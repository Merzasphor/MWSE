#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"
#include "TES3WearablePart.h"

namespace TES3 {
	namespace ArmorSlot {
		enum ArmorSlot {
			Helmet = 0x0,
			Cuirass = 0x1,
			LeftPauldron = 0x2,
			RightPauldron = 0x3,
			Greaves = 0x4,
			Boots = 0x5,
			LeftGauntlet = 0x6,
			RightGauntlet = 0x7,
			Shield = 0x8,
			LeftBracer = 0x9,
			RightBracer = 0xA,
		};
	}

	struct Armor : Item {
		Iterator<void> stolenList; // 0x30
		char * name; // 0x44
		Script * script; // 0x48
		char * model; // 0x4C
		char * icon; // 0x50
		WearablePart parts[7];  // 0x54
		unsigned int slot; // 0xA8
		float weight; // 0xAC
		int value; // 0xB0
		int maxCondition; // 0xB4
		int enchantCapacity; // 0xB8
		int armorRating; // 0xBC
		void * enchantment; // 0xC0

		//
		// Other related this-call functions.
		//

		int getWeightClass();

	};
	static_assert(sizeof(Armor) == 0xC4, "TES3::Armor failed size validation");
}