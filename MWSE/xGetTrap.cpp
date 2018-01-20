/************************************************************************
	
	xGetTrap.cpp - Copyright (c) 2008 The MWSE Project
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
		mwString_t id = NULL;
		mwString_t name = NULL;
		mwShort_t cost = 0;

		// Get reference to what we're finding the lock level of.
		REFRRecord_t* reference = virtualMachine.getReference();

		RecordTypes::recordType_t type = reference->recordPointer->recordType;
		if (type == RecordTypes::CONTAINER || type == RecordTypes::DOOR) {
			mwLockNode_t* lockNode = tes3::getAttachedLockNode(reference);
			if (lockNode) {
				SPELRecord_t* trapSpell = lockNode->trapSpell;
				if (trapSpell) {
					id = trapSpell->id;
					name = trapSpell->friendlyName;
					cost = trapSpell->cost;
				}
			}
			else {
				log::getLog() << "xGetTrap: Could not obtain lock node." << std::endl;
			}
		}
		else {
			log::getLog() << "xGetTrap: Called on a non-container, non-door reference." << std::endl;
		}

		Stack::getInstance().pushShort(cost);
		Stack::getInstance().pushString(name);
		Stack::getInstance().pushString(id);

		return 0.0f;
	}
}