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
				result["light"] = reinterpret_cast<LockAttachment*>(attachment)->data;
				break;
			case AttachmentType::Lock:
				result["lock"] = reinterpret_cast<LockAttachment*>(attachment)->data;
				break;
			case AttachmentType::TravelDestination:
				result["travelDestination"] = reinterpret_cast<TravelDestinationAttachment*>(attachment)->data;
				break;
			case AttachmentType::Variables:
				result["variables"] = reinterpret_cast<ItemDataAttachment*>(attachment)->data;
				break;
			case AttachmentType::ActorData:
				result["actor"] = reinterpret_cast<MobileActorAttachment*>(attachment)->data;
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
			if (reference.baseObject->getScript() == nullptr) {
				return sol::nil;
			}

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
			auto usertypeDefinition = state.new_usertype<TES3::Reference>("tes3reference");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::Object, TES3::BaseObject>();
			setUserdataForObject(usertypeDefinition);

			// Access to other objects that need to be packaged.
			usertypeDefinition["baseObject"] = sol::readonly_property([](TES3::Reference& self) { return self.getBaseObject(); });
			usertypeDefinition["cell"] = sol::readonly_property([](TES3::Reference& self) -> TES3::Cell* {
				// Handle case for the player.
				if (TES3::WorldController::get()->getMobilePlayer()->reference == &self) {
					return TES3::DataHandler::get()->currentCell;
				}

				if (self.owningCollection.asReferenceList == nullptr) {
					return nullptr;
				}

				return self.owningCollection.asReferenceList->cell;
			});
			usertypeDefinition["object"] = sol::readonly_property([](TES3::Reference& self) { return self.baseObject; });
			usertypeDefinition["sceneNode"] = sol::readonly_property([](TES3::Reference& self) { return self.sceneNode; });

			// Basic function binding.
			usertypeDefinition["activate"] = [](TES3::Reference& self, TES3::Reference& target) { target.activate(&self); };
			usertypeDefinition["clearActionFlag"] = &TES3::Reference::clearActionFlag;
			usertypeDefinition["clone"] = &TES3::Reference::clone;
			usertypeDefinition["deleteDynamicLightAttachment"] = &TES3::Reference::deleteDynamicLightAttachment;
			usertypeDefinition["detachDynamicLightFromAffectedNodes"] = &TES3::Reference::detachDynamicLightFromAffectedNodes;
			usertypeDefinition["disable"] = &TES3::Reference::disable;
			usertypeDefinition["enable"] = &TES3::Reference::enable;
			usertypeDefinition["getAttachedDynamicLight"] = &TES3::Reference::getAttachedDynamicLight;
			usertypeDefinition["getOrCreateAttachedDynamicLight"] = &TES3::Reference::getOrCreateAttachedDynamicLight;
			usertypeDefinition["setActionFlag"] = &TES3::Reference::setActionFlag;
			usertypeDefinition["testActionFlag"] = &TES3::Reference::testActionFlag;
			usertypeDefinition["updateEquipment"] = &TES3::Reference::updateBipedParts;

			// Functions exposed as properties.
			usertypeDefinition["activationReference"] = sol::property(&TES3::Reference::getActionReference, &TES3::Reference::setActionReference);
			usertypeDefinition["attachments"] = sol::readonly_property(&TES3::Reference::getAttachments);
			usertypeDefinition["context"] = sol::readonly_property(&getContext);
			usertypeDefinition["data"] = sol::readonly_property(&TES3::Reference::getLuaTable);
			usertypeDefinition["isEmpty"] = sol::property(&TES3::Reference::getEmptyInventoryFlag, &TES3::Reference::setEmptyInventoryFlag);
			usertypeDefinition["isRespawn"] = sol::readonly_property(&TES3::Reference::isRespawn);
			usertypeDefinition["orientation"] = sol::property([](TES3::Reference& self) { return self.getOrientation(); }, &TES3::Reference::setOrientationFromLua);
			usertypeDefinition["position"] = sol::property([](TES3::Reference& self) { return self.getPosition(); }, &TES3::Reference::setPositionFromLua);

			// Functions for manually syncing the scene graph, for if orientation or position is manually modified.
			usertypeDefinition["updateSceneGraph"] = [](TES3::Reference& self) {
				TES3::Matrix33 tempOutArg;
				self.sceneNode->setLocalRotationMatrix(self.updateSceneMatrix(&tempOutArg));
				self.sceneNode->update();
				self.setObjectModified(true);
			};

			// Quick access to attachment data.
			usertypeDefinition["itemData"] = sol::property(
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
			);
			usertypeDefinition["lockNode"] = sol::property([](TES3::Reference& self) {
				return self.getAttachedLockNode();
			});
			usertypeDefinition["destination"] = sol::property([](TES3::Reference& self) -> TES3::TravelDestination * {
				TES3::TravelDestinationAttachment * attachment = static_cast<TES3::TravelDestinationAttachment*>(self.getAttachment(TES3::AttachmentType::TravelDestination));
				if (attachment) {
					return attachment->data;
				}
				return nullptr;
			});
			usertypeDefinition["light"] = sol::property([](TES3::Reference& self) -> NI::Pointer<NI::Light> {
				auto attachment = static_cast<TES3::LightAttachment*>(self.getAttachment(TES3::AttachmentType::Light));
				if (attachment) {
					return attachment->data->light;
				}
				return nullptr;
			});
			usertypeDefinition["mobile"] = sol::property([](TES3::Reference& self) {
				return self.getAttachedMobileActor();
			});
			usertypeDefinition["stackSize"] = sol::property(
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
			);
			
			// Allow references to behave like a linked list node.
			usertypeDefinition["previousNode"] = sol::readonly_property([](TES3::Reference& self) { return self.previousInCollection; });
			usertypeDefinition["nextNode"] = sol::readonly_property([](TES3::Reference& self) { return self.nextInCollection; });
			usertypeDefinition["nodeData"] = sol::readonly_property([](TES3::Reference& self) { return &self; });
		}
	}
}
