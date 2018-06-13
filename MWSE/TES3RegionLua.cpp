#include "TES3RegionLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Actor.h"
#include "TES3Region.h"

namespace mwse {
	namespace lua {
		void bindTES3Region() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Region>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition.set(sol::meta_function::to_string, &TES3::Region::getObjectID);

			// Basic property binding.
			usertypeDefinition.set("name", sol::property([](TES3::Region& self) { return self.name; }));
			usertypeDefinition.set("weatherChanceAsh", &TES3::Region::weatherChanceAsh);
			usertypeDefinition.set("weatherChanceBlight", &TES3::Region::weatherChanceBlight);
			usertypeDefinition.set("weatherChanceBlizzard", &TES3::Region::weatherChanceBlizzard);
			usertypeDefinition.set("weatherChanceClear", &TES3::Region::weatherChanceClear);
			usertypeDefinition.set("weatherChanceCloudy", &TES3::Region::weatherChanceCloudy);
			usertypeDefinition.set("weatherChanceFoggy", &TES3::Region::weatherChanceFoggy);
			usertypeDefinition.set("weatherChanceOvercast", &TES3::Region::weatherChanceOvercast);
			usertypeDefinition.set("weatherChanceRain", &TES3::Region::weatherChanceRain);
			usertypeDefinition.set("weatherChanceSnow", &TES3::Region::weatherChanceSnow);
			usertypeDefinition.set("weatherChanceThunder", &TES3::Region::weatherChanceThunder);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("sleepCreature", sol::readonly_property([](TES3::Region& self) { return makeLuaObject(self.sleepCreature); }));

			// Basic function binding.
			usertypeDefinition.set("changeWeather", &TES3::Region::changeWeather);
			usertypeDefinition.set("randomizeWeather", &TES3::Region::randomizeWeather);

			// Finish up our usertype.
			state.set_usertype("tes3region", usertypeDefinition);
		}
	}
}
