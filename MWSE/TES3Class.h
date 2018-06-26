#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"

#include "sol_forward.hpp"

namespace TES3 {
	namespace ServiceFlag {
		enum ServiceFlag {
			BartersWeapons = 0x1,
			BartersArmor = 0x2,
			BartersClothing = 0x4,
			BartersBooks = 0x8,
			BartersIngredients = 0x10,
			BartersLockpicks = 0x20,
			BartersProbes = 0x40,
			BartersLights = 0x80,
			BartersApparatus = 0x100,
			BartersRepairTools = 0x200,
			BartersMiscItems = 0x400,
			OffersSpells = 0x800,
			BartersEnchantedItems = 0x1000,
			BartersAlchemy = 0x2000,
			OffersTraining = 0x4000,
			OffersSpellmaking = 0x8000,
			OffersEnchanting = 0x10000,
			OffersRepairs = 0x20000
		};
	}

	struct Class : BaseObject {
		char id[32]; // 0x10
		char name[32]; // 0x30
		int attributes[2]; // 0x50
		int specialization; // 0x58
		int skills[10]; // 0x5C
		int playable; // 0x84
		unsigned int services; // 0x88
		char * description; // 0x8C
		unsigned int descriptionOffset; // 0x90

		//
		// Virtual table overrides.
		//

		char* getName();

		//
		// Custom functions.
		//

		char * loadDescription();
		void setDescription(const char*);
		void freeDescription();

		bool getServiceFlag(unsigned int);
		void setServiceFlag(unsigned int, bool);

		//
		// Lua-specific interfaces.
		//

		sol::table getMajorSkills();
		sol::table getMinorSkills();

	};
	static_assert(sizeof(Class) == 0x94, "TES3::Class failed size validation");
}
