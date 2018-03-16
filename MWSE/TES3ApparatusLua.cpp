#include "TES3ApparatusLua.h"

#include "LuaManager.h"

#include "TES3Apparatus.h"

namespace mwse {
	namespace lua {
		void bindTES3Apparatus() {
			auto type = LuaManager::getInstance().getState().new_usertype<TES3::Apparatus>("TES3Apparatus",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Apparatus::objectType,
				"type", &TES3::Apparatus::type,
				"quality", &TES3::Apparatus::quality,

				"icon", sol::readonly_property(&TES3::Apparatus::getIcon),

				//
				// Functions.
				//

				"getIcon", [](TES3::Apparatus* self) { return self->vTable->getIconPath(self); }

				);
		}
	}
}
