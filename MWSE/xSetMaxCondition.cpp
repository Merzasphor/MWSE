/************************************************************************
	
	xSetMaxCondition.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetMaxCondition : mwse::InstructionInterface_t
	{
	public:
		xSetMaxCondition();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetMaxConditionOpcode = 0x3E65;
	static xSetMaxCondition xSetMaxConditionInstance;

	xSetMaxCondition::xSetMaxCondition() : mwse::InstructionInterface_t(xSetMaxConditionOpcode) {}

	void xSetMaxCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetMaxCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter from the stack.
		mwLong_t maxCondition = mwse::Stack::getInstance().popLong();
		bool success = false;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xSetMaxCondition: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get the base record.
		TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (record == NULL) {
			mwse::log::getLog() << "xSetMaxCondition: No record found for reference." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the max condition based on record type.
		if (record->recordType == RecordTypes::ARMOR) {
			reinterpret_cast<ARMORecord_t*>(record)->maxCondition = maxCondition;
		}
		else if (record->recordType == RecordTypes::WEAPON) {
			reinterpret_cast<WEAPRecord_t*>(record)->maxCondition = maxCondition;
		}
		else if (record->recordType == RecordTypes::LOCK) {
			reinterpret_cast<LOCKRecord_t*>(record)->maxCondition = maxCondition;
		}
		else if (record->recordType == RecordTypes::PROBE) {
			reinterpret_cast<PROBRecord_t*>(record)->maxCondition = maxCondition;
		}
		else if (record->recordType == RecordTypes::REPAIR) {
			reinterpret_cast<REPARecord_t*>(record)->maxCondition = maxCondition;
		}
		else {
			mwse::log::getLog() << "xSetMaxCondition: Invalid record type: " << record->recordType << std::endl;
			mwse::Stack::getInstance().pushLong(success);
			return 0.0f;
		}

		// If there's a variable node containing condition, and we need to change it, do so.
		mwVarHolderNode_t* varNode = tes3::getAttachedVarHolderNode(reference);
		if (varNode && varNode->unknown_0x0C > maxCondition) {
			varNode->unknown_0x0C = maxCondition;
			success = true;
		}

		// Push success state.
		mwse::Stack::getInstance().pushLong(success);

		return 0.0f;
	}
}