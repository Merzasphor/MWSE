#include "TES3RegionLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Region() {
			LuaManager::getInstance().getState().new_usertype<TES3::Region>("TES3Region",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				sol::meta_function::to_string, &TES3::Region::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Region::objectType,

				"id", sol::readonly_property(&TES3::Region::getObjectID),
				"name", sol::property([](TES3::Region& self) { return self.name; }),

				"weatherChanceClear", &TES3::Region::weatherChanceClear,
				"weatherChanceCloudy", &TES3::Region::weatherChanceCloudy,
				"weatherChanceFoggy", &TES3::Region::weatherChanceFoggy,
				"weatherChanceOvercast", &TES3::Region::weatherChanceOvercast,
				"weatherChanceRain", &TES3::Region::weatherChanceRain,
				"weatherChanceThunder", &TES3::Region::weatherChanceThunder,
				"weatherChanceAsh", &TES3::Region::weatherChanceAsh,
				"weatherChanceBlight", &TES3::Region::weatherChanceBlight,
				"weatherChanceSnow", &TES3::Region::weatherChanceSnow,
				"weatherChanceBlizzard", &TES3::Region::weatherChanceBlizzard,

				"sleepCreature", sol::readonly_property([](TES3::Region& self) { return makeLuaObject(self.sleepCreature); }),

				//
				// Functions.
				//

				"changeWeather", &TES3::Region::changeWeather

				);
		}
	}
}
