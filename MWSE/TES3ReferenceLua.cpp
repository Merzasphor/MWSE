#include "TES3ReferenceLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"
#include "TES3ScriptLua.h"

#include "TES3Util.h"

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
		// We want to provide position as a lie, and do some things under the hood when people try to change a
		// reference's position.
		class ReferencePosition {
		public:
			ReferencePosition(TES3::Reference* _reference) {
				reference = _reference;
			}

			TES3::Reference* reference;
		};

		sol::object getContext(TES3::Reference* reference) {
			auto variables = tes3::getAttachedItemDataNode(reference);
			if (variables == NULL) {
				return sol::nil;
			}
			sol::state& state = mwse::lua::LuaManager::getInstance().getState();
			return sol::make_object(state, std::shared_ptr<ScriptContext>(new ScriptContext(variables->script, variables->scriptData)));
		}

		void bindTES3Reference() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<ReferencePosition>("MWSEReferencePosition",
				// Disable construction of this type.
				"new", sol::no_constructor,

				"x", sol::property(
					[](ReferencePosition& self) { return self.reference->sceneNode->localTranslate.x; },
					[](ReferencePosition& self, double value)
			{
				self.reference->sceneNode->localTranslate.x = value;
				self.reference->sceneNode->propagatePositionChange();
				self.reference->position.x = value;
			}
					),

				"y", sol::property(
					[](ReferencePosition& self) { return self.reference->sceneNode->localTranslate.y; },
					[](ReferencePosition& self, double value)
			{
				self.reference->sceneNode->localTranslate.y = value;
				self.reference->sceneNode->propagatePositionChange();
				self.reference->position.y = value;
			}
					),

				"z", sol::property(
					[](ReferencePosition& self) { return self.reference->sceneNode->localTranslate.z; },
					[](ReferencePosition& self, double value)
			{
				self.reference->sceneNode->localTranslate.z = value;
				self.reference->sceneNode->propagatePositionChange();
				self.reference->position.z = value;
			}
					)
				);

			state.new_usertype<TES3::Reference>("TES3Reference",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties: Reference
				//

				"id", sol::readonly_property(&TES3::Reference::getObjectID),
				"objectType", sol::readonly(&TES3::Reference::objectType),

				"sceneNode", sol::readonly_property([](TES3::Reference& self) { return makeLuaObject(self.sceneNode); }),

				// Position is complicated, we need to wrap it in a structure.
				"position", sol::property([](TES3::Reference& self) { return std::make_unique<ReferencePosition>(&self); }
					),
				//"orientation", &TES3::Reference::orientation,

				"isRespawn", sol::readonly_property(&TES3::Reference::isRespawn),

				"attachments", sol::readonly_property(&TES3::Reference::getAttachments),
				"context", sol::readonly_property([](TES3::Reference& self) { return getContext(&self); }),

				"object", sol::readonly_property(&TES3::Reference::getBaseObject),

				"activationReference", sol::property(&TES3::Reference::getActionReference, &TES3::Reference::setActionReference),

				"data", sol::readonly_property(&TES3::Reference::getLuaTable),

				//
				// Properties: Behave as a linked list node.
				//

				"previousNode", sol::readonly_property([](TES3::Reference& self) { return reinterpret_cast<TES3::Reference*>(self.previousInCollection); }),
				"nextNode", sol::readonly_property([](TES3::Reference& self) { return reinterpret_cast<TES3::Reference*>(self.nextInCollection); }),
				"nodeData", sol::readonly_property([](TES3::Reference& self) { return &self; }),

				//
				// Properties: Quick access to attachment data.
				//

				"stackSize", sol::property(
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
					),

				//
				// Functions
				//

				"activate", [](TES3::Reference& self, TES3::Reference& target) { target.activate(&self); },
				"setActionFlag", &TES3::Reference::setActionFlag,
				"clearActionFlag", &TES3::Reference::clearActionFlag,
				"testActionFlag", &TES3::Reference::testActionFlag

				);
		}
	}
}
