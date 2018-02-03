/************************************************************************
	
	xGetStackSize.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse {
	class xGetStackSize : mwse::InstructionInterface_t {
	public:
		xGetStackSize();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetStackSize xGetStackSizeInstance;

	xGetStackSize::xGetStackSize() : mwse::InstructionInterface_t(OpCode::xGetStackSize) {}

	void xGetStackSize::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetStackSize::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetStackSize: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the associated variable node and its item count.
		mwLong_t count = 0;
		InventoryNode_t* inventoryNode = reinterpret_cast<InventoryNode_t*>(tes3::getAttachedVarHolderNode(reference));
		if (inventoryNode) {
			count = inventoryNode->itemCount;
		}

		mwse::Stack::getInstance().pushLong(count);

		return 0.0f;
	}
}