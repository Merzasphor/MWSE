/************************************************************************
	
	xSetValue.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetValue : mwse::InstructionInterface_t {
	public:
		xSetValue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetValue xSetValueInstance;

	xSetValue::xSetValue() : mwse::InstructionInterface_t(OpCode::xSetValue) {}

	void xSetValue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetValue::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameter.
		mwLong_t value = mwse::Stack::getInstance().popLong();
		bool setValue = false;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetValue: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get record.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetValue: No base record found." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the value from the base record. We group records here by the same offset.
		RecordTypes::recordType_t recordType = record->recordType;
		switch (recordType) {
		case RecordTypes::BOOK:
		case RecordTypes::ALCHEMY:
		case RecordTypes::AMMO:
		case RecordTypes::WEAPON:
			reinterpret_cast<BOOKRecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::LIGHT:
			reinterpret_cast<LIGHRecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::INGREDIENT:
		case RecordTypes::LOCK:
		case RecordTypes::PROBE:
		case RecordTypes::REPAIR:
			reinterpret_cast<LOCKRecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::ARMOR:
			reinterpret_cast<ARMORecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::CLOTHING:
			// Clothing has the same offset as armor, but it's a short rather than a long.
			reinterpret_cast<CLOTRecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::APPARATUS:
			reinterpret_cast<APPARecord_t*>(record)->value = value;
			setValue = true;
			break;
		case RecordTypes::MISC:
		{
			reinterpret_cast<MISCRecord_t*>(record)->value = value;
			setValue = true;
			break;
		}
		default:
#if _DEBUG
			mwse::log::getLog() << "xSetValue: Call on invalid record type." << std::endl;
#endif
			break;
		}

		mwse::Stack::getInstance().pushLong(setValue);

		return 0.0f;
	}
}