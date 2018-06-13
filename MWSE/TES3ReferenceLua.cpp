#include "TES3ReferenceLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"
#include "TES3ScriptLua.h"

#include "TES3Util.h"

#include "NINode.h"

#include "TES3Cell.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace TES3 {
	sol::object Reference::getBaseObject() {
		return mwse::lua::makeLuaObject(baseObject);
	}

	sol::object Reference::getAttachments() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();

		Attachment* attachment = this->attachments;
		while (attachment) {
			switch (attachment->type) {
			case AttachmentType::Lock:
				result["lock"] = sol::make_object(state, reinterpret_cast<LockAttachment*>(attachment)->data);
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

	sol::table& Reference::getLuaTable() {
		// Get previous attachment.
		LuaTableAttachment* attachment = reinterpret_cast<LuaTableAttachment*>(attachments);
		while (attachment && attachment->type != AttachmentType::LuaTable) {
			attachment = reinterpret_cast<LuaTableAttachment*>(attachment->next);
		}

		// Create the attachment if it needs to be made.
		if (attachment == NULL) {
			// We need to ensure that our default sol::table is initialized, so ensure that new is invoked.
			attachment = new (mwse::tes3::malloc<LuaTableAttachment>()) LuaTableAttachment();

			attachment->type = AttachmentType::LuaTable;
			attachment->next = 0;

			// Set this as the first attachment...
			if (attachments == NULL) {
				attachments = attachment;
			}
			// ... or link up the attachment.
			else {
				auto lastAttachment = attachments;
				while (lastAttachment->next) {
					lastAttachment = lastAttachment->next;
				}
				lastAttachment->next = attachment;
			}

			// Create our empty table.
			sol::state& state = mwse::lua::LuaManager::getInstance().getState();
			attachment->table = state.create_table();
		}

		return attachment->table;
	}
}

namespace mwse {
	namespace lua {
		sol::object getContext(TES3::Reference* reference) {
			auto variables = tes3::getAttachedItemDataNode(reference);
			if (variables == NULL) {
				return sol::nil;
			}
			sol::state& state = mwse::lua::LuaManager::getInstance().getState();
			return sol::make_object(state, std::shared_ptr<ScriptContext>(new ScriptContext(variables->script, variables->scriptData)));
		}

		void bindTES3Reference() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Reference>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Object, TES3::BaseObject>());

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Reference::getObjectID);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("cell", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.owningCollection.asReferenceList != NULL ? self.owningCollection.asReferenceList->cell : NULL); }));
			usertypeDefinition.set("object", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.baseObject); }));
			usertypeDefinition.set("sceneNode", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.sceneNode); }));

			// Basic function binding.
			usertypeDefinition.set("activate", [](TES3::Reference& self, TES3::Reference& target) { target.activate(&self); });
			usertypeDefinition.set("setActionFlag", &TES3::Reference::setActionFlag);
			usertypeDefinition.set("clearActionFlag", &TES3::Reference::clearActionFlag);
			usertypeDefinition.set("testActionFlag", &TES3::Reference::testActionFlag);

			// Functions exposed as properties.
			usertypeDefinition.set("activationReference", sol::property(&TES3::Reference::getActionReference, &TES3::Reference::setActionReference));
			usertypeDefinition.set("attachments", sol::readonly_property(&TES3::Reference::getAttachments));
			usertypeDefinition.set("context", sol::readonly_property([](TES3::Reference& self) { return getContext(&self); }));
			usertypeDefinition.set("data", sol::readonly_property(&TES3::Reference::getLuaTable));
			usertypeDefinition.set("isRespawn", sol::readonly_property(&TES3::Reference::isRespawn));
			usertypeDefinition.set("position", sol::property([](TES3::Reference& self) { return &self.position; }, &TES3::Reference::setPositionFromLua));

			// Quick access to attachment data.
			usertypeDefinition.set("stackSize", sol::property(
				[](TES3::Reference& self)
			{
				TES3::ItemData* itemData = tes3::getAttachedItemDataNode(&self);
				return itemData ? itemData->count : 1;
			},
				[](TES3::Reference& self, double count)
			{
				TES3::ItemData* itemData = tes3::getOrCreateAttachedItemDataNode(&self);
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
