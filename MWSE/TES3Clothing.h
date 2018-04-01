#pragma once

#include "TES3Item.h"
#include "TES3WearablePart.h"

namespace TES3 {
	namespace ClothingSlot {
		enum ClothingSlot {
			Pants = 0x0,
			Shoes = 0x1,
			Shirt = 0x2,
			Belt = 0x3,
			Robe = 0x4,
			RightGlove = 0x5,
			LeftGlove = 0x6,
			Skirt = 0x7,
			Ring = 0x8,
			Amulet = 0x9
		};
	}

	struct Clothing : Item {
		WearablePart parts[7];  // 0x54
		unsigned int slot; // 0xA8
		float weight; // 0xAC
		short value; // 0xB0
		short enchantCapacity; // 0xB2
		Enchantment * enchantment; // 0xB4
	};
	static_assert(sizeof(Clothing) == 0xB8, "TES3::Clothing failed size validation");
}
