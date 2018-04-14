#include "TES3MoonLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Moon() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Moon>("TES3Moon",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"weatherController", &TES3::Moon::weatherController,

				"texture", sol::readonly_property(&TES3::Moon::texture),

				"isRed", &TES3::Moon::moonIsRed,
				"phase", &TES3::Moon::phase

				);
		}
	}
}
