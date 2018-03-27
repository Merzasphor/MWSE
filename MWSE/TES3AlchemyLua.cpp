#include "TES3AlchemyLua.h"

#include "LuaManager.h"

#include "TES3Alchemy.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Alchemy() {
			LuaManager::getInstance().getState().new_usertype<TES3::Alchemy>("TES3Alchemy",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Alchemy::objectType,

				"id", sol::readonly_property(&TES3::Alchemy::getObjectID),
				"name", sol::property(&TES3::Alchemy::getName, &TES3::Alchemy::setName),

				"icon", sol::readonly_property(&TES3::Alchemy::getIconPath),
				"model", sol::readonly_property(&TES3::Alchemy::getModelPath),

				"flags", sol::readonly(&TES3::Alchemy::flags),
				"autoCalc", sol::property(&TES3::Alchemy::getAutoCalc, &TES3::Alchemy::setAutoCalc),

				"value", sol::readonly_property(&TES3::Alchemy::getValue),
				"weight", sol::readonly_property(&TES3::Alchemy::getWeight),

				"effects", sol::readonly_property([](TES3::Alchemy* self) { return std::ref(self->effects); }),

				"script", sol::readonly_property(&TES3::Alchemy::getScript)

				);
		}
	}
}
