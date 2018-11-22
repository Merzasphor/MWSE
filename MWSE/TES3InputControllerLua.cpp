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

			// Binding for DIMOUSESTATE2
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<DIMOUSESTATE2>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("x", &DIMOUSESTATE2::lX);
				usertypeDefinition.set("y", &DIMOUSESTATE2::lY);
				usertypeDefinition.set("z", &DIMOUSESTATE2::lZ);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("buttons", sol::readonly_property([](DIMOUSESTATE2& self) { return std::ref(self.rgbButtons); }));

				// Finish up our usertype.
				state.set_usertype("tes3directInputMouseState", usertypeDefinition);
			}

			// Binding for TES3::InputController
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::InputController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("creationFlags", sol::readonly_property(&TES3::InputController::creationFlags));
				usertypeDefinition.set("mouseState", sol::readonly_property(&TES3::InputController::mouseState));
				usertypeDefinition.set("previousMouseState", sol::readonly_property(&TES3::InputController::previousMouseState));

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("inputMaps", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.inputMaps); }));
				usertypeDefinition.set("keyboardState", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.keyboardState); }));
				usertypeDefinition.set("previousKeyboardState", sol::readonly_property([](TES3::InputController& self) { return std::ref(self.previousKeyboardState); }));

				// Basic function binding.
				usertypeDefinition.set("keybindTest", [](TES3::InputController& self, unsigned int key, sol::optional<unsigned int> transition) {
					return self.keybindTest(key, transition.value_or(TES3::KeyTransition::Down));
				});
				usertypeDefinition.set("isKeyDown", &TES3::InputController::isKeyDown);
				usertypeDefinition.set("isKeyPressedThisFrame", &TES3::InputController::isKeyPressedThisFrame);
				usertypeDefinition.set("isKeyReleasedThisFrame", &TES3::InputController::isKeyReleasedThisFrame);

				// Finish up our usertype.
				state.set_usertype("tes3inputController", usertypeDefinition);
			}
		}
	}
}
