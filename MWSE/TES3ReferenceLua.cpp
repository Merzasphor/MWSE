#include "TES3ReferenceLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"
#include "TES3ScriptLua.h"

#include "TES3Util.h"

#include "NINode.h"
#include "NIPointLight.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3ItemData.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3WorldController.h"

namespace TES3 {
	sol::object Reference::getAttachments() {
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		auto stateHandle = luaManager.getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		sol::table result = state.create_table();

		Attachment* attachment = this->attachments;
		while (attachment) {
			switch (attachment->type) {
			case AttachmentType::Light:
				result["light"] = sol::make_object(state, reinterpret_cast<LockAttachment*>(attachment)->data);
				break;
			case AttachmentType::Lock:
				result["lock"] = sol::make_object(state, reinterpret_cast<LockAttachment*>(attachment)->data);
				break;
			case AttachmentType::TravelDestination:
				result["travelDestination"] = sol::make_object(state, reinterpret_cast<TravelDestinationAttachment*>(attachment)->data);
				break;
			case AttachmentType::Variables:
				result["variables"] = sol::make_object(state, reinterpret_cast<ItemDataAttachment*>(attachment)->data);
				break;
			case AttachmentType::ActorData:
				result["actor"] = mwse::lua::makeLuaObject(reinterpret_cast<MobileActorAttachment*>(attachment)->data);
				break;
			}

			attachment = attachment->next;
		}

		return result;
	}

	sol::table Reference::getLuaTable() {
		auto itemData = getAttachedItemData();

		// Create the item data if it doesn't already exist.
		if (itemData == nullptr) {
			itemData = ItemData::createForObject(baseObject);
			setAttachedItemData(itemData);
		}
		// Prevent adding a lua table if there's more than one item involved.
		else if (itemData->count > 1) {
			throw std::exception("Cannot create lua data when more than one item is present.");
		}

		return itemData->getOrCreateLuaDataTable();
	}
}

namespace mwse {
	namespace lua {
		sol::object getContext(TES3::Reference& reference) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			auto variables = reference.getAttachedItemData();
			if (variables == NULL) {
				return sol::nil;
			}
			return sol::make_object(state, std::shared_ptr<ScriptContext>(new ScriptContext(variables->script, variables->scriptData)));
		}

