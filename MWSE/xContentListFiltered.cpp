/************************************************************************

	xContentListFiltered.cpp - Copyright (c) 2008 The MWSE Project
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
	class xContentListFiltered : mwse::InstructionInterface_t {
	public:
		xContentListFiltered();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xContentListFiltered xContentListFilteredInstance;

	xContentListFiltered::xContentListFiltered() : mwse::InstructionInterface_t(OpCode::xContentListFiltered) {}

	void xContentListFiltered::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xContentListFiltered::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		IteratorNode_t<InventoryNode_t>* node = reinterpret_cast<IteratorNode_t<InventoryNode_t>*>(mwse::Stack::getInstance().popLong());
		mwLong_t filter = mwse::Stack::getInstance().popLong();

		// If we're not filtering, abandon ship.
		if (filter == 0) {
#if _DEBUG
			mwse::log::getLog() << "xContentListFiltered: No filter provided." << std::endl;
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

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xContentListFiltered: Called on invalid reference." << std::endl;
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
		mwLong_t count = 0;
		mwLong_t type = 0;
		mwLong_t value = 0;
		mwFloat_t weight = 0;
		mwString_t name = NULL;
		IteratorNode_t<InventoryNode_t>* next = NULL;

		// If we aren't given a node, get the first one.
		if (node == NULL) {
			node = tes3::getFirstInventoryNode(reference);

			// Pass over any records that don't match the current filter.
			while (node && node->data && node->data->recordAddress
				&& !(tes3::getBitMaskForRecordType(node->data->recordAddress->recordType) & filter)) {
				node = node->next;
			}
		}

		// Validate the node we've obtained.
		if (node && node->data && node->data->recordAddress) {
			TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(node->data->recordAddress);

			id = record->objectId;
			count = node->data->itemCount;
			type = record->recordType;

			// Get value.
			try {
				value = tes3::getValue(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				value = 0;
#if _DEBUG
				mwse::log::getLog() << "xContentListFiltered: Could not get value of object '" << id << "'. " << e.what() << std::endl;
#endif
			}

			// Get weight.
			try {
				weight = tes3::getWeight(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				weight = 0.0f;
#if _DEBUG
				mwse::log::getLog() << "xContentListFiltered: Could not get weight of object '" << id << "'. " << e.what() << std::endl;
#endif
			}

			// Get name.
			try {
				name = tes3::getName(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				name = NULL;
#if _DEBUG
				mwse::log::getLog() << "xContentListFiltered: Could not get name of object '" << id << "'. " << e.what() << std::endl;
#endif
			}

			// Get next node. Pass over any records that don't match the given filter.
			next = node->next;
			while (next && next->data && next->data->recordAddress
				&& !(tes3::getBitMaskForRecordType(next->data->recordAddress->recordType) & filter)) {
				next = next->next;
			}
		}

		// Push values to the stack.
		mwse::Stack::getInstance().pushLong((mwLong_t)next);
		mwse::Stack::getInstance().pushString(name);
		mwse::Stack::getInstance().pushFloat(weight);
		mwse::Stack::getInstance().pushLong(value);
		mwse::Stack::getInstance().pushLong(type);
		mwse::Stack::getInstance().pushLong(count);
		mwse::Stack::getInstance().pushString(id);

		return 0.0f;
	}
}