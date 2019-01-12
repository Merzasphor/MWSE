#include "TES3Misc.h"

#include "TES3Util.h"

namespace TES3 {
	const auto TES3_Misc_getGoldStackCount = reinterpret_cast<int(__cdecl*)(Misc*)>(0x49A750);
	int Misc::getGoldStackCount() {
		return TES3_Misc_getGoldStackCount(this);
	}

	SoulGemData * Misc::getSoulGemData() {
		return mwse::tes3::getSoulGemData(this);
	}

	bool Misc::isSoulGem() {
		return mwse::tes3::isSoulGem(this);
	}
}
