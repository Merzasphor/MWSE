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
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<NI::Camera>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>());
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("lodAdjust", &NI::Camera::LODAdjust);
			usertypeDefinition.set("port", &NI::Camera::port);
			usertypeDefinition.set("viewDistance", &NI::Camera::viewDistance);
			usertypeDefinition.set("worldDirection", &NI::Camera::worldDirection);
			usertypeDefinition.set("worldRight", &NI::Camera::worldRight);
			usertypeDefinition.set("worldUp", &NI::Camera::worldUp);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("renderer", sol::readonly_property([](NI::Camera& self) { return makeLuaObject(self.renderer); }));
			usertypeDefinition.set("scene", sol::readonly_property([](NI::Camera& self) { return makeLuaObject(self.scene); }));

			// Finish up our usertype.
			state.set_usertype("niCamera", usertypeDefinition);
		}
	}
}
