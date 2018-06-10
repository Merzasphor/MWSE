#include "TES3UIBlock.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3UIBlock.h"

namespace mwse {
	namespace lua {
		void bindTES3UIBlock() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::UI::Block>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property bindings.
			usertypeDefinition.set("id", sol::readonly_property(&TES3::UI::Block::id));
			usertypeDefinition.set("name", sol::readonly_property([](TES3::UI::Block& self) { return self.name.cString; }));
			usertypeDefinition.set("parent", sol::readonly_property(&TES3::UI::Block::parent));
			usertypeDefinition.set("tag", sol::readonly_property(&TES3::UI::Block::tag));

			// Finish up our usertype.
			state.set_usertype("tes3uiBlock", usertypeDefinition);
		}
	}
}
