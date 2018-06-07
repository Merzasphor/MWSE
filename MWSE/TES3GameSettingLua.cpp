#include "TES3GameSettingLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Util.h"

#include "TES3GameSetting.h"

namespace mwse {
	namespace lua {
		sol::object getDefaultValue(TES3::GameSetting& gmst) {
			sol::state& state = LuaManager::getInstance().getState();

			switch (gmst.getType()) {
			case 'i': return sol::make_object(state, (double)gmst.getDefaultIntValue());
			case 'f': return sol::make_object(state, (double)gmst.getDefaultFloatValue());
			case 's': return sol::make_object(state, gmst.getDefaultStringValue());
			}

			return sol::nil;
		}

		sol::object getValue(TES3::GameSetting& gmst) {
			sol::state& state = LuaManager::getInstance().getState();

			switch (gmst.getType()) {
			case 'i': return sol::make_object(state, (double)gmst.value.asLong);
			case 'f': return sol::make_object(state, (double)gmst.value.asFloat);
			case 's': return sol::make_object(state, gmst.value.asString);
			}

			return sol::nil;
		}

		void setValue(TES3::GameSetting& gmst, sol::object value) {
			char type = gmst.getType();
			if (type == 's' && value.is<std::string>()) {
				tes3::setDataString(&gmst.value.asString, value.as<std::string>().c_str());
			}
			else if (value.is<double>()) {
				if (type == 'i') {
					gmst.value.asLong = value.as<double>();
				}
				else if (type == 'f') {
					gmst.value.asFloat = value.as<double>();
				}
			}
		}

		void bindTES3GameSetting() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::GameSetting>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

			// Basic property binding.
			usertypeDefinition.set("index", sol::readonly_property(&TES3::GameSetting::index));

			// Override the default BaseObject bindings to return the GMST's name.
			usertypeDefinition.set("id", sol::readonly_property(&TES3::GameSetting::getName));
			usertypeDefinition.set(sol::meta_function::to_string, sol::readonly_property(&TES3::GameSetting::getName));

			// Functions exposed as properties.
			usertypeDefinition.set("defaultValue", sol::readonly_property(&getDefaultValue));
			usertypeDefinition.set("type", sol::readonly_property(&TES3::GameSetting::getType));
			usertypeDefinition.set("value", sol::property(&getValue, &setValue));

			// Finish up our usertype.
			state.set_usertype("tes3gameSetting", usertypeDefinition);
		}
	}
}
