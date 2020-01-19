#include "TES3InventoryLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3CollectionsLua.h"
#include "TES3ScriptLua.h"

#include "TES3Inventory.h"
#include "TES3ItemData.h"
#include "TES3GlobalVariable.h"
#include "TES3Creature.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		TES3::BaseObject* getItemDataOwner(TES3::ItemData& itemData) {
			return itemData.owner;
		}

		void setItemDataOwner(TES3::ItemData& itemData, sol::object value) {
			if (value == sol::nil) { 
				itemData.owner = nullptr; 
			}
			else if (value.is<TES3::BaseObject*>()) {
				TES3::BaseObject * newOwner = value.as<TES3::BaseObject*>();

				// We only support NPC and Faction owners.
				if (newOwner->objectType != TES3::ObjectType::NPC && newOwner->objectType != TES3::ObjectType::Faction) {
					throw std::exception("Ownership must be an NPC or a faction.");
				}

				// If the owner type is changing, reset the requirement.
				if (itemData.owner->objectType != newOwner->objectType) {
					itemData.requiredVariable = nullptr;
				}

				itemData.owner = newOwner;
			}
		}

		sol::object getItemDataOwnerRequirement(TES3::ItemData& itemData) {
			if (itemData.owner == nullptr) {
				return sol::nil;
			}
			else if (itemData.owner->objectType == TES3::ObjectType::Faction) {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				return sol::make_object(state, itemData.requiredRank);
			}
			else if (itemData.owner->objectType == TES3::ObjectType::NPC) {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				return TES3::BaseObject::getOrCreateLuaObject(state, itemData.requiredVariable);
			}

			return sol::nil;
		}

		void setItemDataOwnerRequirement(TES3::ItemData& itemData, sol::object value) {
			if (itemData.owner == nullptr) {
				throw std::exception("An owner must be set before the requirement can be set.");
			}
			else if (itemData.owner->objectType == TES3::ObjectType::Faction) {
				if (value.is<double>()) {
					itemData.requiredRank = (int)value.as<double>();
				}
				else {
					throw std::exception("Faction ownership used. Requirement must be a rank (number).");
				}
			}
			else if (itemData.owner->objectType == TES3::ObjectType::NPC) {
				if (value.is<TES3::GlobalVariable*>()) {
					itemData.requiredVariable = value.as<TES3::GlobalVariable*>();
				}
				else {
					throw std::exception("NPC ownership used. Requirement must be a global variable.");
				}
			}
		}

		TES3::Actor* getItemDataSoul(TES3::ItemData& itemData) {
			return itemData.getSoulActor();
		}

		void setItemDataSoul(TES3::ItemData& itemData, sol::object soul) {
			// Make our best attempt at making sure this actually has a soul. This is not reliable!
			if (itemData.charge == -1.0f) {
				return;
			}
			else if (soul.is<TES3::Creature*>()) {
				itemData.soul = soul.as<TES3::Creature*>();
			}
			else if (soul.is<TES3::CreatureInstance*>()) {
				itemData.soul = soul.as<TES3::CreatureInstance*>()->baseCreature;
			}
		}

		void bindTES3Inventory() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::ItemData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::ItemData>("tes3itemData");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["charge"] = &TES3::ItemData::charge;
				usertypeDefinition["count"] = &TES3::ItemData::count;
				usertypeDefinition["condition"] = &TES3::ItemData::condition;
				usertypeDefinition["scriptVariables"] = &TES3::ItemData::scriptData;
				usertypeDefinition["timeLeft"] = &TES3::ItemData::timeLeft;

				// Access to other objects that need to be packaged.
				usertypeDefinition["script"] = sol::readonly_property([](TES3::ItemData& self) { return self.script; });

				// Complex properties that need special handling.
				usertypeDefinition["owner"] = sol::property(&getItemDataOwner, &setItemDataOwner);
				usertypeDefinition["requirement"] = sol::property(&getItemDataOwnerRequirement, &setItemDataOwnerRequirement);
				usertypeDefinition["soul"] = sol::property(&getItemDataSoul, &setItemDataSoul);

				// 
				usertypeDefinition["data"] = sol::property(&TES3::ItemData::getOrCreateLuaDataTable, &TES3::ItemData::setLuaDataTable);

				// Add the ability to get the unique script context from this itemdata for ease of mwscript interaction.
				usertypeDefinition["context"] = sol::readonly_property([](TES3::ItemData& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script, self.scriptData)); });
			}

			// Binding for TES3::ItemStack
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::ItemStack>("tes3itemStack");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["count"] = &TES3::ItemStack::count;
				usertypeDefinition["variables"] = &TES3::ItemStack::variables;

				// Access to other objects that need to be packaged.
				usertypeDefinition["object"] = sol::readonly_property([](TES3::ItemStack& self) { return self.object; });
			}

			// Binding for TES3::EquipmentStack
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::EquipmentStack>("tes3equipmentStack");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["itemData"] = &TES3::EquipmentStack::variables;
				usertypeDefinition["variables"] = &TES3::EquipmentStack::variables;

				// Access to other objects that need to be packaged.
				usertypeDefinition["object"] = sol::readonly_property([](TES3::EquipmentStack& self) { return self.object; });
			}

			// Binding for TES3::Inventory
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Inventory>("tes3inventory");
				usertypeDefinition["new"] = sol::no_constructor;

				// Metamethod binding.
				usertypeDefinition[sol::meta_function::pairs] = [](TES3::Inventory& self) {
					Iterator_state<TES3::ItemStack> it_state(&self.iterator);
					return std::make_tuple(&bindIterator_pairsNext<TES3::ItemStack>, sol::user<Iterator_state<TES3::ItemStack>>(std::move(it_state)), sol::lua_nil);
				};
				usertypeDefinition[sol::meta_function::length] = [](TES3::Inventory& self) {
					return self.iterator.size;
				};

				// Basic property binding.
				usertypeDefinition["flags"] = sol::readonly_property(&TES3::Inventory::flags);
				usertypeDefinition["iterator"] = sol::readonly_property(&TES3::Inventory::iterator);

				// Basic function binding.
				usertypeDefinition["addItem"] = [](TES3::Inventory& self, sol::table params) {
					TES3::MobileActor * mact = getOptionalParamMobileActor(params, "mobile");
					TES3::Item * item = getOptionalParamObject<TES3::Item>(params, "item");
					int count = getOptionalParam<int>(params, "count", 1);
					TES3::ItemData * itemData = getOptionalParam<TES3::ItemData*>(params, "itemData", nullptr);
					self.addItem(mact, item, count, false, itemData ? &itemData : nullptr);
				};
				usertypeDefinition["contains"] = [](TES3::Inventory& self, sol::object itemOrItemId, sol::optional<TES3::ItemData*> itemData) {
					if (itemOrItemId.is<TES3::Item*>()) {
						auto item = itemOrItemId.as<TES3::Item*>();
						return self.containsItem(item, itemData.value_or(nullptr));
					}
					else if (itemOrItemId.is<const char*>()) {
						TES3::DataHandler * dataHandler = TES3::DataHandler::get();
						if (dataHandler) {
							auto itemId = itemOrItemId.as<const char*>();
							auto item = dataHandler->nonDynamicData->resolveObjectByType<TES3::Item>(itemId);
							return self.containsItem(item, itemData.value_or(nullptr));
						}
					}
					return false;
				};
				usertypeDefinition["dropItem"] = &TES3::Inventory::dropItem;
				usertypeDefinition["calculateWeight"] = &TES3::Inventory::calculateContainedWeight;
				usertypeDefinition["removeItem"] = [](TES3::Inventory& self, sol::table params) {
					TES3::MobileActor * mact = getOptionalParamMobileActor(params, "mobile");
					TES3::Item * item = getOptionalParamObject<TES3::Item>(params, "item");
					int count = getOptionalParam<int>(params, "count", 1);
					TES3::ItemData * itemData = getOptionalParam<TES3::ItemData*>(params, "itemData", nullptr);
					bool deleteItemData = getOptionalParam<bool>(params, "deleteItemData", false);
					self.removeItemWithData(mact, item, itemData, count, deleteItemData);
				};
				usertypeDefinition["resolveLeveledItems"] = [](TES3::Inventory& self, sol::optional<TES3::MobileActor*> actor) { self.resolveLeveledLists(actor.value_or(nullptr)); };
			}
		}
	}
}
