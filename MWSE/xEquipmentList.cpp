/************************************************************************
	
	xEquipmentList.cpp - Copyright (c) 2008 The MWSE Project
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
	class xEquipmentList : mwse::InstructionInterface_t {
	public:
		xEquipmentList();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
		
	private:
		mwLong_t getSubtype(TES3DefaultTemplate_t* record);
		bool nodeMatchesFilter(IteratorNode_t<TES3DefaultTemplate_t*>* node, mwLong_t typeFilter, mwLong_t subtypeFilter);
	};

	static xEquipmentList xEquipmentListInstance;

	xEquipmentList::xEquipmentList() : mwse::InstructionInterface_t(OpCode::xEquipmentList) {}

	void xEquipmentList::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xEquipmentList::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		IteratorNode_t<TES3DefaultTemplate_t*>* node = reinterpret_cast<IteratorNode_t<TES3DefaultTemplate_t*>*>(mwse::Stack::getInstance().popLong());
		mwLong_t typeFilter = mwse::Stack::getInstance().popLong();
		mwLong_t subtypeFilter = mwse::Stack::getInstance().popLong() - 1;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xEquipmentList: Called without refrence." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushFloat(0.0f);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		if (reference->recordPointer->recordType != RecordTypes::NPC && reference->recordPointer->recordType != RecordTypes::CREATURE) {
			mwse::log::getLog() << "xEquipmentList: Called on non-NPC, non-creature." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushFloat(0.0f);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Results.
		char * id = NULL;
		mwLong_t count = 0;
		mwLong_t type = 0;
		mwLong_t subtype = -1;
		mwLong_t value = 0;
		mwFloat_t weight = 0;
		mwString_t name = NULL;
		mwString_t enchantId = NULL;
		IteratorNode_t<TES3DefaultTemplate_t*>* next = NULL;

		// If we aren't given a node, get the first one.
		if (node == NULL) {
			node = reinterpret_cast<NPCCopyRecord_t*>(reference->recordPointer)->equipment.head;

			// Pass over any records that don't match the current filters.
			while (node && !nodeMatchesFilter(node, typeFilter, subtypeFilter)) {
				node = node->next;
			}
		}

		// Validate the node we've obtained.
		if (node && node->data) {
			TES3DefaultTemplate_t* record = *node->data;

			id = record->objectId;
			type = record->recordType;

			// Get subtype.
			subtype = getSubtype(record) + 1;

			// Get count. Right now we hardcode this to 1, but ammo might actually have a count.
			count = 1;

			// Get value.
			try {
				value = tes3::getValue(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				value = 0;
				mwse::log::getLog() << "xEquipmentList: Could not get value of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get weight.
			try {
				weight = tes3::getWeight(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				weight = 0.0f;
				mwse::log::getLog() << "xEquipmentList: Could not get weight of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get name.
			try {
				name = tes3::getName(reinterpret_cast<BaseRecord_t*>(record));
			}
			catch (std::exception& e) {
				name = NULL;
				mwse::log::getLog() << "xEquipmentList: Could not get name of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get enchantment id.
			try {
				ENCHRecord_t* enchantment = tes3::getEnchantment(record);
				if (enchantment) {
					enchantId = enchantment->id;
				}
			}
			catch (std::exception& e) {
				name = NULL;
				mwse::log::getLog() << "xEquipmentList: Could not get enchantment id of object '" << id << "'. " << e.what() << std::endl;
			}

			// Pass over any records that don't match the current filters.
			next = node->next;
			while (next && !nodeMatchesFilter(next, typeFilter, subtypeFilter)) {
				next = next->next;
			}
		}

		// Push values to the stack.
		mwse::Stack::getInstance().pushLong((mwLong_t)next);
		mwse::Stack::getInstance().pushString(enchantId);
		mwse::Stack::getInstance().pushString(name);
		mwse::Stack::getInstance().pushFloat(weight);
		mwse::Stack::getInstance().pushLong(value);
		mwse::Stack::getInstance().pushLong(subtype);
		mwse::Stack::getInstance().pushLong(type);
		mwse::Stack::getInstance().pushLong(count);
		mwse::Stack::getInstance().pushString(id);

		return 0.0f;
	}

	mwLong_t xEquipmentList::getSubtype(TES3DefaultTemplate_t* record) {
		if (record == NULL) {
			return -2;
		}

		mwLong_t subtype = -2;

		AMMORecord_t * ammo = reinterpret_cast<AMMORecord_t*>(record);
		switch (record->recordType) {
		case RecordTypes::AMMO:
			subtype = ammo->weight;
			break;
		case RecordTypes::ARMOR:
			subtype = reinterpret_cast<ARMORecord_t*>(record)->slot;
			break;
		case RecordTypes::CLOTHING:
			subtype = reinterpret_cast<CLOTRecord_t*>(record)->slot;
			break;
		case RecordTypes::WEAPON:
			subtype = reinterpret_cast<WEAPRecord_t*>(record)->weaponType;
			break;
		}

		return subtype;
	}

	bool xEquipmentList::nodeMatchesFilter(IteratorNode_t<TES3DefaultTemplate_t*>* node, mwLong_t typeFilter, mwLong_t subtypeFilter) {
		TES3DefaultTemplate_t* record = *node->data;

		if (typeFilter != 0 && record->recordType != typeFilter) {
			return false;
		}

		if (subtypeFilter != -1 && getSubtype(record) != subtypeFilter) {
			return false;
		}

		return true;
	}
}