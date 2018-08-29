#include "TES3InventoryLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3ScriptLua.h"

#include "TES3Inventory.h"
#include "TES3GlobalVariable.h"
#include "TES3Creature.h"
#include "TES3Script.h"

namespace TES3 {
	sol::object ItemStack::getObjectLua() {
		return mwse::lua::makeLuaObject(object);
	}

	sol::object EquipmentStack::getObjectLua() {
		return mwse::lua::makeLuaObject(object);
	}
}

namespace mwse {
	namespace lua {
		sol::object getItemDataOwner(TES3::ItemData& itemData) {
			return makeLuaObject(itemData.owner);
		}

		void setItemDataOwner(TES3::ItemData& itemData, sol::object value) {
			if (value.is<TES3::BaseObject*>()) {
				TES3::BaseObject * newOwner = value.as<TES3::BaseObject*>();

				// We only support NPC and Faction owners.
				if (newOwner->objectType != TES3::ObjectType::NPC && newOwner->objectType != TES3::ObjectType::Faction) {
					sol::state& state = LuaManager::getInstance().getState();
					state["error"]("Ownership must be an NPC or a faction.");
					return;
				}

				// If the owner type is changing, reset the requirement.
				if (itemData.owner->objectType != newOwner->objectType) {
					itemData.requirement.variable = NULL;
				}

				itemData.owner = newOwner;
			}
		}

		sol::object getItemDataOwnerRequirement(TES3::ItemData& itemData) {
			if (itemData.owner == NULL) {
				return sol::nil;
			}
			else if (itemData.owner->objectType == TES3::ObjectType::Faction) {
				return sol::make_object(LuaManager::getInstance().getState(), itemData.requirement.rank);
			}
			else if (itemData.owner->objectType == TES3::ObjectType::NPC) {
				return makeLuaObject(itemData.requirement.variable);
			}

			return sol::nil;
		}

		void setItemDataOwnerRequirement(TES3::ItemData& itemData, sol::object value) {
			if (itemData.owner == NULL) {
				sol::state& state = LuaManager::getInstance().getState();
				state["error"]("An owner must be set before the requirement can be set.");
			}
			else if (itemData.owner->objectType == TES3::ObjectType::Faction) {
				if (value.is<double>()) {
					itemData.requirement.rank = (int)value.as<double>();
				}
				else {
					sol::state& state = LuaManager::getInstance().getState();
					state["error"]("Faction ownership used. Requirement must be a rank (number).");
				}
			}
			else if (itemData.owner->objectType == TES3::ObjectType::NPC) {
				if (value.is<TES3::GlobalVariable*>()) {
					itemData.requirement.variable = value.as<TES3::GlobalVariable*>();
				}
				else {
					sol::state& state = LuaManager::getInstance().getState();
					state["error"]("NPC ownership used. Requirement must be a global variable.");
				}
			}
		}

		float getItemDataCharge(TES3::ItemData& itemData) {
			return itemData.enchantData.charge;
		}

		void setItemDataCharge(TES3::ItemData& itemData, float charge) {
			itemData.enchantData.charge = charge;
		}

		sol::object getItemDataSoul(TES3::ItemData& itemData) {
			// Make our best attempt at making sure this actually has a soul. This is not reliable!
			if (itemData.enchantData.charge == -1.0f) {
				return sol::nil;
			}

			return makeLuaObject(itemData.enchantData.soul);
		}

		void setItemDataSoul(TES3::ItemData& itemData, sol::object soul) {
			// Make our best attempt at making sure this actually has a soul. This is not reliable!
			if (itemData.enchantData.charge == -1.0f) {
				return;
			}
			else if (soul.is<TES3::Creature*>()) {
				itemData.enchantData.soul = soul.as<TES3::Creature*>();
			}
			else if (soul.is<TES3::CreatureInstance*>()) {
				itemData.enchantData.soul = soul.as<TES3::CreatureInstance*>()->baseCreature;
			}
		}

		void bindTES3Inventory() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::ItemData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::ItemData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("count", &TES3::ItemData::count);
				usertypeDefinition.set("condition", &TES3::ItemData::condition);
				usertypeDefinition.set("scriptVariables", &TES3::ItemData::scriptData);
				usertypeDefinition.set("timeLeft", &TES3::ItemData::timeLeft);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("script", sol::readonly_property([](TES3::ItemData& self) { return makeLuaObject(self.script); }));

				// Functions exposed as properties.
				usertypeDefinition.set("charge", sol::property(&getItemDataCharge, &setItemDataCharge));
				usertypeDefinition.set("owner", sol::property(&getItemDataOwner, &setItemDataOwner));
				usertypeDefinition.set("requirement", sol::property(&getItemDataOwnerRequirement, &setItemDataOwnerRequirement));
				usertypeDefinition.set("soul", sol::property(&getItemDataSoul, &setItemDataSoul));

				// Add the ability to get the unique script context from this itemdata for ease of mwscript interaction.
				usertypeDefinition.set("context", sol::readonly_property([](TES3::ItemData& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script, self.scriptData)); }));

				// Finish up our usertype.
				state.set_usertype("tes3itemData", usertypeDefinition);
			}

			// Binding for TES3::ItemStack
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::ItemStack>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("count", &TES3::ItemStack::count);
				usertypeDefinition.set("variables", &TES3::ItemStack::variables);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("object", sol::readonly_property([](TES3::ItemStack& self) { return makeLuaObject(self.object); }));

				// Finish up our usertype.
				state.set_usertype("tes3itemStack", usertypeDefinition);
			}

			// Binding for TES3::EquipmentStack
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::EquipmentStack>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("variables", &TES3::EquipmentStack::variables);

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("object", sol::readonly_property([](TES3::EquipmentStack& self) { return makeLuaObject(self.object); }));

				// Finish up our usertype.
				state.set_usertype("tes3equipmentStack", usertypeDefinition);
			}

			// Binding for TES3::Inventory
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Inventory>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("flags", sol::readonly_property(&TES3::Inventory::flags));
				usertypeDefinition.set("iterator", sol::readonly_property(&TES3::Inventory::iterator));

				// Basic function binding.
				usertypeDefinition.set("resolveLeveledItems", [](TES3::Inventory& self, sol::optional<TES3::MobileActor*> actor) { self.resolveLeveledLists(actor.value_or(nullptr)); });

				// Finish up our usertype.
				state.set_usertype("tes3inventory", usertypeDefinition);
			}
		}
	}
}
