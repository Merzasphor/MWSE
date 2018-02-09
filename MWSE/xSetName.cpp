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
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(false);
			return 0.0f;
		}
		
		// Get the base record.
		TES3::BaseObject* recordGeneric = reinterpret_cast<TES3::BaseObject*>(reference->objectPointer);
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
		TES3::ObjectType::ObjectType recordType = recordGeneric->objectType;
		switch (recordType) {
		case TES3::ObjectType::NPC:
		case TES3::ObjectType::Creature:
			nameContainer = &reinterpret_cast<TES3::NPCInstance*>(recordGeneric)->baseNPC->name;
			namePtr = *nameContainer;
			break;
		case TES3::ObjectType::CONTAINER:
			nameContainer = &reinterpret_cast<CONTRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case TES3::ObjectType::LIGHT:
			nameContainer = &reinterpret_cast<LIGHRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case TES3::ObjectType::Alchemy:
		case TES3::ObjectType::AMMO:
		case TES3::ObjectType::ARMOR:
		case TES3::ObjectType::BOOK:
		case TES3::ObjectType::CLOTHING:
		case TES3::ObjectType::MISC:
		case TES3::ObjectType::WEAPON:
			nameContainer = &reinterpret_cast<TES3::Armor*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case TES3::ObjectType::ACTIVATOR:
			nameContainer = &reinterpret_cast<ACTIRecord_t*>(recordGeneric)->name;
			namePtr = *nameContainer;
			break;
		case TES3::ObjectType::DOOR:
			namePtr = reinterpret_cast<DOORRecord_t*>(recordGeneric)->name;
			break;
		case TES3::ObjectType::APPARATUS:
			namePtr = reinterpret_cast<APPARecord_t*>(recordGeneric)->name;
			break;
		case TES3::ObjectType::INGREDIENT:
		case TES3::ObjectType::LOCKPICK:
		case TES3::ObjectType::PROBE:
		case TES3::ObjectType::REPAIR:
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