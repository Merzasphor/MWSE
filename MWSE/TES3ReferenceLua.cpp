#include "TES3ReferenceLua.h"

#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "TES3Util.h"

namespace TES3 {
	sol::object Reference::getBaseObject() {
		return mwse::lua::makeLuaObject(baseObject);
	}

	sol::object Reference::getAttachments() {
		if (this->attachments == NULL) {
			return sol::nil;
		}

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

	sol::table Reference::getLuaTable() {
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
		void bindTES3Reference() {
			LuaManager::getInstance().getState().new_usertype<TES3::Reference>("TES3Reference",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"id", sol::readonly_property(&TES3::Reference::getObjectID),
				"objectType", sol::readonly(&TES3::Reference::objectType),

				"position", &TES3::Reference::position,
				"orientation", &TES3::Reference::orientation, // This doesn't seem to actually do anything.

				"isRespawn", sol::readonly_property(&TES3::Reference::isRespawn),

				"attachments", sol::readonly_property(&TES3::Reference::getAttachments),

				"object", sol::readonly_property(&TES3::Reference::getBaseObject),

				"activationReference", sol::property(&TES3::Reference::getActivationReference, &TES3::Reference::setActivationReference),

				"data", sol::readonly_property(&TES3::Reference::getLuaTable),

				//
				// Functions
				//

				"activate", &TES3::Reference::activate,
				"setActivationFlag", &TES3::Reference::setActivationFlag,
				"clearActivationFlag", &TES3::Reference::clearActivationFlag,
				"testActivationFlag", &TES3::Reference::testActivationFlag

				);
		}
	}
}
