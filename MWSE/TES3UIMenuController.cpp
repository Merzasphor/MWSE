#include "TES3UIMenuController.h"

namespace TES3 {
	namespace UI {
		const auto TES3_ui_resetBufferedInput = reinterpret_cast<void(__thiscall*)(MenuInputController *)>(0x58E9C0);
		void MenuInputController::acquireTextInput(Element* element) {
			// Set target for buffered text input
			textInputFocus = element;
			// Reset text buffer to avoid previous input appearing immediately
			TES3_ui_resetBufferedInput(this);
		}

		const auto TES3_MenuController_setInventoryMenuEnabled = reinterpret_cast<void(__thiscall*)(MenuController *, bool)>(0x5968D0);
		void MenuController::setInventoryMenuEnabled(bool enabled) {
			TES3_MenuController_setInventoryMenuEnabled(this, enabled);
		}

		const auto TES3_MenuController_setMagicMenuEnabled = reinterpret_cast<void(__thiscall*)(MenuController *, bool)>(0x596A90);
		void MenuController::setMagicMenuEnabled(bool enabled) {
			TES3_MenuController_setMagicMenuEnabled(this, enabled);
		}

		const auto TES3_MenuController_setMapMenuEnabled = reinterpret_cast<void(__thiscall*)(MenuController *, bool)>(0x596B70);
		void MenuController::setMapMenuEnabled(bool enabled) {
			TES3_MenuController_setMapMenuEnabled(this, enabled);
		}

		const auto TES3_MenuController_setStatsMenuEnabled = reinterpret_cast<void(__thiscall*)(MenuController *, bool)>(0x5969B0);
		void MenuController::setStatsMenuEnabled(bool enabled) {
			TES3_MenuController_setStatsMenuEnabled(this, enabled);
		}

		bool MenuController::getInventoryMenuEnabled() {
			return inventoryMenuEnabled;
		}

		bool MenuController::getMagicMenuEnabled() {
			return magicMenuEnabled;
		}

		bool MenuController::getMapMenuEnabled() {
			return mapMenuEnabled;
		}

		bool MenuController::getStatsMenuEnabled() {
			return statsMenuEnabled;
		}
	}
}