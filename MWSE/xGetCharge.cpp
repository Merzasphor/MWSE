/************************************************************************
	
	xGetCharge.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3ItemData.h"
#include "TES3Reference.h"
#include "TES3Enchantment.h"

using namespace mwse;

namespace mwse
{
	class xGetCharge : mwse::InstructionInterface_t
	{
	public:
		xGetCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const float INVALID_VALUE = -1.0f;
	};

	static xGetCharge xGetChargeInstance;

	xGetCharge::xGetCharge() : mwse::InstructionInterface_t(OpCode::xGetCharge) {}

	void xGetCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetCharge::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float charge = INVALID_VALUE;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the base record.
		TES3::BaseObject* object = reference->baseObject;
		if (object == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the charge based on the record type. If the item doesn't have a varnode,
		// return the maximum charge from the enchantment record.
		auto varNode = reference->getAttachedItemData();
		if (varNode) {
			charge = varNode->charge;
		}
		else {
			TES3::Enchantment* enchantment = object->vTable.object->getEnchantment(object);
			if (enchantment) {
				charge = enchantment->maxCharge;
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetCharge: Invalid call on record of type " << object->objectType << "." << std::endl;
#endif
			}
		}

		mwse::Stack::getInstance().pushFloat(charge);

		return 0.0f;
	}
}