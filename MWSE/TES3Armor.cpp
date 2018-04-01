#include "TES3Armor.h"

#define TES3_Armor_getWeightClass 0x4A0F30

namespace TES3 {
	int Armor::getWeightClass() {
		return reinterpret_cast<int(__thiscall *)(Armor*)>(TES3_Armor_getWeightClass)(this);
	}
}
