#include "TES3Sound.h"

#define TES3_Sound_play 0x510A40

namespace TES3 {
	bool Sound::play(Reference* reference, unsigned char volume, float pitch, bool isNot3D) {
		return reinterpret_cast<signed char(__thiscall *)(Sound*, Reference*, unsigned char, float, bool)>(TES3_Sound_play)(this, reference, volume, pitch, isNot3D);
	}
}
