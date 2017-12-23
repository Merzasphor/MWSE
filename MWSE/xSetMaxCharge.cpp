/************************************************************************
	
	xSetMaxCharge.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetMaxCharge : mwse::InstructionInterface_t
	{
	public:
		xSetMaxCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xSetMaxChargeOpcode = 0x3E67;
	static xSetMaxCharge xSetMaxChargeInstance;

	xSetMaxCharge::xSetMaxCharge() : mwse::InstructionInterface_t(xSetMaxChargeOpcode) {}

	void xSetMaxCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetMaxCharge::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter from the stack.
		mwFloat_t maxCharge = mwse::Stack::getInstance().popFloat();

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xSetMaxCharge: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get the base record.
		TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (record == NULL) {
			mwse::log::getLog() << "xSetMaxCharge: No record found for reference." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// If there's charge data in an attached node, update it.
		mwVarHolderNode_t* varNode = tes3::getAttachedVarHolderNode(reference);
		if (varNode) {
			mwFloat_t& charge = *reinterpret_cast<mwFloat_t*>(&varNode->unknown_0x10);
			if (charge >= maxCharge) {
				charge = maxCharge;
			}
		}

		// Get enchantment record based on record type.
		ENCHRecord_t* enchantment = NULL;
		if (record->recordType == RecordTypes::ARMOR) {
			enchantment = reinterpret_cast<ARMORecord_t*>(record)->enchantment;
		}
		else if (record->recordType == RecordTypes::CLOTHING) {
			enchantment = reinterpret_cast<CLOTRecord_t*>(record)->enchantment;
		}
		else if (record->recordType == RecordTypes::WEAPON) {
			enchantment = reinterpret_cast<WEAPRecord_t*>(record)->enchantment;
		}

		// If we found an enchantment record, set the max charge.
		if (enchantment) {
			enchantment->charge = maxCharge;
		}

		// Return the enchantment record, if it's autocalced.
		if (enchantment && (enchantment->autocalc & 0xFF) != 0) {
			mwse::Stack::getInstance().pushLong((mwLong_t)enchantment);
		}
		else {
			mwse::Stack::getInstance().pushLong(NULL);
		}

		return 0.0f;
	}
}