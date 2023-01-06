#include "CSArmor.h"

namespace se::cs {
	ArmorWeightClass::ArmorWeightClass Armor::getWeightClass() const {
		const auto Armor_getWeightClass = reinterpret_cast<ArmorWeightClass::ArmorWeightClass(__thiscall*)(const Armor*)>(0x4032AB);
		return Armor_getWeightClass(this);
	}

	const char* Armor::getWeightClassName() const {
		switch (getWeightClass()) {
		case ArmorWeightClass::Light:
			return "Light";
		case ArmorWeightClass::Medium:
			return "Medium";
		case ArmorWeightClass::Heavy:
			return "Heavy";
		default:
			return "Unknown";
		}
	}
}
