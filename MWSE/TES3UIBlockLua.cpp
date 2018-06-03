#include "TES3UIBlock.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3UIBlock.h"

namespace mwse {
	namespace lua {
		void bindTES3UIBlock() {
			LuaManager::getInstance().getState().new_usertype<TES3::UI::Block>("TES3UIBlock",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"tag", sol::readonly_property(&TES3::UI::Block::tag),

				"id", sol::readonly_property(&TES3::UI::Block::id),
				"name", sol::readonly_property([](TES3::UI::Block& self) { return self.name.cString; }),

				"parent", sol::readonly_property(&TES3::UI::Block::parent)

				);
		}
	}
}
