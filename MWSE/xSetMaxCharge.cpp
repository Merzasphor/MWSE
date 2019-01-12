/************************************************************************
	
	xSetMaxCharge.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetMaxCharge : mwse::InstructionInterface_t
	{
	public:
		xSetMaxCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetMaxCharge xSetMaxChargeInstance;

	xSetMaxCharge::xSetMaxCharge() : mwse::InstructionInterface_t(OpCode::xSetMaxCharge) {}

	void xSetMaxCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetMaxCharge::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter from the stack.
		float maxCharge = mwse::Stack::getInstance().popFloat();
		bool success = false;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetMaxCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get the base record.
		TES3::BaseObject* object = reference->baseObject;
		if (object == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetMaxCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// If we found an enchantment record, set the max charge.
		TES3::Enchantment* enchantment = object->vTable.object->getEnchantment(object);
		if (enchantment) {
			enchantment->maxCharge = maxCharge;

			// If there's charge data in an attached node, update it.
			auto varNode = reference->getAttachedItemData();
			if (varNode) {
				if (varNode->charge >= maxCharge) {
					varNode->charge = maxCharge;
				}
			}

			success = true;
		}

		// Push success state.
		mwse::Stack::getInstance().pushLong(success);

		return 0.0f;
	}
}