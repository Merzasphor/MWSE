#include "TES3InputController.h"

#define TES3_InputController_readKeyState 0x4065E0
#define TES3_InputController_keybindTest 0x406F40

namespace TES3 {
	std::reference_wrapper<BYTE[8]> InputController::DirectInputMouseState::getButtons() {
		return std::ref(rgbButtons);
	}

	void InputController::readKeyState() {
		reinterpret_cast<void(__thiscall *)(InputController*)>(TES3_InputController_readKeyState)(this);
	}

	bool InputController::keybindTest(unsigned int keyBind, unsigned int transition) const {
		return reinterpret_cast<int(__thiscall *)(const InputController*, unsigned int, unsigned int)>(TES3_InputController_keybindTest)(this, keyBind, transition) == 1;
	}

	bool InputController::isKeyDown(unsigned char keyCode) const {
		return keyboardState[keyCode] & 0x80;
	}

	bool InputController::isKeyPressedThisFrame(unsigned char keyCode) const {
		return (keyboardState[keyCode] & 0x80) && !(previousKeyboardState[keyCode] & 0x80);
	}

	bool InputController::isKeyReleasedThisFrame(unsigned char keyCode) const {
		return !(keyboardState[keyCode] & 0x80) && (previousKeyboardState[keyCode] & 0x80);
	}

	bool InputController::isMouseButtonDown(unsigned char button) const {
		return mouseState.rgbButtons[button] & 0x80;
	}

	bool InputController::isMouseButtonPressedThisFrame(unsigned char button) const {
		return (mouseState.rgbButtons[button] & 0x80) && !(previousMouseState.rgbButtons[button] & 0x80);
	}

	bool InputController::isMouseButtonReleasedThisFrame(unsigned char button) const {
		return !(mouseState.rgbButtons[button] & 0x80) && (previousMouseState.rgbButtons[button] & 0x80);
	}

	bool InputController::keybindTest_lua(unsigned int key, sol::optional<unsigned int> transition) const {
		return keybindTest(key, transition.value_or(TES3::KeyTransition::Down));
	}

	std::reference_wrapper<unsigned char[256]> InputController::getKeyboardState() {
		return std::ref(keyboardState);
	}

	std::reference_wrapper<unsigned char[256]> InputController::getPreviousKeyboardState() {
		return std::ref(previousKeyboardState);
	}

	std::reference_wrapper<InputConfig[34]> InputController::getInputConfigs() {
		return std::ref(inputMaps);
	}
}
