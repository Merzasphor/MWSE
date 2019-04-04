#include "TES3AudioController.h"
#include "TES3Sound.h"
#include "TES3Util.h"
#include "TES3WorldController.h"

namespace TES3 {
	const auto TES3_Sound_play = reinterpret_cast<bool (__thiscall *)(Sound*, int, unsigned char, float, bool)>(0x510A40);
	bool Sound::play(int playbackFlags, unsigned char volume, float pitch, bool isNot3D) {
		unsigned int master = TES3::WorldController::get()->audioController->volumeMaster;
		unsigned int finalVolume = master * volume / 250;
		return TES3_Sound_play(this, playbackFlags, finalVolume, pitch, isNot3D);
	}

	const auto TES3_Sound_stop = reinterpret_cast<void(__thiscall *)(Sound*)>(0x510BC0);
	void Sound::stop() {
		TES3_Sound_stop(this);
	}

	const auto TES3_Sound_isPlaying = reinterpret_cast<bool(__thiscall *)(Sound*)>(0x510B80);
	bool Sound::isPlaying() {
		return TES3_Sound_isPlaying(this);
	}
}
