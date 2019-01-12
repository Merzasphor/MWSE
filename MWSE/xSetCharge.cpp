/************************************************************************
	
	xSetCharge.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse {
	class xSetCharge : mwse::InstructionInterface_t {
	public:
		xSetCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetCharge xSetChargeInstance;

	xSetCharge::xSetCharge() : mwse::InstructionInterface_t(OpCode::xSetCharge) {}

	void xSetCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetCharge::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get charge from parameter.
		float charge = Stack::getInstance().popFloat();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get the base record.
		TES3::BaseObject* record = reference->baseObject;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get the charge based on the record type. If the item doesn't have a varnode,
		// return the maximum charge from the enchantment record.
		auto varNode = reference->getAttachedItemData();
		if (varNode) {
			varNode->charge = charge;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetCharge: Could not get attached VARNODE." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushShort(1);

		return 0.0f;
	}
}