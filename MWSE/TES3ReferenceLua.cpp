#include "TES3ReferenceLua.h"

#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"

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
