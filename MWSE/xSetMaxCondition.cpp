/************************************************************************
	
	xSetMaxCondition.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Armor.h"
#include "TES3Weapon.h"
#include "TES3Lockpick.h"
#include "TES3Probe.h"
#include "TES3RepairTool.h"

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

	static xSetMaxCondition xSetMaxConditionInstance;

	xSetMaxCondition::xSetMaxCondition() : mwse::InstructionInterface_t(OpCode::xSetMaxCondition) {}

	void xSetMaxCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetMaxCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter from the stack.
		long maxCondition = mwse::Stack::getInstance().popLong();
		bool success = false;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetMaxCondition: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get the base object.
		TES3::BaseObject* object = reference->baseObject;
		if (object == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetMaxCondition: No object found for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the max condition based on object type.
		if (object->objectType == TES3::ObjectType::Armor) {
			reinterpret_cast<TES3::Armor*>(object)->maxCondition = maxCondition;
		}
		else if (object->objectType == TES3::ObjectType::Weapon) {
			reinterpret_cast<TES3::Weapon*>(object)->maxCondition = maxCondition;
		}
		else if (object->objectType == TES3::ObjectType::Lockpick) {
			reinterpret_cast<TES3::Lockpick*>(object)->maxCondition = maxCondition;
		}
		else if (object->objectType == TES3::ObjectType::Probe) {
			reinterpret_cast<TES3::Probe*>(object)->maxCondition = maxCondition;
		}
		else if (object->objectType == TES3::ObjectType::Repair) {
			reinterpret_cast<TES3::RepairTool*>(object)->maxCondition = maxCondition;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetMaxCondition: Invalid object type: " << object->objectType << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(success);
			return 0.0f;
		}

		// If there's a variable node containing condition, and we need to change it, do so.
		auto varNode = reference->getAttachedItemData();
		if (varNode && varNode->condition > maxCondition) {
			varNode->condition = maxCondition;
			success = true;
		}

		// Push success state.
		mwse::Stack::getInstance().pushLong(success);

		return 0.0f;
	}
}