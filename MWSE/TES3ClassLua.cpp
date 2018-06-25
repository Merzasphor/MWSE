#include "TES3ClassLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Class.h"

namespace TES3 {
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

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Class::getObjectID);

			// Basic property binding.
			usertypeDefinition.set("services", &TES3::Class::services);
			usertypeDefinition.set("specialization", &TES3::Class::specialization);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("attributes", sol::readonly_property([](TES3::Class& self) { return std::ref(self.attributes); }));
			usertypeDefinition.set("skills", sol::readonly_property([](TES3::Class& self) { return std::ref(self.skills); }));

			// Properties that have type remapping.
			usertypeDefinition.set("playable", sol::property(
				[](TES3::Class& self) { return self.playable != 0; },
				[](TES3::Class& self, bool value) { self.playable = value; }
				));

			// Functions exposed as properties.
			usertypeDefinition.set("majorSkills", sol::readonly_property(&TES3::Class::getMajorSkills));
			usertypeDefinition.set("minorSkills", sol::readonly_property(&TES3::Class::getMinorSkills));
			// Functions exposed as properties.
			usertypeDefinition.set("name", sol::property(
				[](TES3::Class& self) { return self.name; },
				[](TES3::Class& self, const char* value) { if (strlen(value) < 32) strcpy(self.name, value); }
			));

			// Finish up our usertype.
			state.set_usertype("tes3class", usertypeDefinition);
		}
	}
}
