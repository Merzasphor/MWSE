#include "TES3ClassLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace TES3 {
	sol::table Class::getAttributes() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		result[1] = &attributes[0];
		result[2] = &attributes[1];
		return result;
	}

	sol::table Class::getMajorSkills() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		for (int i = 0; i < 5; i++) {
			result[i + 1] = &skills[i * 2];
		}
		return result;
	}

	sol::table Class::getMinorSkills() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table();
		for (int i = 0; i < 5; i++) {
			result[i + 1] = &skills[i * 2 + 1];
		}
		return result;
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Class() {
			LuaManager::getInstance().getState().new_usertype<TES3::Class>("TES3Class",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::meta_function::to_string, &TES3::Class::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Class::objectType,

				"id", sol::readonly_property(&TES3::Class::getObjectID),
				"name", sol::readonly_property(&TES3::Class::getName),

				"specialization", &TES3::Class::specialization,
				"attributes", sol::readonly_property(&TES3::Class::getAttributes),
				"majorSkills", sol::readonly_property(&TES3::Class::getMajorSkills),
				"minorSkills", sol::readonly_property(&TES3::Class::getMinorSkills),

				"services", &TES3::Class::services,

				"playable", &TES3::Class::playable

				);
		}
	}
}
