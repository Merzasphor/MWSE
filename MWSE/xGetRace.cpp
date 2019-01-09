/************************************************************************
	
	xGetRace.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "ArrayUtil.h"

#include "TES3MobileNPC.h"
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3Race.h"
#include "TES3Skill.h"

using namespace mwse;

namespace mwse
{
	class xGetRace : mwse::InstructionInterface_t
	{
	public:
		xGetRace();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		std::map<long, long> arrayMap;
	};

	static xGetRace xGetRaceInstance;

	xGetRace::xGetRace() : mwse::InstructionInterface_t(OpCode::xGetRace) {}

	void xGetRace::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetRace::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetRace: No reference provided." << std::endl;
#endif
			return 0.0f;
		}

		// Get the base record.
		TES3::NPCInstance* object = reinterpret_cast<TES3::NPCInstance*>(reference->baseObject);
		if (object == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetRace: No record found for reference." << std::endl;
#endif
			return 0.0f;
		}
		else if (object->objectType != TES3::ObjectType::NPC) {
#if _DEBUG
			mwse::log::getLog() << "xGetRace: Called on a non-NPC reference." << std::endl;
#endif
			return 0.0f;
		}

		// Get the NPC's race.
		TES3::Race* race = object->vTable.object->getRace(object);

		// Get argument: return variable type.
		short returnTypeParam = mwse::Stack::getInstance().popShort();

		// Simple case. Just push the race name.
		if (returnTypeParam == 0) {
			mwse::Stack::getInstance().pushString(race->name);
			return 0.0f;
		}

		// Complex case, push array(s).
		else if (returnTypeParam == 1) {
			// Get the array index to use from storage, or create it.
			long mainArrayId = 0;
			long skillArrayId = 0;
			long attributeArrayId = 0;
			auto foundArrayId = arrayMap.find((long)race);
			if (foundArrayId != arrayMap.end()) {
				// Array found. Clear the arrays for reuse.
				mainArrayId = foundArrayId->second;
				mwse::Arrays::getInstance().clear("xGetRace", mainArrayId);
				skillArrayId = mainArrayId + 1;
				mwse::Arrays::getInstance().clear("xGetRace", skillArrayId);
				attributeArrayId = mainArrayId + 1;
				mwse::Arrays::getInstance().clear("xGetRace", attributeArrayId);
			}
			else {
				// Arrays not found. Create them.
				mainArrayId = mwse::Arrays::getInstance().create("xGetRace");
				skillArrayId = mwse::Arrays::getInstance().create("xGetRace");
				attributeArrayId = mwse::Arrays::getInstance().create("xGetRace");
				arrayMap[(long)race] = mainArrayId;
			}

			if (mainArrayId != 0) {
				// Create array for skills.
				if (skillArrayId != 0) {
					ContainedArray_t& skillArray = mwse::Arrays::getInstance().get(skillArrayId);
					skillArray.push_back(7);
					for (size_t i = 0; i < 7; i++) {
						if (race->skillBonuses[i].skill != TES3::SkillID::Invalid) {
							skillArray.push_back(race->skillBonuses[i].skill);
							skillArray.push_back(race->skillBonuses[i].bonus);
						}
						else {
							skillArray[0] = i;
						}
					}
				}

				// Create array for attributes.
				if (attributeArrayId != 0) {
					ContainedArray_t& attributeArray = mwse::Arrays::getInstance().get(attributeArrayId);
					for (size_t i = 0; i < 8; i++) {
						attributeArray.push_back(race->baseAttributes[i].male);
						attributeArray.push_back(race->baseAttributes[i].female);
					}
				}

				// Push the above arrays and other values to the result array.
				ContainedArray_t& returnArray = mwse::Arrays::getInstance().get(mainArrayId);
				returnArray.push_back(mwse::string::store::getOrCreate(race->id));
				returnArray.push_back(mwse::string::store::getOrCreate(race->name));
				returnArray.push_back(skillArrayId);
				returnArray.push_back(attributeArrayId);
				returnArray.push_back(*reinterpret_cast<long*>(&race->height.male));
				returnArray.push_back(*reinterpret_cast<long*>(&race->height.female));
				returnArray.push_back(*reinterpret_cast<long*>(&race->weight.male));
				returnArray.push_back(*reinterpret_cast<long*>(&race->weight.female));
				returnArray.push_back(race->flags & 1);
				returnArray.push_back(race->flags >> 1);

				// Push array result
				mwse::Stack::getInstance().pushLong(mainArrayId);
				return 0.0f;
			}
		}

		// Invalid return type, or something wrong happened.
		mwse::Stack::getInstance().pushLong(false);
		return 0.0f;
	}
}