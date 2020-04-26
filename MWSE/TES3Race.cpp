#include "TES3Race.h"

#define TES3_Race_loadDescription 0x4A7A90
#define TES3_Race_freeDescription 0x4A7C90

namespace TES3 {
	char * Race::getObjectID() {
		return id;
	}

	const auto TES3_Race_getBodyPart = reinterpret_cast<BodyPart * (__thiscall*)(Race*, int, int, Race::PartIndex)>(0x4A7790);
	BodyPart* Race::getBodyPart(bool isFemale, bool isVampire, PartIndex index) {
		return TES3_Race_getBodyPart(this, isFemale, isVampire, index);
	}

	char* Race::loadDescription() {
		return reinterpret_cast<char* (__thiscall*)(Race*)>(TES3_Race_loadDescription)(this);
	}

	void Race::freeDescription() {
		reinterpret_cast<void(__thiscall*)(Race*)>(TES3_Race_freeDescription)(this);
	}
}
