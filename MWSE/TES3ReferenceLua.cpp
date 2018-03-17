#include "TES3ReferenceLua.h"

#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3Reference() {
			LuaManager::getInstance().getState().new_usertype<TES3::Reference>("TES3Reference",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", sol::readonly(&TES3::Reference::objectType),

				"position", &TES3::Reference::position,
				"orientation", &TES3::Reference::orientation, // This doesn't seem to actually do anything.

				"isRespawn", sol::readonly_property(&TES3::Reference::isRespawn),

				//
				// Functions.
				//

				"of", [](TES3::Reference* self) { return makeLuaObject(self->baseObject); }

				);
		}
	}
}
