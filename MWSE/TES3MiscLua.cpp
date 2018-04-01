#include "TES3MiscLua.h"

#include "LuaManager.h"

#include "TES3Misc.h"
#include "TES3Enchantment.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3Misc() {
			LuaManager::getInstance().getState().new_usertype<TES3::Misc>("TES3Misc",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Misc::objectType,

				"id", sol::readonly_property(&TES3::Misc::getObjectID),
				"name", sol::property(&TES3::Misc::getName, &TES3::Misc::setName),

				"icon", sol::readonly_property(&TES3::Misc::getIconPath),
				"model", sol::readonly_property(&TES3::Misc::getModelPath),

				"value", sol::readonly_property(&TES3::Misc::getValue),
				"weight", sol::readonly_property(&TES3::Misc::getWeight),

				"script", sol::readonly_property(&TES3::Misc::getScript)

				);
		}
	}
}