		void bindTES3Reference() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Reference>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Object, TES3::BaseObject>());
			setUserdataForObject(usertypeDefinition);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("baseObject", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.getBaseObject()); }));
			usertypeDefinition.set("cell", sol::readonly_property([](TES3::Reference& self) -> sol::object {
				// Handle case for the player.
				if (TES3::WorldController::get()->getMobilePlayer()->reference == &self) {
					return makeLuaObject(TES3::DataHandler::get()->currentCell);
				}

				if (self.owningCollection.asReferenceList == nullptr) {
					return sol::nil;
				}

				return makeLuaObject(self.owningCollection.asReferenceList->cell);
			}));
			usertypeDefinition.set("object", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.baseObject); }));
			usertypeDefinition.set("sceneNode", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.sceneNode); }));

			// Basic function binding.
			usertypeDefinition.set("activate", [](TES3::Reference& self, TES3::Reference& target) { target.activate(&self); });
			usertypeDefinition.set("clearActionFlag", &TES3::Reference::clearActionFlag);
			usertypeDefinition.set("clone", &TES3::Reference::clone);
			usertypeDefinition.set("deleteDynamicLightAttachment", &TES3::Reference::deleteDynamicLightAttachment);
			usertypeDefinition.set("detachDynamicLightFromAffectedNodes", &TES3::Reference::detachDynamicLightFromAffectedNodes);
			usertypeDefinition.set("disable", &TES3::Reference::disable);
			usertypeDefinition.set("enable", &TES3::Reference::enable);
			usertypeDefinition.set("getAttachedDynamicLight", &TES3::Reference::getAttachedDynamicLight);
			usertypeDefinition.set("getOrCreateAttachedDynamicLight", &TES3::Reference::getOrCreateAttachedDynamicLight);
			usertypeDefinition.set("setActionFlag", &TES3::Reference::setActionFlag);
			usertypeDefinition.set("testActionFlag", &TES3::Reference::testActionFlag);
			usertypeDefinition.set("updateEquipment", &TES3::Reference::updateBipedParts);

			// Functions exposed as properties.
			usertypeDefinition.set("activationReference", sol::property(&TES3::Reference::getActionReference, &TES3::Reference::setActionReference));
			usertypeDefinition.set("attachments", sol::readonly_property(&TES3::Reference::getAttachments));
			usertypeDefinition.set("context", sol::readonly_property(&getContext));
			usertypeDefinition.set("data", sol::readonly_property(&TES3::Reference::getLuaTable));
			usertypeDefinition.set("isEmpty", sol::property(&TES3::Reference::getEmptyInventoryFlag, &TES3::Reference::setEmptyInventoryFlag));
			usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::Reference::isRespawn));
			usertypeDefinition.set("orientation", sol::property([](TES3::Reference& self) { return self.getOrientation(); }, &TES3::Reference::setOrientationFromLua));
			usertypeDefinition.set("position", sol::property([](TES3::Reference& self) { return self.getPosition(); }, &TES3::Reference::setPositionFromLua));

			// Functions for manually syncing the scene graph, for if orientation or position is manually modified.
			usertypeDefinition.set("updateSceneGraph", [](TES3::Reference& self) {
				TES3::Matrix33 tempOutArg;
				self.sceneNode->setLocalRotationMatrix(self.updateSceneMatrix(&tempOutArg));
				self.sceneNode->update();
				self.setObjectModified(true);
			});

			// Quick access to attachment data.
			usertypeDefinition.set("itemData", sol::property(
				[](TES3::Reference& self)
				{
					return self.getAttachedItemData();
				},
				[](TES3::Reference& self, TES3::ItemData * value)
				{
					auto attachment = static_cast<TES3::ItemDataAttachment*>(self.getAttachment(TES3::AttachmentType::Variables));
					if (attachment) {
						attachment->data = value;
					}
					else if (value != nullptr) {
						self.addItemDataAttachment(value);
					}
				}
			));
			usertypeDefinition.set("lockNode", sol::property([](TES3::Reference& self) {
				return self.getAttachedLockNode();
			}));
			usertypeDefinition.set("destination", sol::property([](TES3::Reference& self) -> TES3::TravelDestination * {
				TES3::TravelDestinationAttachment * attachment = static_cast<TES3::TravelDestinationAttachment*>(self.getAttachment(TES3::AttachmentType::TravelDestination));
				if (attachment) {
					return attachment->data;
				}
				return nullptr;
			}));
			usertypeDefinition.set("light", sol::property([](TES3::Reference& self) -> sol::object {
				auto attachment = static_cast<TES3::LightAttachment*>(self.getAttachment(TES3::AttachmentType::Light));
				if (attachment) {
					return makeLuaObject(attachment->data->light);
				}
				return sol::nil;
			}));
			usertypeDefinition.set("mobile", sol::property([](TES3::Reference& self) {
				return makeLuaObject(self.getAttachedMobileActor());
			}));
			usertypeDefinition.set("stackSize", sol::property(
				[](TES3::Reference& self)
			{
				TES3::ItemData* itemData = self.getAttachedItemData();
				return itemData ? itemData->count : 1;
			},
				[](TES3::Reference& self, int count)
			{
				TES3::ItemData* itemData = self.getOrCreateAttachedItemData();
				itemData->count = count;
			}
			));
			
			// Allow references to behave like a linked list node.
			usertypeDefinition.set("previousNode", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.previousInCollection); }));
			usertypeDefinition.set("nextNode", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.nextInCollection); }));
			usertypeDefinition.set("nodeData", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(&self); }));

			// Finish up our usertype.
			state.set_usertype("tes3reference", usertypeDefinition);
		}
	}
}
