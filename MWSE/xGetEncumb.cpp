/************************************************************************
	
	xGetEncumb.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetEncumb : mwse::InstructionInterface_t
	{
	public:
		xGetEncumb();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetEncumb xGetEncumbInstance;

	xGetEncumb::xGetEncumb() : mwse::InstructionInterface_t(OpCode::xGetEncumb) {}

	void xGetEncumb::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEncumb::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference to target.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetEncumb: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		bool hasLeveledContent = false;
		mwFloat_t totalWeight = 0.0f;

		// Loop through the inventory nodes of the reference, adding weight for each item found.
		ListNode_t<InventoryNode_t>* inventoryListNode = tes3::getFirstInventoryNode(reference);
		while (inventoryListNode) {
			InventoryNode_t* inventoryNode = inventoryListNode->dataPtr;
			if (inventoryNode) {
				totalWeight += tes3::getWeight(inventoryNode->recordAddress) * inventoryNode->itemCount;

				// Keep track if we've run across leveled content.
				if (!hasLeveledContent && inventoryNode->recordAddress->recordType == RecordTypes::LEVELLEDITEM) {
					hasLeveledContent = true;
				}
			}

			inventoryListNode = inventoryListNode->nextNode;
		}

		// If we ran into leveled content, make our weight negative.
		if (hasLeveledContent) {
			totalWeight *= -1;
		}

		mwse::Stack::getInstance().pushFloat(totalWeight);

		return 0.0f;
	}
}