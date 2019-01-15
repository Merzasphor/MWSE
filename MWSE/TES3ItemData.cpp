#include "TES3ItemData.h"

#include "TES3Util.h"

#include "TES3Enchantment.h"
#include "TES3Light.h"
#include "TES3Misc.h"
#include "TES3Weapon.h"

#include "LuaManager.h"

#include <unordered_set>

namespace TES3 {
	//
	// Vanilla ItemData
	//

	const auto TES3_ItemData_constructor = reinterpret_cast<ItemDataVanilla*(__thiscall *)(ItemDataVanilla*)>(0x4E44B0);
	ItemDataVanilla * ItemDataVanilla::ctor(ItemDataVanilla * self) {
		return TES3_ItemData_constructor(self);
	}

	const auto TES3_ItemData_destructor = reinterpret_cast<void(__thiscall *)(ItemDataVanilla*)>(0x4E44E0);
	void ItemDataVanilla::dtor(ItemDataVanilla * self) {
		TES3_ItemData_destructor(self);
	}

	ItemDataVanilla * ItemDataVanilla::createForObject(Object * object) {
		return reinterpret_cast<TES3::ItemDataVanilla*(__cdecl *)(TES3::BaseObject*)>(0x4E7750)(object);
	}

	//
	// MWSE-Extended ItemData
	//

	ItemData::LuaData::LuaData() {
		data = mwse::lua::LuaManager::getInstance().getState().create_table();
	}

	ItemData::ItemData() {
		ctor(this);
	}

	ItemData::~ItemData() {
		dtor(this);
	}

	ItemData * ItemData::ctor(ItemData * self) {
		ItemDataVanilla::ctor(self);
		self->luaData = nullptr;
		return self;
	}

	void ItemData::dtor(ItemData * self) {
		ItemDataVanilla::dtor(self);
		if (self->luaData) {
			delete self->luaData;
		}
	}

	ItemData * ItemData::createForObject(Object * object) {
		auto itemData = mwse::tes3::_new<ItemData>();
		ItemData::ctor(itemData);

		switch (object->objectType) {
		case TES3::ObjectType::Armor:
			itemData->condition = object->getDurability();
			break;
		case TES3::ObjectType::Weapon:
			if (static_cast<Weapon*>(object)->hasDurability()) {
				itemData->condition = object->getDurability();
			}
			break;
		case TES3::ObjectType::Lockpick:
		case TES3::ObjectType::Probe:
		case TES3::ObjectType::Repair:
			itemData->condition = object->getUses();
			break;
		case TES3::ObjectType::Light:
			itemData->timeLeft = static_cast<Light*>(object)->time;
			break;
		case TES3::ObjectType::Misc:
			itemData->count = static_cast<Misc*>(object)->getGoldStackCount();
			break;
		}

		auto enchantment = object->getEnchantment();
		if (enchantment) {
			itemData->charge = enchantment->maxCharge;
		}

		return itemData;
	}

	const auto TES3_IsItemFullyRepaired = reinterpret_cast<bool(__cdecl *)(ItemDataVanilla*, Item*, bool)>(0x4E7970);
	bool ItemData::isFullyRepaired(ItemData * itemData, Item * item, bool fromBarterMenu) {
		if (!TES3_IsItemFullyRepaired(itemData, item, fromBarterMenu)) {
			return false;
		}

		if (itemData->luaData) {
			return itemData->luaData->data.empty();
		}

		return true;
	}

}
