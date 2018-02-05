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

	private:
		mwLong_t getBitMaskForRecordType(mwLong_t recordType);
		bool passesFilter(BaseRecord_t* record, mwLong_t filter);

		enum FilterMask {
			FILTER_ACTI = 1,
			FILTER_ALCH = 2,
			FILTER_AMMO = 4,
			FILTER_APPA = 8,
			FILTER_ARMO = 16,
			FILTER_BODY = 32,
			FILTER_BOOK = 64,
			FILTER_CLOT = 128,
			FILTER_CONT = 256,
			FILTER_CREA = 512,
			FILTER_DOOR = 1024,
			FILTER_INGR = 2048,
			FILTER_LEVC = 4096,
			FILTER_LEVI = 8192,
			FILTER_LIGH = 16384,
			FILTER_LOCK = 32768,
			FILTER_MISC = 65536,
			FILTER_NPC = 131072,
			FILTER_PROB = 262144,
			FILTER_REPA = 524288,
			FILTER_STAT = 1048576,
			FILTER_WEAP = 2097152,
			FILTER_ENCH = 4194304
		};
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
			while (node && node->data && node->data->recordAddress && !passesFilter(node->data->recordAddress, filter)) {
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
			while (next && next->data && next->data->recordAddress && !passesFilter(next->data->recordAddress, filter)) {
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

	mwLong_t xContentListFiltered::getBitMaskForRecordType(mwLong_t recordType) {
		switch (recordType) {
		case RecordTypes::ACTIVATOR: return FILTER_ACTI;
		case RecordTypes::ALCHEMY: return FILTER_ALCH;
		case RecordTypes::AMMO: return FILTER_AMMO;
		case RecordTypes::APPARATUS: return FILTER_APPA;
		case RecordTypes::ARMOR: return FILTER_ARMO;
		case RecordTypes::BODY: return FILTER_BODY;
		case RecordTypes::BOOK: return FILTER_BOOK;
		case RecordTypes::CLOTHING: return FILTER_CLOT;
		case RecordTypes::CONTAINER: return FILTER_CONT;
		case RecordTypes::CREATURE: return FILTER_CREA;
		case RecordTypes::DOOR: return FILTER_DOOR;
		case RecordTypes::INGREDIENT: return FILTER_INGR;
		case RecordTypes::LEVELLEDCREATURE: return FILTER_LEVC;
		case RecordTypes::LEVELLEDITEM: return FILTER_LEVI;
		case RecordTypes::LIGHT: return FILTER_LIGH;
		case RecordTypes::LOCKPICK: return FILTER_LOCK;
		case RecordTypes::MISC: return FILTER_MISC;
		case RecordTypes::NPC: return FILTER_NPC;
		case RecordTypes::PROBE: return FILTER_PROB;
		case RecordTypes::REPAIR: return FILTER_REPA;
		case RecordTypes::STATIC: return FILTER_STAT;
		case RecordTypes::WEAPON: return FILTER_WEAP;
		}

		return 0x0;
	}

	bool xContentListFiltered::passesFilter(BaseRecord_t* record, mwLong_t filter) {
		// Filter by record type. Unless we're not filtering only by enchantment.
		if (filter != FILTER_ENCH && !(getBitMaskForRecordType(record->recordType) & filter)) {
			return false;
		}

		// If we're filtering by enchantment, verify that the record has one.
		if ((filter & FILTER_ENCH) && tes3::getEnchantment(reinterpret_cast<TES3DefaultTemplate_t*>(record)) == NULL) {
			return false;
		}

		return true;
	}
}