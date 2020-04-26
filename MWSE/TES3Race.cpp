#include "TES3Race.h"

namespace TES3 {
	char * Race::getObjectID() {
		return id;
	}

	const auto TES3_Race_getBodyPart = reinterpret_cast<BodyPart * (__thiscall*)(Race*, int, int, Race::PartIndex)>(0x4A7790);
	BodyPart* Race::getBodyPart(bool isFemale, bool isVampire, PartIndex index) {
		return TES3_Race_getBodyPart(this, isFemale, isVampire, index);
	}

	const auto TES3_Race_loadDescription = reinterpret_cast<char* (__thiscall*)(Race*)>(0x4A7A90);
	char* Race::loadDescription() {
		return TES3_Race_loadDescription(this);
	}

	const auto TES3_Race_freeDescription = reinterpret_cast<void(__thiscall*)(Race*)>(0x4A7C90);
	void Race::freeDescription() {
		return TES3_Race_freeDescription(this);
	}
}
