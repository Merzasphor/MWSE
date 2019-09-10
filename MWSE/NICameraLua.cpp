#include "NICameraLua.h"

#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NICamera.h"
#include "NINode.h"
#include "NIRTTI.h"

#include "TES3Vectors.h"

namespace mwse {
	namespace lua {
		void bindNICamera() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::Camera>("niCamera");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>();
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["lodAdjust"] = &NI::Camera::LODAdjust;
			usertypeDefinition["port"] = &NI::Camera::port;
			usertypeDefinition["viewDistance"] = &NI::Camera::viewDistance;
			usertypeDefinition["worldDirection"] = &NI::Camera::worldDirection;
			usertypeDefinition["worldRight"] = &NI::Camera::worldRight;
			usertypeDefinition["worldUp"] = &NI::Camera::worldUp;

			// Access to other objects that need to be packaged.
			usertypeDefinition["renderer"] = sol::readonly_property([](NI::Camera& self) { return makeLuaObject(self.renderer); });
			usertypeDefinition["scene"] = sol::readonly_property([](NI::Camera& self) { return makeLuaObject(self.scene); });
		}
	}
}
