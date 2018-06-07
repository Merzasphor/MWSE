#include "TES3InputControllerLua.h"

#include "sol.hpp"

#include "LuaManager.h"

#include "TES3InputController.h"

namespace mwse {
	namespace lua {
		void bindTES3InputController() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::InputConfig
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::InputConfig>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("code", &TES3::InputConfig::keyCode);
				usertypeDefinition.set("device", &TES3::InputConfig::device);

				// Finish up our usertype.
				state.set_usertype("tes3inputConfig", usertypeDefinition);
			}

			// Binding for TES3::InputController
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::InputController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("creationFlags", sol::readonly_property(&TES3::InputController::creationFlags));

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("inputMaps", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.inputMaps); }));
				usertypeDefinition.set("keyboardState", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.keyboardState); }));
				usertypeDefinition.set("previousKeyboardState", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.previousKeyboardState); }));

				// Basic function binding.
				usertypeDefinition.set("keybindTest", &TES3::InputController::keybindTest);

				// Finish up our usertype.
				state.set_usertype("tes3inputController", usertypeDefinition);
			}
		}
	}
}
