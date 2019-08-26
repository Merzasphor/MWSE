#pragma once

#include <unordered_map>

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3MagicEffect.h"

namespace TES3 {
#define MAX_EFFECT_COUNT SHRT_MAX

	namespace MagicEffectAttribute {
		typedef unsigned int value_type;

		enum EffectAttribute : value_type {
			AttackBonus = 0,
			Sanctuary = 1,
			ResistMagicka = 2,
			ResistFire = 3,
			ResistFrost = 4,
			ResistShock = 5,
			ResistCommonDisease = 6,
			ResistBlightDisease = 7,
			ResistCorprus = 8,
			ResistPoison = 9,
			ResistParalysis = 10,
			Chameleon = 11,
			ResistNormalWeapons = 12,
			WaterBreathing = 13,
			WaterWalking = 14,
			SwiftSwim = 15,
			Jump = 16,
			Levitate = 17,
			Shield = 18,
			Sound = 19,
			Silence = 20,
			Blind = 21,
			Paralyze = 22,
			Invisibility = 23,
			Fight = 24,
			Flee = 25,
			Hello = 26,
			Alarm = 27,
			NonResistable = 28,
		};
	}

	class MagicEffectController {
	public:
		MagicEffectController();
		~MagicEffectController();

		// MagicEffect object functions.
		MagicEffect* getEffectObject(int id);
		void addEffectObject(MagicEffect* effect);

		const char * getEffectName(int id);

		// Flag manipulation.
		static mwse::bitset32 getEffectFlags(int id);
		static void setEffectFlags(int id, unsigned int flags);
		static bool getEffectFlag(int id, EffectFlag::FlagBit flag);
		static void setEffectFlag(int id, EffectFlag::FlagBit flag, bool value);

		static void InstallCustomMagicEffectController();

		// Implemented.
		std::unordered_map<int, MagicEffect*> effectObjects;
		std::unordered_map<int, sol::protected_function> effectLuaTickFunctions;
		std::unordered_map<int, sol::protected_function> effectLuaCollisionFunctions;
		std::unordered_map<int, std::string> effectCustomNames;

		// Unimplemented.
		static unsigned int effectNameGMSTs[MAX_EFFECT_COUNT];
		static mwse::bitset32 effectFlags[MAX_EFFECT_COUNT];
		static unsigned int effectCounters[MAX_EFFECT_COUNT][5];
	};
}
