/************************************************************************
	
	xSetName.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetName : mwse::InstructionInterface_t
	{
	public:
		xSetName();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetName xSetNameInstance;

	xSetName::xSetName() : mwse::InstructionInterface_t(OpCode::xSetName) {}

	void xSetName::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetName::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter from the stack.
		mwseString_t& name = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Enforce name length.
		if (name.length() > 128) {
			mwse::log::getLog() << "xSetName: Given name length must be 128 characters or less." << std::endl;
			return 0.0f;
		}

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xSetName: No reference provided." << std::endl;
			return 0.0f;
		}

		// Get the base record.
		TES3DefaultTemplate_t* recordGeneric = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (recordGeneric == NULL) {
			mwse::log::getLog() << "xSetName: No record found for reference." << std::endl;
			return 0.0f;
		}

		// Set name based on record type.
		if (recordGeneric->recordType == RecordTypes::NPC
			|| recordGeneric->recordType == RecordTypes::CREATURE) {
			NPCCopyRecord_t* record = reinterpret_cast<NPCCopyRecord_t*>(recordGeneric);
			strcpy(record->baseNPC->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::CONTAINER) {
			CONTRecord_t* record = reinterpret_cast<CONTRecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::LIGHT) {
			LIGHRecord_t* record = reinterpret_cast<LIGHRecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::ARMOR
			|| recordGeneric->recordType == RecordTypes::CLOTHING
			|| recordGeneric->recordType == RecordTypes::WEAPON
			|| recordGeneric->recordType == RecordTypes::MISC
			|| recordGeneric->recordType == RecordTypes::BOOK
			|| recordGeneric->recordType == RecordTypes::ALCHEMY
			|| recordGeneric->recordType == RecordTypes::AMMO) {
			ARMORecord_t* record = reinterpret_cast<ARMORecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::ACTIVATOR) {
			ACTIRecord_t* record = reinterpret_cast<ACTIRecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::DOOR) {
			DOORRecord_t* record = reinterpret_cast<DOORRecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::APPARATUS) {
			APPARecord_t* record = reinterpret_cast<APPARecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}
		else if (recordGeneric->recordType == RecordTypes::INGREDIENT
			|| recordGeneric->recordType == RecordTypes::REPAIR
			|| recordGeneric->recordType == RecordTypes::PROBE
			|| recordGeneric->recordType == RecordTypes::LOCKPICK) {
			LOCKRecord_t* record = reinterpret_cast<LOCKRecord_t*>(recordGeneric);
			strcpy(record->name, name.c_str());
		}

		return 0.0f;
	}
}