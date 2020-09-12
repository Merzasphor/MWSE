#include "TES3Alchemy.h"

#include "TES3Util.h"

namespace TES3 {
	size_t Alchemy::getActiveEffectCount() {
		size_t count = 0;
		for (size_t i = 0; i < 8; i++) {
			if (effects[i].effectID != TES3::EffectID::None) {
				count++;
			}
		}
		return count;
	}

	int Alchemy::getFirstIndexOfEffect(int effectId) {
		for (size_t i = 0; i < 8; i++) {
			if (effects[i].effectID = effectId) {
				return i;
			}
		}
		return -1;
	}

	bool Alchemy::effectsMatchWith(Alchemy * other) {
		for (size_t i = 0; i < 8; i++) {
			if (effects[i].matchesEffectsWith(&other->effects[i])) {
				return false;
			}
		}
		return true;
	}

	void Alchemy::setIconPath(const char* path) {
		if (strnlen_s(path, 32) >= 32) {
			throw std::invalid_argument("Path must not be 32 or more characters.");
		}
		mwse::tes3::setDataString(&icon, path);
	}

	std::reference_wrapper<Effect[8]> Alchemy::getEffects() {
		return std::ref(effects);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Alchemy)
