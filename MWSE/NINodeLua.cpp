#include "NINodeLua.h"

#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"
#include "NIRTTI.h"

#include "TES3Collections.h"

#include "TES3CollectionsLua.h"

namespace mwse {
	namespace lua {
		void bindNINode() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::TArray<NI::AVObject>.
			bindGenericObjectTArray<NI::AVObject>("niAVObjectTArray");

			// Binding for NI::Node.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::Node>();
				usertypeDefinition.set("new", []() {
					return NI::Pointer<NI::Node>(new (tes3::_new<NI::Node>()) NI::Node());
				});

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>());
				setUserdataForNINode(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niNode", usertypeDefinition);
			}
		}
	}
}
