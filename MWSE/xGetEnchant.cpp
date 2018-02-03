/************************************************************************
	
	xGetEnchant.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetEnchant : mwse::InstructionInterface_t
	{
	public:
		xGetEnchant();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetEnchant xGetEnchantInstance;

	xGetEnchant::xGetEnchant() : mwse::InstructionInterface_t(OpCode::xGetEnchant) {}

	void xGetEnchant::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEnchant::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Return values.
		mwString_t enchId = NULL;
		mwLong_t type = 0;
		mwLong_t cost = 0;
		mwFloat_t currCharge = 0.0f;
		mwLong_t maxCharge = 0;
		mwLong_t effects = 0;
		mwLong_t autocalc = 0;

		// Get reference to what we're finding enchantment information for.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference) {
			ENCHRecord_t* enchantment = NULL;

			// Get ENCH record by type.
			RecordTypes::recordType_t recordType = reference->recordPointer->recordType;
			if (recordType == RecordTypes::ARMOR) {
				ARMORecord_t* armor = reinterpret_cast<ARMORecord_t*>(reference->recordPointer);
				enchantment = armor->enchantment;
			}
			else if (recordType == RecordTypes::WEAPON) {
				WEAPRecord_t* weapon = reinterpret_cast<WEAPRecord_t*>(reference->recordPointer);
				enchantment = weapon->enchantment;
			}
			else if (recordType == RecordTypes::CLOTHING) {
				CLOTRecord_t* clothing = reinterpret_cast<CLOTRecord_t*>(reference->recordPointer);
				enchantment = clothing->enchantment;
			}
			else if (recordType == RecordTypes::BOOK) {
				BOOKRecord_t* book = reinterpret_cast<BOOKRecord_t*>(reference->recordPointer);
				enchantment = book->enchantment;
			}
			else if (recordType == RecordTypes::AMMO) {
				AMMORecord_t* ammo = reinterpret_cast<AMMORecord_t*>(reference->recordPointer);
				enchantment = ammo->enchantment;
			}
			else {
#if _DEBUG
				log::getLog() << "xGetEnchant: Could not find enchant record of record type: " << recordType << std::endl;
#endif
			}

			// Get data from ENCH record.
			if (enchantment) {
				enchId = enchantment->id;
				type = enchantment->type;
				cost = enchantment->cost;
				maxCharge = enchantment->charge;
				effects = tes3::getEffectCount(enchantment->effects);
				autocalc = enchantment->autocalc;

				// Get the current charge.
				mwVarHolderNode_t* varNode = tes3::getAttachedVarHolderNode(reference);
				if (varNode) {
					currCharge = *reinterpret_cast<mwFloat_t*>(&varNode->unknown_0x10);
				}
				else {
					currCharge = maxCharge;
				}
			}
		}
		else {
#if _DEBUG
			log::getLog() << "xGetEnchant: No reference found for function." << std::endl;
#endif
		}

		// Push results to the stack.
		Stack::getInstance().pushLong(autocalc);
		Stack::getInstance().pushLong(effects);
		Stack::getInstance().pushLong(maxCharge);
		Stack::getInstance().pushFloat(currCharge);
		Stack::getInstance().pushLong(cost);
		Stack::getInstance().pushLong(type);
		Stack::getInstance().pushString(enchId);

		return 0.0f;
	}
}