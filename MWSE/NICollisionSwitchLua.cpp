#include "NISwitchNodeLua.h"

#include "NINodeLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDefines.h"
#include "NICollisionSwitch.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNICollisionSwitch() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::CollisionSwitch>();
			usertypeDefinition.set("new", []() {
				return NI::Pointer<NI::CollisionSwitch>(new NI::CollisionSwitch());
			});

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Node, NI::AVObject, NI::ObjectNET, NI::Object>());
			setUserdataForNINode(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("collisionActive", sol::property(&NI::CollisionSwitch::getCollisionActive, &NI::CollisionSwitch::setCollisionActive));

			// Finish up our usertype.
			state.set_usertype("niCollisionSwitch", usertypeDefinition);
		}
	}
}
