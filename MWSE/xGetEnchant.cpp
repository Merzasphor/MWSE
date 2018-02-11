/************************************************************************
	
	xGetEnchant.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

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

#include "TES3Armor.h"
#include "TES3Weapon.h"
#include "TES3Clothing.h"
#include "TES3Book.h"

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
		mwString enchId = NULL;
		mwLong type = 0;
		mwLong cost = 0;
		mwFloat currCharge = 0.0f;
		mwLong maxCharge = 0;
		mwLong effects = 0;
		mwLong autocalc = 0;

		// Get reference to what we're finding enchantment information for.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference) {
			TES3::Enchantment* enchantment = NULL;

			// Get ENCH record by type.
			TES3::ObjectType::ObjectType recordType = reference->objectPointer->objectType;
			if (recordType == TES3::ObjectType::Armor) {
				TES3::Armor* armor = reinterpret_cast<TES3::Armor*>(reference->objectPointer);
				enchantment = armor->enchantment;
			}
			else if (recordType == TES3::ObjectType::Weapon) {
				TES3::Weapon* weapon = reinterpret_cast<TES3::Weapon*>(reference->objectPointer);
				enchantment = weapon->enchantment;
			}
			else if (recordType == TES3::ObjectType::Clothing) {
				TES3::Clothing* clothing = reinterpret_cast<TES3::Clothing*>(reference->objectPointer);
				enchantment = clothing->enchantment;
			}
			else if (recordType == TES3::ObjectType::Book) {
				TES3::Book* book = reinterpret_cast<TES3::Book*>(reference->objectPointer);
				enchantment = book->enchantment;
			}
			else if (recordType == TES3::ObjectType::Ammo) {
				TES3::Ammo* ammo = reinterpret_cast<TES3::Ammo*>(reference->objectPointer);
				enchantment = ammo->enchantment;
			}
			else {
#if _DEBUG
				log::getLog() << "xGetEnchant: Could not find enchant record of record type: " << recordType << std::endl;
#endif
			}

			// Get data from ENCH record.
			if (enchantment) {
				enchId = enchantment->objectID;
				type = enchantment->type;
				cost = enchantment->cost;
				maxCharge = enchantment->charge;
				effects = tes3::getEffectCount(enchantment->effects);
				//autocalc = enchantment->autocalc; // TODO: This field didn't seem valid. Find it.

				// Get the current charge.
				auto varNode = tes3::getAttachedVariableNode(reference);
				if (varNode) {
					currCharge = varNode->currentCharge;
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