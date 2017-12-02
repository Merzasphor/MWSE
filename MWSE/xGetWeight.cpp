/************************************************************************
	
	xGetWeight.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetWeight : mwse::InstructionInterface_t {
	public:
		xGetWeight();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetWeightOpcode = 0x3F63;
	static xGetWeight xGetWeightInstance;

	xGetWeight::xGetWeight() : mwse::InstructionInterface_t(xGetWeightOpcode) {}

	void xGetWeight::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetWeight::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetWeight: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get record.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
			mwse::log::getLog() << "xGetWeight: No base record found." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		mwFloat_t weight = 0.0f;

		// Get the weight from the base record. We group records here by the same offset.
		bool foundValue = true;
		RecordTypes::recordType_t recordType = record->recordType;
		switch (recordType) {
		case RecordTypes::MISC:
		case RecordTypes::BOOK:
		case RecordTypes::ALCHEMY:
		case RecordTypes::AMMO:
		case RecordTypes::WEAPON:
			weight = reinterpret_cast<BOOKRecord_t*>(record)->weight;
			break;
		case RecordTypes::LIGHT:
			weight = reinterpret_cast<LIGHRecord_t*>(record)->weight;
			break;
		case RecordTypes::INGREDIENT:
		case RecordTypes::LOCK:
		case RecordTypes::PROBE:
		case RecordTypes::REPAIR:
			weight = reinterpret_cast<LOCKRecord_t*>(record)->weight;
			break;
		case RecordTypes::ARMOR:
			weight = reinterpret_cast<ARMORecord_t*>(record)->weight;
			break;
		case RecordTypes::CLOTHING:
			// Clothing has the same offset as armor, but it's a short rather than a long.
			weight = reinterpret_cast<CLOTRecord_t*>(record)->weight;
			break;
		case RecordTypes::APPARATUS:
			weight = reinterpret_cast<APPARecord_t*>(record)->weight;
			break;
		case RecordTypes::CONTAINER:
			weight = reinterpret_cast<CONTRecord_t*>(record)->weight;
			break;
		default:
			mwse::log::getLog() << "xGetWeight: Call on invalid record type." << std::endl;
			foundValue = false;
			break;
		}

		// Multiply the value by the count of the item.
		if (foundValue) {
			mwVarHolderNode_t* varHolder = tes3::getAttachedVarHolderNode(reference);
			if (varHolder) {
				weight *= varHolder->unknown_0x00;
			}
		}

		DebugRecord_t* debug = reinterpret_cast<DebugRecord_t*>(record);
		mwse::Stack::getInstance().pushFloat(weight);

		return 0.0f;
	}
}