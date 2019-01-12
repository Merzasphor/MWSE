/************************************************************************
	
	xSetCondition.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse
{
	class xSetCondition : mwse::InstructionInterface_t
	{
	public:
		xSetCondition();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetCondition xSetConditionInstance;

	xSetCondition::xSetCondition() : mwse::InstructionInterface_t(OpCode::xSetCondition) {}

	void xSetCondition::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetCondition::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		long value = Stack::getInstance().popLong();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			log::getLog() << "xSetCondition: No reference provided." << std::endl;
#endif
			Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		// Get associated varnode, and the condition from it.
		auto varNode = reference->getAttachedItemData();
		if (varNode != NULL) {
			varNode->condition = value;
		}
		else {
#if _DEBUG
			log::getLog() << "xSetCondition: Could not get attached VARNODE." << std::endl;
#endif
			Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		Stack::getInstance().pushShort(1);

		return 0.0f;
	}
}