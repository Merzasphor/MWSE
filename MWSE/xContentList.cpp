/************************************************************************
	
	xContentList.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse {
	class xContentList : mwse::InstructionInterface_t {
	public:
		xContentList();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xContentListOpcode = 0x3F03;
	static xContentList xContentListInstance;

	xContentList::xContentList() : mwse::InstructionInterface_t(xContentListOpcode) {}

	void xContentList::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xContentList::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		ListNode_t<InventoryNode_t>* node = reinterpret_cast<ListNode_t<InventoryNode_t>*>(mwse::Stack::getInstance().popLong());

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();

		// Results.
		mwLong_t id = NULL;
		mwLong_t count = 0;
		mwLong_t type = 0;
		mwLong_t value = 0;
		mwFloat_t weight = 0;
		mwLong_t name = 0;
		ListNode_t<InventoryNode_t>* next = NULL;

		// If we aren't given a node, get the first one.
		if (node == NULL) {
			node = tes3::getFirstInventoryNode(reference);
		}

		// Validate the node we've obtained.
		if (node && node->dataPtr && node->dataPtr->recordAddress) {
			TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(node->dataPtr->recordAddress);
			
			id = mwseString_t::get(record->objectId);
			count = node->dataPtr->itemCount;
			type = record->recordType;

			// Get value.
			try {
				value = tes3::getValue(reference, false);
			}
			catch (std::exception& e) {
				value = 0;
			}

			// Get weight.
			try {
				weight = tes3::getWeight(reference, false);
			}
			catch (std::exception& e) {
				weight = 0.0f;
			}

			// Get name.
			try {
				name = tes3::getName(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				name = NULL;
			}
			
			next = node->nextNode;
		}

		// Push values to the stack.
		mwse::Stack::getInstance().pushLong((mwLong_t)next);
		mwse::Stack::getInstance().pushLong(name);
		mwse::Stack::getInstance().pushFloat(weight);
		mwse::Stack::getInstance().pushLong(value);
		mwse::Stack::getInstance().pushLong(type);
		mwse::Stack::getInstance().pushLong(count);
		mwse::Stack::getInstance().pushLong(id);

		return 0.0;
	}
}