#include "TES3LightLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Light() {
			LuaManager::getInstance().getState().new_usertype<TES3::Light>("TES3Light",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::meta_function::to_string, &TES3::Light::getObjectID,

				//
				// Properties.
				//

				"objectType", &TES3::Light::objectType,

				"boundingBox", &TES3::Light::boundingBox,

				"id", sol::readonly_property(&TES3::Light::getObjectID),
				"name", sol::property(&TES3::Light::getName, &TES3::Light::setName),

				"icon", sol::readonly_property(&TES3::Light::getIconPath),
				"model", sol::readonly_property(&TES3::Light::getModelPath),

				"value", sol::readonly_property(&TES3::Light::getValue),
				"weight", sol::readonly_property(&TES3::Light::getWeight),

				"time", &TES3::Light::time,
				"radius", &TES3::Light::radius,

				"flags", &TES3::Light::flags,
				"canCarry", sol::property(&TES3::Light::getCanCarry, &TES3::Light::setCanCarry),
				"flickers", sol::property(&TES3::Light::getFlickers, &TES3::Light::setFlickers),
				"flickersSlowly", sol::property(&TES3::Light::getFlickersSlowly, &TES3::Light::setFlickersSlowly),
				"isDynamic", sol::property(&TES3::Light::getIsDynamic, &TES3::Light::setIsDynamic),
				"isFire", sol::property(&TES3::Light::getIsFire, &TES3::Light::setIsFire),
				"isNegative", sol::property(&TES3::Light::getIsNegative, &TES3::Light::setIsNegative),
				"isOffByDefault", sol::property(&TES3::Light::getIsOffByDefault, &TES3::Light::setIsOffByDefault),
				"pulses", sol::property(&TES3::Light::getPulses, &TES3::Light::setPulses),
				"pulsesSlowly", sol::property(&TES3::Light::getPulsesSlowly, &TES3::Light::setPulsesSlowly),

				// TODO: Color exposure?

				// TODO: Sound?

				"script", sol::readonly_property(&TES3::Light::getScript)

				);
		}
	}
}
