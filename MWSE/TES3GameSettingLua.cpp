#include "TES3GameLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

#include "TES3Util.h"

namespace mwse {
	namespace lua {
		void bindTES3GameSetting() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::GameSetting>("TES3GameSetting",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", sol::readonly_property(&TES3::GameSetting::objectType),
				"objectFlags", sol::readonly_property(&TES3::GameSetting::objectFlags),

				"index", sol::readonly_property(&TES3::GameSetting::index),
				"name", sol::readonly_property([](TES3::GameSetting& self) { return tes3::getGMSTInfo(self.index)->name; }),
				"value", sol::property(
					[](TES3::GameSetting& self) -> sol::object
			{
				sol::state& state = LuaManager::getInstance().getState();

				char type = *tes3::getGMSTInfo(self.index)->name;
				switch (type) {
				case 'i': return sol::make_object(state, (double)self.value.asLong);
				case 'f': return sol::make_object(state, (double)self.value.asFloat);
				case 's': return sol::make_object(state, self.value.asString);
				}
				return sol::nil;
			},
					[](TES3::GameSetting& self, sol::object value)
			{
				char type = *tes3::getGMSTInfo(self.index)->name;
				if (type == 's' && value.is<std::string>()) {
					tes3::setDataString(&self.value.asString, value.as<std::string>().c_str());
				}
				else if (value.is<double>()) {
					if (type == 'i') {
						self.value.asLong = value.as<double>();
					} else if (type == 'f') {
						self.value.asFloat = value.as<double>();
					}
				}
			}
					),
				"type", sol::readonly_property([](TES3::GameSetting& self) { return *tes3::getGMSTInfo(self.index)->name; })

				);
		}
	}
}
