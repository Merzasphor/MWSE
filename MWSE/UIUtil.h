#pragma once

#include "TES3Object.h"

namespace mwse {
	namespace tes3 {
		namespace ui {
			bool requestMenuModeOff();
			bool requestMenuModeOn(short prop = 0);

			TES3::UI::Block* getMenuNode(short);
			short getInventoryMenuId();

			TES3::UI::InventoryTile* inventoryAddTile(int, TES3::UI::InventoryTile*);
			signed char inventoryUpdateIcons();
		}
	}
}
