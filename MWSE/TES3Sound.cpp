#include "TES3AudioController.h"
#include "TES3Sound.h"
#include "TES3Util.h"
#include "TES3WorldController.h"

namespace TES3 {
	char* Sound::getObjectID() {
		return id;
	}

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

	const auto TES3_Sound_setVolumeRaw = reinterpret_cast<void(__thiscall*)(Sound*, unsigned char)>(0x510C30);
	void Sound::setVolumeRaw(unsigned char volume) {
		TES3_Sound_setVolumeRaw(this, volume);
	}

	const auto TES3_Sound_isPlaying = reinterpret_cast<bool(__thiscall *)(Sound*)>(0x510B80);
	bool Sound::isPlaying() {
		return TES3_Sound_isPlaying(this);
	}

	float Sound::getVolume() {
		return (float)volume / 250.0f;
	}

	void Sound::setVolume(float volume) {
		float currentScale = 1.0f;
		if (soundBuffer && soundBuffer->lpSoundBuffer) {
			if (this->volume == 0) {
				currentScale = 0.0f;
			}
			else {
				currentScale = (float)soundBuffer->volume / (float)this->volume;
			}
		}

		this->volume = volume * 250;

		setVolumeRaw(currentScale);
	}
}
