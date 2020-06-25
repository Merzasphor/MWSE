#include "TES3GameSettingLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3GameSetting.h"

namespace mwse {
	namespace lua {
		sol::object getDefaultValue(TES3::GameSetting& gmst) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			switch (gmst.getType()) {
			case 'i': return sol::make_object(state, (double)gmst.getDefaultIntValue());
			case 'f': return sol::make_object(state, (double)gmst.getDefaultFloatValue());
			case 's': return sol::make_object(state, gmst.getDefaultStringValue());
			}

			return sol::nil;
		}

		sol::object getValue(TES3::GameSetting& gmst) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			switch (gmst.getType()) {
			case 'i': return sol::make_object(state, (double)gmst.value.asLong);
			case 'f': return sol::make_object(state, (double)gmst.value.asFloat);
			case 's': return sol::make_object(state, gmst.value.asString);
			}

			return sol::nil;
		}

		void setValue(TES3::GameSetting& gmst, sol::object value) {
			auto& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::GameSetting>("tes3gameSetting");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
			setUserdataForTES3BaseObject(usertypeDefinition);

			// Base class overrides.
			usertypeDefinition[sol::meta_function::to_string] = &TES3::GameSetting::getObjectID;
			usertypeDefinition["id"] = sol::readonly_property(&TES3::GameSetting::getObjectID);

			// Allow object to be serialized to json.
			usertypeDefinition["__tojson"] = &TES3::GameSetting::toJson;

			// Basic property binding.
			usertypeDefinition["index"] = sol::readonly_property(&TES3::GameSetting::index);

			// Functions exposed as properties.
			usertypeDefinition["defaultValue"] = sol::readonly_property(&getDefaultValue);
			usertypeDefinition["type"] = sol::readonly_property(&TES3::GameSetting::getType);
			usertypeDefinition["value"] = sol::property(&getValue, &setValue);
		}
	}
}
