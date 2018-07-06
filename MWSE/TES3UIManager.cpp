#include "TES3UIBlock.h"
#include "TES3UIManager.h"
#include "TES3UIMenuController.h"
#include "TES3Util.h"
#include "TES3WorldController.h"

namespace TES3 {
	namespace UI {
		const auto TES3_ui_registerID = reinterpret_cast<UI_ID (__cdecl *)(const char *)>(0x58DF10);
		const auto TES3_ui_createMenu = reinterpret_cast<Block* (__cdecl *)(UI_ID)>(0x595400);
		const auto TES3_ui_findMenu = reinterpret_cast<Block* (__cdecl*)(UI_ID)>(0x595370);
		const auto TES3_ui_requestMenuModeOn = reinterpret_cast<Boolean (__cdecl*)(UI_ID)>(0x595230);
		const auto TES3_ui_requestMenuModeOff = reinterpret_cast<Boolean (__cdecl*)(UI_ID)>(0x595270);
		const auto TES3_ui_onMenuUnfocus = reinterpret_cast<EventCallback>(0x58F790);

		UI_ID registerID(const char *name) {
			return TES3_ui_registerID(name);
		}

		Property registerProperty(const char *name) {
			return static_cast<Property>(TES3_ui_registerID(name));
		}

		Block* createMenu(UI_ID id) {
			return TES3_ui_createMenu(id);
		}

		Block* findMenu(UI_ID id) {
			return TES3_ui_findMenu(id);
		}

		Boolean enterMenuMode(UI_ID id) {
			return TES3_ui_requestMenuModeOn(id);
		}

		Boolean leaveMenuMode() {
			return TES3_ui_requestMenuModeOff(0);
		}

		void acquireTextInput(Block* block) {
			MenuController *menuController = static_cast<MenuController*>(mwse::tes3::getWorldController()->menuController);
			menuController->menuInputController->acquireTextInput(block);
		}

		void preventInventoryMenuToggle(Block* menu) {
			menu->setProperty(Property::event_unfocus, TES3_ui_onMenuUnfocus);
		}
	}
}
