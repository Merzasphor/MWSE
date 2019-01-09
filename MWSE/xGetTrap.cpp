/************************************************************************
	
	xGetTrap.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Reference.h"
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xGetTrap : mwse::InstructionInterface_t
	{
	public:
		xGetTrap();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetTrap xGetTrapInstance;

	xGetTrap::xGetTrap() : mwse::InstructionInterface_t(OpCode::xGetTrap) {}

	void xGetTrap::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetTrap::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		char* id = NULL;
		char* name = NULL;
		short cost = 0;

		// Get reference to what we're finding the trap of.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetTrap: Called on invalid reference." << std::endl;
#endif
			Stack::getInstance().pushShort(cost);
			Stack::getInstance().pushString(name);
			Stack::getInstance().pushString(id);
			return 0.0f;
		}

		TES3::ObjectType::ObjectType type = reference->baseObject->objectType;
		if (type == TES3::ObjectType::Container || type == TES3::ObjectType::Door) {
			auto lockNode = reference->getAttachedLockNode();
			if (lockNode) {
				TES3::Spell* trapSpell = lockNode->trap;
				if (trapSpell) {
					id = trapSpell->objectID;
					name = trapSpell->name;
					cost = trapSpell->magickaCost;
				}
			}
			else {
#if _DEBUG
				log::getLog() << "xGetTrap: Could not obtain lock node." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			log::getLog() << "xGetTrap: Called on a non-container, non-door reference." << std::endl;
#endif
		}

		Stack::getInstance().pushShort(cost);
		Stack::getInstance().pushString(name);
		Stack::getInstance().pushString(id);

		return 0.0f;
	}
}