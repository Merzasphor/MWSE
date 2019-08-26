#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	namespace LightFlags {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Dynamic = 0x1,
			CanCarry = 0x2,
			Negative = 0x4,
			Flicker = 0x8,
			Fire = 0x10,
			OffByDefault = 0x20,
			FlickerSlow = 0x40,
			Pulse = 0x80,
			PulseSlow = 0x100
		};
	}

	struct Light : Item {
		void * animationData;
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char* name; // 0x48
		char* model; // 0x4C
		Script * script;
		char* icon; // 0x54
		float weight; // 0x58
		long value; // 0x5C
		int time; // 0x60
		int radius; // 0x64
		unsigned char color[4]; // 0x68
		mwse::bitset32 flags; // 0x6C
		Sound * sound; // 0x70

		//
		// Functions to get/set flags.
		//

		bool getIsDynamic();
		void setIsDynamic(bool);

		bool getCanCarry();
		void setCanCarry(bool);

		bool getIsNegative();
		void setIsNegative(bool);

		bool getFlickers();
		void setFlickers(bool);

		bool getIsFire();
		void setIsFire(bool);

		bool getIsOffByDefault();
		void setIsOffByDefault(bool);

		bool getFlickersSlowly();
		void setFlickersSlowly(bool);

		bool getPulses();
		void setPulses(bool);

		bool getPulsesSlowly();
		void setPulsesSlowly(bool);

	};
	static_assert(sizeof(Light) == 0x74, "TES3::Light failed size validation");
}
