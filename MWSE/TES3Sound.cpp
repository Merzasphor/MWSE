#include "TES3Sound.h"
#include "TES3Util.h"

namespace TES3 {
	const auto TES3_Sound_play = reinterpret_cast<bool (__thiscall *)(Sound*, int, unsigned char, float, bool)>(0x510A40);

	bool Sound::play(int playbackFlags, unsigned char volume, float pitch, bool isNot3D) {
		return TES3_Sound_play(this, playbackFlags, volume, pitch, isNot3D);
	}
}
