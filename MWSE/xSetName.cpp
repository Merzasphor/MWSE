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
		if (name.length() > 31) {
#if _DEBUG
			mwse::log::getLog() << "xSetName: Given name length must be 31 characters or less." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(false);
			return 0.0f;
		}

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(false);
			return 0.0f;
		}
		
		// Get the base record.
		TES3DefaultTemplate_t* recordGeneric = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (recordGeneric == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetName: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(false);
			return 0.0f;
		}

		// Get string pointer based on record type.
		char* namePtr = NULL;
		char** nameContainer = NULL;
		RecordTypes::recordType_t recordType = recordGeneric->recordType;
		switch (recordType) {
		case RecordTypes::NPC:
		case RecordTypes::CREATURE:
			nameContainer = &reinterpret_cast<NPCCopyRecord_t*>(recordGeneric)->baseNPC->name;
			namePtr = *nameContainer;
			break;
		case RecordTypes::CONTAINER:
			nameContainer = &reinterpret_cast<CONTRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case RecordTypes::LIGHT:
			nameContainer = &reinterpret_cast<LIGHRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case RecordTypes::ALCHEMY:
		case RecordTypes::AMMO:
		case RecordTypes::ARMOR:
		case RecordTypes::BOOK:
		case RecordTypes::CLOTHING:
		case RecordTypes::MISC:
		case RecordTypes::WEAPON:
			nameContainer = &reinterpret_cast<ARMORecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case RecordTypes::ACTIVATOR:
			nameContainer = &reinterpret_cast<ACTIRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case RecordTypes::DOOR:
			namePtr = reinterpret_cast<DOORRecord_t*>(recordGeneric)->name;
			break;
		case RecordTypes::APPARATUS:
			namePtr = reinterpret_cast<APPARecord_t*>(recordGeneric)->name;
			break;
		case RecordTypes::INGREDIENT:
		case RecordTypes::LOCKPICK:
		case RecordTypes::PROBE:
		case RecordTypes::REPAIR:
			namePtr = reinterpret_cast<LOCKRecord_t*>(recordGeneric)->name;
			break;
		}

		// Bail out if we haven't found the name.
		if (namePtr == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetName: Unsupported record format: " << recordType << "." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(false);
			return 0.0f;
		}

		// Some strings might need to be recreated.
		if (nameContainer != NULL && name.length() > strlen(namePtr)) {
			namePtr = reinterpret_cast<char*>(tes3::realloc(namePtr, name.length() + 1));
			*nameContainer = namePtr;
		}

		strcpy(namePtr, name.c_str());

		mwse::Stack::getInstance().pushShort(true);
		return 0.0f;
	}
}