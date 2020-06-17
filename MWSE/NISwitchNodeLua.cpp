#include "NISwitchNode.h"

#include "NINodeLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDefines.h"
#include "NINode.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNISwitchNode() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::SwitchNode>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Node, NI::AVObject, NI::ObjectNET, NI::Object>());
			setUserdataForNINode(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("switchIndex", sol::property(
				[](NI::SwitchNode& self) { return self.switchIndex; },
				[](NI::SwitchNode& self, int index) {
					if (index < 0 || self.children[index] == nullptr) {
						throw std::exception("Attempted to set switchIndex beyond bounds!");
					}
					self.switchIndex = index;
				}));

			// Finish up our usertype.
			state.set_usertype("niSwitchNode", usertypeDefinition);
		}
	}
}
