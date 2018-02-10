/************************************************************************

	xGetClass.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MACP.h"
#include "TES3NPC.h"

using namespace mwse;

namespace mwse
{
	class xGetClass : mwse::InstructionInterface_t
	{
	public:
		xGetClass();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetClass xGetClassInstance;

	xGetClass::xGetClass() : mwse::InstructionInterface_t(OpCode::xGetClass) {}

	void xGetClass::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetClass::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetClass: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the base record.
		TES3::NPCInstance* record = reinterpret_cast<TES3::NPCInstance*>(reference->objectPointer);
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetClass: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}
		else if (record->objectType != TES3::ObjectType::NPC) {
#if _DEBUG
			mwse::log::getLog() << "xGetClass: Called on a non-NPC reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}
		else if (record->baseNPC == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetClass: NPC record lacks a base NPC." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get argument: 
		mwLong attributesMask = mwse::Stack::getInstance().popLong();
		mwLong majorMask = mwse::Stack::getInstance().popLong();
		mwLong minorMask = mwse::Stack::getInstance().popLong();

		// Get the class record.
		TES3::Class* classRecord = record->baseNPC->classRecord;

		// Get basic class details.
		mwString id = classRecord->id;
		mwString name = classRecord->name;
		mwLong playable = classRecord->playable;
		mwLong specialization = classRecord->specialization;

		// Get class attributes.
		mwLong attributes = (1 << classRecord->attributes[0]) + (1 << classRecord->attributes[1]);
		if (attributesMask != 0) {
			attributes &= attributesMask;
		}

		// Get class minor/major skills.
		mwLong minorSkills = 0;
		mwLong majorSkills = 0;
		for (int i = 0; i < 10; i += 2) {
			minorSkills += 1 << classRecord->skills[i];
			majorSkills += 1 << classRecord->skills[i + 1];
		}
		if (minorMask != 0) {
			minorSkills &= minorMask;
		}
		if (majorMask != 0) {
			majorSkills &= majorMask;
		}

		// Push results
		mwse::Stack::getInstance().pushLong(minorSkills);
		mwse::Stack::getInstance().pushLong(majorSkills);
		mwse::Stack::getInstance().pushLong(attributes);
		mwse::Stack::getInstance().pushLong(specialization);
		mwse::Stack::getInstance().pushLong(playable);
		mwse::Stack::getInstance().pushString(name);
		mwse::Stack::getInstance().pushString(id);

		return 0.0f;
	}
}