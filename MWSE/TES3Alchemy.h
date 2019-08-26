#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"
#include "TES3MagicEffect.h"

#include "sol_forward.hpp"

namespace TES3 {
	namespace AlchemyFlag {
		typedef unsigned short value_type;

		enum Flag : value_type {
			AutoCalc = 0x1
		};
	}

	struct Alchemy : Item {
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char * name; // 0x44
		Script * script; // 0x48
		char * model; // 0x4C
		char * icon; // 0x50
		float weight; // 0x54
		unsigned short value; // 0x58
		Effect effects[8]; // 0x5C
		mwse::bitset16 flags; // 0x011C

		//
		// Custom functions.
		//

		size_t getActiveEffectCount();
		int getFirstIndexOfEffect(int effectId);
		bool effectsMatchWith(Alchemy * other);

	};
	static_assert(sizeof(Alchemy) == 0x120, "TES3::Alchemy failed size validation");
}

