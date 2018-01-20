/************************************************************************
	
	xGetRace.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

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

using namespace mwse;

namespace mwse
{
	class xGetRace : mwse::InstructionInterface_t
	{
	public:
		xGetRace();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetRace xGetRaceInstance;

	xGetRace::xGetRace() : mwse::InstructionInterface_t(OpCode::xGetRace) {}

	void xGetRace::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetRace::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetRace: No reference provided." << std::endl;
			return 0.0f;
		}

		// Get the base record.
		NPCCopyRecord_t* record = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (record == NULL) {
			mwse::log::getLog() << "xGetRace: No record found for reference." << std::endl;
			return 0.0f;
		}
		else if (record->recordType != RecordTypes::NPC) {
			mwse::log::getLog() << "xGetRace: Called on a non-NPC reference." << std::endl;
			return 0.0f;
		}
		else if (record->baseNPC == NULL) {
			mwse::log::getLog() << "xGetRace: NPC record lacks a base NPC." << std::endl;
			return 0.0f;
		}

		// Get the NPC's race.
		RACERecord_t* race = record->baseNPC->raceRecord;

		// Get argument: return variable type.
		mwShort_t returnTypeParam = mwse::Stack::getInstance().popShort();

		// Simple case. Just push the race name.
		if (returnTypeParam == 0) {
			mwse::Stack::getInstance().pushString(race->name);
			return 0.0f;
		}
		else if (returnTypeParam == 1) {
			mwLong_t arrayId = mwse::Arrays::getInstance().create("xGetRace");
			if (arrayId != 0) {
				// Create array for skills.
				mwLong_t skillArrayId = mwse::Arrays::getInstance().create("xGetRace");
				if (skillArrayId != 0) {
					ContainedArray_t& skillArray = mwse::Arrays::getInstance().get(skillArrayId);
					skillArray.push_back(7);
					for (size_t i = 0; i < 7; i++) {
						if (race->skill_bonuses[i].skill != NoSkill) {
							skillArray.push_back(race->skill_bonuses[i].skill);
							skillArray.push_back(race->skill_bonuses[i].bonus);
						}
						else {
							skillArray[0] = i;
						}
					}
				}

				// Create array for attributes.
				mwLong_t attributeArrayId = mwse::Arrays::getInstance().create("xGetRace");
				if (attributeArrayId != 0) {
					ContainedArray_t& attributeArray = mwse::Arrays::getInstance().get(attributeArrayId);
					for (size_t i = 0; i < 8; i++) {
						attributeArray.push_back(race->base_attributes[i].male);
						attributeArray.push_back(race->base_attributes[i].female);
					}
				}

				// Push the above arrays and other values to the result array.
				ContainedArray_t& returnArray = mwse::Arrays::getInstance().get(arrayId);
				returnArray.push_back(mwse::string::store::getOrCreate(race->id));
				returnArray.push_back(mwse::string::store::getOrCreate(race->name));
				returnArray.push_back(skillArrayId);
				returnArray.push_back(attributeArrayId);
				returnArray.push_back(*reinterpret_cast<mwLong_t*>(&race->height.male));
				returnArray.push_back(*reinterpret_cast<mwLong_t*>(&race->height.female));
				returnArray.push_back(*reinterpret_cast<mwLong_t*>(&race->weight.male));
				returnArray.push_back(*reinterpret_cast<mwLong_t*>(&race->weight.female));
				returnArray.push_back(race->flags & 1);
				returnArray.push_back(race->flags >> 1);

				// Push array result
				mwse::Stack::getInstance().pushLong(arrayId);
				return 0.0f;
			}
		}
		else {

		}
		
		// 
		mwse::Stack::getInstance().pushLong(false);
		return 0.0f;
	}
}