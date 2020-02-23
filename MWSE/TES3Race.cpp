#include "TES3Race.h"

namespace TES3 {
	char * Race::getObjectID() {
		return id;
	}

	const auto TES3_Race_getBodyPart = reinterpret_cast<BodyPart * (__thiscall*)(Race*, int, int, Race::PartIndex)>(0x4A7790);
	BodyPart* Race::getBodyPart(bool isFemale, bool isVampire, PartIndex index) {
		return TES3_Race_getBodyPart(this, isFemale, isVampire, index);
	}
}
