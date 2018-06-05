#pragma once

#include "TES3Defines.h"

namespace TES3 {
	namespace UI {
		struct InventoryTile {
			Item * item; // 0x0
			ItemData * itemData; // 0x4
			void * unknown_0x8;
			int count; // 0xC
			UI::Block * block; // 0x10
			char unknown_0x14;
			char padding_0x15[3];
			unsigned int flags; // 0x18
			char itemId[32]; // 0x1C
			unsigned int tileType; // 0x3C
			unsigned char isBoundItem; // 0x40
		};
		static_assert(sizeof(InventoryTile) == 0x44, "TES3::UI::InventoryTile failed size validation");
	}
}
