#include "TES3CellLua.h"

#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3Region.h"

namespace mwse {
	namespace lua {
		void bindTES3Cell() {
			LuaManager::getInstance().getState().new_usertype<TES3::Cell>("TES3Cell",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Cell::objectType,

				"id", sol::readonly_property(&TES3::Cell::getObjectID),

				"flags", &TES3::Cell::cellFlags,

				"actors", &TES3::Cell::actors,
				"activators", &TES3::Cell::activators,
				"statics", &TES3::Cell::statics,
				"moveReferences", &TES3::Cell::moveReferences,

				"pathGrid", sol::readonly_property(&TES3::Cell::pathGrid),

				"gridX", sol::readonly_property(&TES3::Cell::getGridX),
				"gridY", sol::readonly_property(&TES3::Cell::getGridY),

				"ambientColor", sol::property(&TES3::Cell::getAmbientColor, &TES3::Cell::setAmbientColor),
				"sunColor", sol::property(&TES3::Cell::getSunColor, &TES3::Cell::setSunColor),
				"fogColor", sol::property(&TES3::Cell::getFogColor, &TES3::Cell::setFogColor),
				"fogDensity", sol::property(&TES3::Cell::getFogDensity, &TES3::Cell::setFogDensity),

				"waterLevel", sol::property(&TES3::Cell::getWaterLevel, &TES3::Cell::setWaterLevel),

				"region", sol::readonly_property(&TES3::Cell::getRegion)

				);
		}
	}
}
