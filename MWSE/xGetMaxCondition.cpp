/************************************************************************
	
	xGetMaxCondition.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse
{
	class xGetMaxCondition : mwse::InstructionInterface_t
	{
	public:
		xGetMaxCondition();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetMaxCondition xGetMaxConditionInstance;

	xGetMaxCondition::xGetMaxCondition() : mwse::InstructionInterface_t(OpCode::xGetMaxCondition) {}

	void xGetMaxCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMaxCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCondition: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwLong value = 0;

		// Get the max condition.
		TES3::ObjectType::ObjectType recordType = reference->objectPointer->objectType;
		if (recordType == TES3::ObjectType::Lockpick) {
			TES3::Lockpick* lockpick = reinterpret_cast<TES3::Lockpick*>(reference->objectPointer);
			value = lockpick->maxCondition;
		}
		else if (recordType == TES3::ObjectType::Probe) {
			TES3::Probe* probe = reinterpret_cast<TES3::Probe*>(reference->objectPointer);
			value = probe->maxCondition;
		}
		else if (recordType == TES3::ObjectType::Armor) {
			TES3::Armor* armor = reinterpret_cast<TES3::Armor*>(reference->objectPointer);
			value = armor->maxCondition;
		}
		else if (recordType == TES3::ObjectType::Repair) {
			TES3::Repair* repair = reinterpret_cast<TES3::Repair*>(reference->objectPointer);
			value = repair->maxCondition;
		}
		else if (recordType == TES3::ObjectType::Weapon) {
			TES3::Weapon* weapon = reinterpret_cast<TES3::Weapon*>(reference->objectPointer);
			value = weapon->maxCondition;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetMaxCondition: Could not fall back to max condition of given type, " << recordType << "." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(value);

		return 0.0f;
	}
}