#include "NINodeLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"
#include "NIRTTI.h"

#include "TES3Collections.h"

namespace mwse {
	namespace lua {
		void bindNINode() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::TArray<NI::AVObject>.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::TArray<NI::AVObject>>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set(sol::meta_function::index, [](TES3::TArray<NI::AVObject>& self, int index) { return makeLuaObject(self.storage[index - 1]); });
				usertypeDefinition.set(sol::meta_function::length, [](TES3::TArray<NI::AVObject>& self) { return self.filledCount; });

				// Finish up our usertype.
				state.set_usertype("niAVObjectTArray", usertypeDefinition);
			}

			// Binding for NI::Node.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::Node>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>());

				// Basic property binding.
				usertypeDefinition.set("children", &NI::Node::children);

				// Finish up our usertype.
				state.set_usertype("niNode", usertypeDefinition);
			}
		}
	}
}
