#pragma once

#include "TES3Defines.h"

namespace mwse::tes3::ui {
	bool requestMenuModeOff();
	bool requestMenuModeOn(short prop = 0);

	int getButtonPressedIndex();
	void resetButtonPressedIndex();

	TES3::UI::Element* getMenuNode(short);
	short getInventoryMenuId();

	TES3::UI::InventoryTile* inventoryAddTile(int, TES3::UI::InventoryTile*);
	void inventoryUpdateIcons();
	bool equipInventoryTile(TES3::UI::InventoryTile*);
	bool equipInventoryItem(TES3::PhysicalObject*, TES3::ItemData*);
	void flagPaperDollUpdate();

	void showRestWaitMenu(bool allowRest, bool scripted = true);
}
