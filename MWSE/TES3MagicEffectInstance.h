#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct MagicEffectInstance {
		struct Data {
			float resistedPercent; // 0x0
			int magnitude; // 0x4
			float timeActive; // 0x8
			float cumulativeMagnitude; // 0xC
			int state; // 0x10
			signed char visual; // 0x14
			Item* boundItem; // 0x18
			int unknown_0x1C;
			Weapon* lastUsedWeapon; // 0x20
			Armor* lastUsedArmor; // 0x24
			Armor* lastUsedShield; // 0x28
			Light* lastUsedLight; // 0x2C
			Item* lastUsedEnchItem; // 0x30
			float unknown_0x34;
		};
		const char * targetId; // 0x0
		union { // Backwards compatibility for maximum ugliness.
			Data data;
			struct {
				float resistedPercent; // 0x4
				int magnitude; // 0x8
				float timeActive; // 0xC
				float cumulativeMagnitude; // 0x10
				int state; // 0x14
				signed char visual; // 0x18
				Item* boundItem; // 0x1C
				int unknown_0x20;
				Weapon* lastUsedWeapon; // 0x24
				Armor* lastUsedArmor; // 0x28
				Armor* lastUsedShield; // 0x2C
				Light* lastUsedLight; // 0x30
				Item* lastUsedEnchItem; // 0x34
				float unknown_0x38;
			};
		};
	};
	static_assert(sizeof(MagicEffectInstance) == 0x3C, "TES3::MagicEffectInstance failed size validation");
	static_assert(sizeof(MagicEffectInstance::Data) == 0x38, "TES3::MagicEffectInstance::Data failed size validation");
}
