#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

#include <dsound.h>

namespace TES3 {
	enum class AudioMixType {
		Master = 0,
		Voice,
		Effects,
		Footsteps,
		Music
	};

	struct AudioController {
		char unknown_0x0;
		char unknown_0x1;
		int unknown_0x4; // Flags.
		int unknown_0x8; // Flags.
		LPDIRECTSOUND directSound; // 0xC
		LPDIRECTSOUNDBUFFER lpPrimaryBuffer; // 0x10
		LPDIRECTSOUNDBUFFER lpListener3D; // 0x14
		char unknown_0x18;
		LPDSCAPS soundCaps; // 0x1C
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		char nextMusicFilePath[260]; // 0x7C
		char currentMusicFilePath[260]; // 0x180
		int timestampBeginFade; // 0x284
		int timestampNextTrackStart; // 0x288
		float volumeNextTrack; // 0x28C
		unsigned char volumeMaster; // 0x290
		float volumeMusic; // 0x294
		unsigned char volumeEffects; // 0x298
		unsigned char volumeVoice; // 0x299
		unsigned char volumeFootsteps; // 0x29A
		int unknown_0x29C;
		LPDIRECTSOUNDBUFFER bufferMusic; // 0x2A0
		LPDIRECTSOUNDBUFFER bufferMusic2; // 0x2A4
		bool disableAudio; // 0x2A8
		Vector3 listenerPosition; // 0x2AC
		Vector3 unknown_0x2B8; // Orientation.
		Vector3 unknown_0x2C4; // Orientation.
		float yawAxis; // 0x2D0 // In radians.
		float pitchAxisApproximated; // 0x2D4 // In radians.

		//
		// Thiscall functions.
		//

		void changeMusicTrack(const char* filename, int crossfadeMillis, float volume);

		void setMusicVolume(float volume);

		//
		// Custom functions.
		//

		float getMixVolume(AudioMixType mixType);

		float getNormalizedMasterVolume();
		void setNormalizedMasterVolume(float value);

		float getNormalizedEffectsVolume();
		void setNormalizedEffectsVolume(float value);

		float getNormalizedVoiceVolume();
		void setNormalizedVoiceVolume(float value);

		float getNormalizedFootstepsVolume();
		void setNormalizedFootstepsVolume(float value);

		float getMusicVolume();

		const char* getCurrentMusicFilePath();
		void setCurrentMusicFilePath(const char* path);

		const char* getNextMusicFilePath();
		void setNextMusicFilePath(const char* path);

	};
	static_assert(sizeof(AudioController) == 0x2D8, "TES3::AudioController failed size validation");

	// Make sure we're looking at the same size for DirectSound structures.
	static_assert(sizeof(DSBUFFERDESC) == 0x24, "DirectSound DSBUFFERDESC failed size validation");
	static_assert(sizeof(DSCAPS) == 0x60, "DirectSound DSCAPS failed size validation");
}