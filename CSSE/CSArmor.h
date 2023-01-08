#pragma once

#include "CSPhysicalObject.h"
#include "CSWearablePart.h"

namespace se::cs {
	namespace ArmorSlot {
		typedef unsigned int value_type;

		enum ArmorSlot : value_type {
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

			// Unusued in Morrowind itself, only used for MWSE operations.
			Invalid = 0xFFFFFFFF,

			First = Helmet,
			Last = RightBracer,
		};
	}

	namespace ArmorWeightClass {
		typedef unsigned int value_type;

		enum ArmorWeightClass : value_type {
			Light = 0x0,
			Medium = 0x1,
			Heavy = 0x2,

			First = Light,
			Last = Heavy,
		};
	}

	struct Armor : PhysicalObject {
		char* name; // 0x48
		char* model; // 0x4C
		Script* script; // 0x50
		char* icon; // 0x54
		WearablePart parts[7]; // 0x58
		ArmorSlot::ArmorSlot slot; // 0xAC
		float weight; // 0xB0
		int value; // 0xB4
		int maxCondition; // 0xB8
		int enchantPoints; // 0xBC
		int armorRating; // 0xC0
		Enchantment* enchantment; // 0xC4

		ArmorWeightClass::ArmorWeightClass getWeightClass() const;
		const char* getWeightClassName() const;
	};
	static_assert(sizeof(Armor) == 0xC8, "Armor failed size validation");
}
