#include "TES3InputControllerLua.h"

#include "LuaManager.h"

#include "TES3InputController.h"

namespace mwse {
	namespace lua {
		void bindTES3InputController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::InputConfig
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::InputConfig>("tes3inputConfig");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["code"] = &TES3::InputConfig::keyCode;
				usertypeDefinition["device"] = &TES3::InputConfig::device;
			}

			// Binding for DIMOUSESTATE2
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<DIMOUSESTATE2>("tes3directInputMouseState");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["x"] = &DIMOUSESTATE2::lX;
				usertypeDefinition["y"] = &DIMOUSESTATE2::lY;
				usertypeDefinition["z"] = &DIMOUSESTATE2::lZ;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["buttons"] = sol::readonly_property([](DIMOUSESTATE2& self) { return std::ref(self.rgbButtons); });
			}

			// Binding for TES3::InputController
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::InputController>("tes3inputController");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["creationFlags"] = sol::readonly_property(&TES3::InputController::creationFlags);
				usertypeDefinition["mouseState"] = sol::readonly_property(&TES3::InputController::mouseState);
				usertypeDefinition["previousMouseState"] = sol::readonly_property(&TES3::InputController::previousMouseState);

				// Indirect bindings to unions and arrays.
				usertypeDefinition["inputMaps"] = sol::readonly_property([](TES3::InputController& self) { return std::ref(self.inputMaps); });
				usertypeDefinition["keyboardState"] = sol::readonly_property([](TES3::InputController& self) { return std::ref(self.keyboardState); });
				usertypeDefinition["previousKeyboardState"] = sol::readonly_property([](TES3::InputController& self) { return std::ref(self.previousKeyboardState); });

				// Basic function binding.
				usertypeDefinition["keybindTest"] = [](TES3::InputController& self, unsigned int key, sol::optional<unsigned int> transition) {
					return self.keybindTest(key, transition.value_or(TES3::KeyTransition::Down));
				};
				usertypeDefinition["isKeyDown"] = &TES3::InputController::isKeyDown;
				usertypeDefinition["isKeyPressedThisFrame"] = &TES3::InputController::isKeyPressedThisFrame;
				usertypeDefinition["isKeyReleasedThisFrame"] = &TES3::InputController::isKeyReleasedThisFrame;
				usertypeDefinition["isMouseButtonDown"] = &TES3::InputController::isMouseButtonDown;
				usertypeDefinition["isMouseButtonPressedThisFrame"] = &TES3::InputController::isMouseButtonPressedThisFrame;
				usertypeDefinition["isMouseButtonReleasedThisFrame"] = &TES3::InputController::isMouseButtonReleasedThisFrame;
			}
		}
	}
}
