/************************************************************************
	
	xGetValue.cpp - Copyright (c) 2008 The MWSE Project
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
#include "Reference.h"

using namespace mwse;

namespace mwse {
	class xGetValue : mwse::InstructionInterface_t {
	public:
		xGetValue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetValueOpcode = 0x3F61;
	static xGetValue xGetValueInstance;

	xGetValue::xGetValue() : mwse::InstructionInterface_t(xGetValueOpcode) {}

	void xGetValue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetValue::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetValue: No reference provided." << std::endl;
			// TODO: Fix stack.
			return 0.0f;
		}

		// Get record.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
			mwse::log::getLog() << "xGetValue: No base record found." << std::endl;
			// TODO: Fix stack.
			return 0.0f;
		}

		mwLong_t value = 0;

		// Get the value from the base record. We group records here by the same offset.
		bool foundValue = true;
		RecordTypes::recordType_t recordType = record->recordType;
		switch (recordType) {
		case RecordTypes::BOOK:
		case RecordTypes::ALCHEMY:
		case RecordTypes::AMMO:
		case RecordTypes::WEAPON:
			value = reinterpret_cast<BOOKRecord_t*>(record)->value;
			break;
		case RecordTypes::LIGHT:
			value = reinterpret_cast<LIGHRecord_t*>(record)->value;
			break;
		case RecordTypes::INGREDIENT:
		case RecordTypes::LOCK:
		case RecordTypes::PROBE:
		case RecordTypes::REPAIR:
			value = reinterpret_cast<LOCKRecord_t*>(record)->value;
			break;
		case RecordTypes::ARMOR:
			value = reinterpret_cast<ARMORecord_t*>(record)->value;
			break;
		case RecordTypes::CLOTHING:
			// Clothing has the same offset as armor, but it's a short rather than a long.
			value = reinterpret_cast<CLOTRecord_t*>(record)->value;
			break;
		case RecordTypes::APPARATUS:
			value = reinterpret_cast<APPARecord_t*>(record)->value;
			break;
		case RecordTypes::MISC:
		{
			// Misc is a unique case. We need to make gold always be worth 1.
			MISCRecord_t* misc = reinterpret_cast<MISCRecord_t*>(record);
			value = misc->value;
			if (!strncmp(misc->id, "Gold_", 5)) {
				value = 1;
			}
			break;
		}
		default:
			mwse::log::getLog() << "xGetValue: Call on invalid record type." << std::endl;
			foundValue = false;
			break;
		}

		// Multiply the value by the count of the item.
		if (foundValue) {
			mwVarHolderNode_t* varHolder = tes3::getAttachedVarHolderNode(reference);
			if (varHolder) {
				value *= varHolder->unknown_0x00;
			}
		}

		DebugRecord_t* debug = reinterpret_cast<DebugRecord_t*>(record);
		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}