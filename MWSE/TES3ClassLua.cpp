#include "TES3ClassLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Class.h"

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
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Class>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

			// Basic property binding.
			usertypeDefinition.set("playable", &TES3::Class::playable);
			usertypeDefinition.set("services", &TES3::Class::services);
			usertypeDefinition.set("specialization", &TES3::Class::specialization);

			// Functions exposed as properties.
			usertypeDefinition.set("attributes", sol::readonly_property(&TES3::Class::getAttributes));
			usertypeDefinition.set("majorSkills", sol::readonly_property(&TES3::Class::getMajorSkills));
			usertypeDefinition.set("minorSkills", sol::readonly_property(&TES3::Class::getMinorSkills));
			usertypeDefinition.set("name", sol::readonly_property(&TES3::Class::getName));

			// Finish up our usertype.
			state.set_usertype("tes3class", usertypeDefinition);
		}
	}
}
