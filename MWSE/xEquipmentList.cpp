/************************************************************************
	
	xEquipmentList.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Armor.h"
#include "TES3Clothing.h"
#include "TES3Weapon.h"
#include "TES3NPC.h"
#include "TES3Enchantment.h"

using namespace mwse;

namespace mwse {
	class xEquipmentList : mwse::InstructionInterface_t {
	public:
		xEquipmentList();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
		
	private:
		mwLong getSubtype(TES3::BaseObject* record);
		bool nodeMatchesFilter(TES3::IteratorNode<TES3::BaseObject*>* node, mwLong typeFilter, mwLong subtypeFilter);
	};

	static xEquipmentList xEquipmentListInstance;

	xEquipmentList::xEquipmentList() : mwse::InstructionInterface_t(OpCode::xEquipmentList) {}

	void xEquipmentList::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xEquipmentList::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		TES3::IteratorNode<TES3::BaseObject*>* node = reinterpret_cast<TES3::IteratorNode<TES3::BaseObject*>*>(mwse::Stack::getInstance().popLong());
		mwLong typeFilter = mwse::Stack::getInstance().popLong();
		mwLong subtypeFilter = mwse::Stack::getInstance().popLong() - 1;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
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

		TES3::ObjectType::ObjectType objectType = reference->objectPointer->objectType;
		if (objectType != TES3::ObjectType::NPC && objectType != TES3::ObjectType::Creature) {
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
		mwLong count = 0;
		mwLong type = 0;
		mwLong subtype = -1;
		mwLong value = 0;
		mwFloat weight = 0;
		mwString name = NULL;
		mwString enchantId = NULL;
		TES3::IteratorNode<TES3::BaseObject*>* next = NULL;

		// If we aren't given a node, get the first one.
		if (node == NULL) {
			node = reinterpret_cast<TES3::NPCInstance*>(reference->objectPointer)->equipment.head;

			// Pass over any records that don't match the current filters.
			while (node && !nodeMatchesFilter(node, typeFilter, subtypeFilter)) {
				node = node->next;
			}
		}

		// Validate the node we've obtained.
		if (node && node->data) {
			TES3::BaseObject* record = *node->data;

			id = record->objectID;
			type = record->objectType;

			// Get subtype.
			subtype = getSubtype(record) + 1;

			// Get count. Right now we hardcode this to 1, but ammo might actually have a count.
			count = 1;

			// Get value.
			try {
				value = tes3::getValue(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				value = 0;
				mwse::log::getLog() << "xEquipmentList: Could not get value of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get weight.
			try {
				weight = tes3::getWeight(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				weight = 0.0f;
				mwse::log::getLog() << "xEquipmentList: Could not get weight of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get name.
			try {
				name = tes3::getName(reinterpret_cast<TES3::BaseObject*>(record));
			}
			catch (std::exception& e) {
				name = NULL;
				mwse::log::getLog() << "xEquipmentList: Could not get name of object '" << id << "'. " << e.what() << std::endl;
			}

			// Get enchantment id.
			try {
				TES3::Enchantment* enchantment = tes3::getEnchantment(record);
				if (enchantment) {
					enchantId = enchantment->objectID;
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
		mwse::Stack::getInstance().pushLong((mwLong)next);
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

	mwLong xEquipmentList::getSubtype(TES3::BaseObject* record) {
		if (record == NULL) {
			return -2;
		}

		mwLong subtype = -2;

		TES3::Ammo * ammo = reinterpret_cast<TES3::Ammo*>(record);
		switch (record->objectType) {
		case TES3::ObjectType::Ammo:
			subtype = ammo->weight;
			break;
		case TES3::ObjectType::Armor:
			subtype = reinterpret_cast<TES3::Armor*>(record)->slot;
			break;
		case TES3::ObjectType::Clothing:
			subtype = reinterpret_cast<TES3::Clothing*>(record)->slot;
			break;
		case TES3::ObjectType::Weapon:
			subtype = reinterpret_cast<TES3::Weapon*>(record)->weaponType;
			break;
		}

		return subtype;
	}

	bool xEquipmentList::nodeMatchesFilter(TES3::IteratorNode<TES3::BaseObject*>* node, mwLong typeFilter, mwLong subtypeFilter) {
		TES3::BaseObject* record = *node->data;

		if (typeFilter != 0 && record->objectType != typeFilter) {
			return false;
		}

		if (subtypeFilter != -1 && getSubtype(record) != subtypeFilter) {
			return false;
		}

		return true;
	}
}