/************************************************************************

	xGetClass.cpp - Copyright (c) 2008 The MWSE Project
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

	static const mwse::mwOpcode_t xGetClassOpcode = 0x392B;
	static xGetClass xGetClassInstance;

	xGetClass::xGetClass() : mwse::InstructionInterface_t(xGetClassOpcode) {}

	void xGetClass::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetClass::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetClass: No reference provided." << std::endl;
			return 0.0f;
		}

		// Get the base record.
		NPCCopyRecord_t* record = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer);
		if (record == NULL) {
			mwse::log::getLog() << "xGetClass: No record found for reference." << std::endl;
			return 0.0f;
		}
		else if (record->recordType != RecordTypes::NPC) {
			mwse::log::getLog() << "xGetClass: Called on a non-NPC reference." << std::endl;
			return 0.0f;
		}
		else if (record->baseNPC == NULL) {
			mwse::log::getLog() << "xGetClass: NPC record lacks a base NPC." << std::endl;
			return 0.0f;
		}

		// Get argument: 
		mwLong_t attributesMask = mwse::Stack::getInstance().popLong();
		mwLong_t majorMask = mwse::Stack::getInstance().popLong();
		mwLong_t minorMask = mwse::Stack::getInstance().popLong();

		// Get the class record.
		CLASRecord_t* classRecord = record->baseNPC->classRecord;

		// Get basic class details.
		mwseString_t id(classRecord->id);
		mwseString_t name(classRecord->name);
		mwLong_t playable = classRecord->playable;
		mwLong_t specialization = classRecord->specialization;

		// Get class attributes.
		mwLong_t attributes = (1 << classRecord->attributes[0]) + (1 << classRecord->attributes[1]);
		if (attributesMask != 0) {
			attributes &= attributesMask;
		}

		// Get class minor/major skills.
		mwLong_t minorSkills = 0;
		mwLong_t majorSkills = 0;
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
		mwse::Stack::getInstance().pushLong(name);
		mwse::Stack::getInstance().pushLong(id);

		return 0.0f;
	}
}