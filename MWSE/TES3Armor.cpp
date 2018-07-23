#include "TES3Armor.h"

#define TES3_Armor_getWeightClass 0x4A0F30
#define TES3_Armor_calculateArmorRating 0x4A1120

namespace TES3 {
	int Armor::getWeightClass() {
		return reinterpret_cast<int(__thiscall *)(Armor*)>(TES3_Armor_getWeightClass)(this);
	}

	float Armor::calculateArmorRating(MobileActor * actor) {
		return reinterpret_cast<float(__thiscall *)(Armor*, MobileActor*)>(TES3_Armor_calculateArmorRating)(this, actor);
	}
}
