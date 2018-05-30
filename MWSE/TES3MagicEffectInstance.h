#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct MagicEffectInstance {
		Reference * target;
		float resistedPercent;
		float magnitude;
		float timeActive;
		float cumulativeMagnitude;
		int state;
		signed char visual;
		Item * boundItem;
		int unknown_0x20;
		Weapon * lastUsedWeapon;
		Armor * lastUsedArmor;
		Armor * lastUsedShield;
		Light * lastUsedLight;
		Item * lastUsedEnchItem;
		int unknown_0x38;
	};
}
