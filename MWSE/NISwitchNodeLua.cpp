#include "NISwitchNode.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDefines.h"
#include "NINode.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNISwitchNode() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::SwitchNode>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Node, NI::AVObject, NI::ObjectNET, NI::Object>());

			// Basic property binding.
			usertypeDefinition.set("switchIndex", &NI::SwitchNode::switchIndex);

			// Finish up our usertype.
			state.set_usertype("niSwitchNode", usertypeDefinition);
		}
	}
}
