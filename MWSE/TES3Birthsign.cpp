#include "TES3Birthsign.h"

#define TES3_Birthsign_getDescription 0x474990
#define TES3_Birthsign_loadDescription 0x4749B0
#define TES3_Birthsign_freeDescription 0x474B70

namespace TES3 {
	char* Birthsign::getName() {
		return name;
	}

	char* Birthsign::getDescription() {
		return reinterpret_cast<char* (__thiscall*)(Birthsign*)>(TES3_Birthsign_getDescription)(this);
	}

	void Birthsign::freeDescription() {
		reinterpret_cast<void(__thiscall*)(Birthsign*)>(TES3_Birthsign_freeDescription)(this);
	}

	std::string Birthsign::getAndFreeDescription() {
		std::string desc = Birthsign::getDescription();
		Birthsign::freeDescription();
		return std::move(desc);
	}
}
