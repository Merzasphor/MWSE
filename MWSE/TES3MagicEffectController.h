#pragma once

#include <unordered_map>

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3MagicEffect.h"

namespace TES3 {
#define MAX_EFFECT_COUNT SHRT_MAX

	class MagicEffectController {
	public:
		MagicEffectController();
		~MagicEffectController();

		// MagicEffect object functions.
		MagicEffect* getEffectObject(int id);
		void addEffectObject(MagicEffect* effect);

		const char * getEffectName(int id);

		// Flag manipulation.
		static unsigned int getEffectFlags(int id);
		static void setEffectFlags(int id, unsigned int flags);
		static bool getEffectFlag(int id, EffectFlag::Flag flag);
		static void setEffectFlag(int id, EffectFlag::Flag flag, bool value);

		static void InstallCustomMagicEffectController();

		// Implemented.
		std::unordered_map<int, MagicEffect*> effectObjects;
		std::unordered_map<int, sol::protected_function> effectLuaTickFunctions;
		std::unordered_map<int, std::string> effectCustomNames;

		// Unimplemented.
		static unsigned int effectNameGMSTs[MAX_EFFECT_COUNT];
		static unsigned int effectFlags[MAX_EFFECT_COUNT];
		static unsigned int effectCounters[MAX_EFFECT_COUNT][5];
	};
}
