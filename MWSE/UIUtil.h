#pragma once

#include "TES3Defines.h"

namespace mwse {
	namespace tes3 {
		namespace ui {
			__declspec(dllexport) TES3::UI::Element* getTopMenu();

			__declspec(dllexport) bool requestMenuModeOff();
			__declspec(dllexport) bool requestMenuModeOn(short prop = 0);

			__declspec(dllexport) int messagePlayer(const char*);
			__declspec(dllexport) int getButtonPressedIndex();
			__declspec(dllexport) void resetButtonPressedIndex();

			__declspec(dllexport) TES3::UI::Element* getMenuNode(short);
			__declspec(dllexport) short getInventoryMenuId();

			__declspec(dllexport) TES3::UI::InventoryTile* inventoryAddTile(int, TES3::UI::InventoryTile*);
			__declspec(dllexport) signed char inventoryUpdateIcons();
			__declspec(dllexport) signed char equipInventoryTile(TES3::UI::InventoryTile*);
			__declspec(dllexport) void flagPaperDollUpdate();

			__declspec(dllexport) void showRestWaitMenu(bool allowRest, bool scripted = true);
		}
	}
}
