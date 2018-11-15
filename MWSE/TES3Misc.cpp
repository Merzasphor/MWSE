#include "TES3Misc.h"

#include "TES3Util.h"

namespace TES3 {
	SoulGemData * Misc::getSoulGemData() {
		return mwse::tes3::getSoulGemData(this);
	}

	bool Misc::isSoulGem() {
		return mwse::tes3::isSoulGem(this);
	}
}
