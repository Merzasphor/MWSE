/************************************************************************
	
	xGetLockLevel.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetLockLevel : mwse::InstructionInterface_t
	{
	public:
		xGetLockLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetLockLevel xGetLockLevelInstance;

	xGetLockLevel::xGetLockLevel() : mwse::InstructionInterface_t(OpCode::xGetLockLevel) {}

	void xGetLockLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetLockLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwShort_t lockLevel = -1;

		// Get reference to what we're finding the lock level of.
		REFRRecord_t* reference = virtualMachine.getReference();

		RecordTypes::recordType_t type = reference->recordPointer->recordType;
		if (type == RecordTypes::CONTAINER || type == RecordTypes::DOOR) {
			mwLockNode_t* lockNode = tes3::getAttachedLockNode(reference);
			if (lockNode) {
				lockLevel = lockNode->lockLevel;
			}
			else {
				log::getLog() << "xGetLockLevel: Could not obtain lock node." << std::endl;
			}
		}
		else {
			log::getLog() << "xGetLockLevel: Called on a non-container, non-door reference." << std::endl;
		}

		Stack::getInstance().pushShort(lockLevel);

		return 0.0f;
	}
}