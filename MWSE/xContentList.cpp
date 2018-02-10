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

	static xContentList xContentListInstance;

	xContentList::xContentList() : mwse::InstructionInterface_t(OpCode::xContentList) {}

	void xContentList::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xContentList::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		TES3::IteratorNode<TES3::InventoryNode>* node = reinterpret_cast<TES3::IteratorNode<TES3::InventoryNode>*>(mwse::Stack::getInstance().popLong());

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xContentList: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushFloat(0.0f);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Results.
		char * id = NULL;
		mwLong count = 0;
		mwLong type = 0;
		mwLong value = 0;
		mwFloat weight = 0;
		mwString name = NULL;
		TES3::IteratorNode<TES3::InventoryNode>* next = NULL;

		// If we aren't given a node, get the first one.
		if (node == NULL) {
			node = tes3::getFirstInventoryNode(reference);
		}

		// Validate the node we've obtained.
		if (node && node->data && node->data->object) {
			TES3::BaseObject* record = reinterpret_cast<TES3::BaseObject*>(node->data->object);
			
			id = record->objectID;
			count = node->data->itemCount;
			type = record->objectType;

			// Get value.
			try {
				value = tes3::getValue(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				value = 0;
				mwse::log::getLog() << "xContentList: Could not get value of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get weight.
			try {
				weight = tes3::getWeight(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				weight = 0.0f;
				mwse::log::getLog() << "xContentList: Could not get weight of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get name.
			try {
				name = tes3::getName(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				name = NULL;
				mwse::log::getLog() << "xContentList: Could not get name of object '" << id << "'. " << e.what() << std::endl;
			}
			
			next = node->next;
		}

		// Push values to the stack.
		mwse::Stack::getInstance().pushLong((mwLong)next);
		mwse::Stack::getInstance().pushString(name);
		mwse::Stack::getInstance().pushFloat(weight);
		mwse::Stack::getInstance().pushLong(value);
		mwse::Stack::getInstance().pushLong(type);
		mwse::Stack::getInstance().pushLong(count);
		mwse::Stack::getInstance().pushString(id);

		return 0.0f;
	}
}