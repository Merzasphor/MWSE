/************************************************************************
	
	xGetMaxCharge.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetMaxCharge : mwse::InstructionInterface_t
	{
	public:
		xGetMaxCharge();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat_t INVALID_VALUE = -1.0f;
	};

	static xGetMaxCharge xGetMaxChargeInstance;

	xGetMaxCharge::xGetMaxCharge() : mwse::InstructionInterface_t(OpCode::xGetMaxCharge) {}

	void xGetMaxCharge::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMaxCharge::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		float charge = 0.0f;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCharge: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get the base record.
		TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCharge: No record found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get  the maximum charge from the enchantment record.
		RecordTypes::recordType_t type = reference->recordPointer->recordType;
		if (type == RecordTypes::ARMOR) {
			ARMORecord_t* armor = reinterpret_cast<ARMORecord_t*>(record);
			if (armor->enchantment) {
				charge = armor->enchantment->charge;
			}
		}
		else if (type == RecordTypes::CLOTHING) {
			CLOTRecord_t* clothing = reinterpret_cast<CLOTRecord_t*>(record);
			if (clothing->enchantment) {
				charge = clothing->enchantment->charge;
			}
		}
		else if (type == RecordTypes::WEAPON) {
			WEAPRecord_t* weapon = reinterpret_cast<WEAPRecord_t*>(record);
			if (weapon->enchantment) {
				charge = weapon->enchantment->charge;
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCharge: Invalid call on record of type " << type << "." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushFloat(charge);

		return 0.0f;
	}
}