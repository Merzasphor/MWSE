#include "TES3AudioController.h"

namespace TES3 {

	float AudioController::getMixVolume(AudioMixType mix) {
		float volume = 0.004 * volumeMaster;
		switch (mix) {
		case AudioMixType::Master:
			break;
		case AudioMixType::Voice:
			volume *= 0.004 * volumeVoice;
			break;
		case AudioMixType::Effects:
			volume *= 0.004 * volumeEffects;
			break;
		case AudioMixType::Footsteps:
			volume *= 0.004 * volumeFootsteps;
			break;
		case AudioMixType::Music:
			// Music is not linked to master volume
			volume = volumeMusic;
			break;
		}
		return volume;
	}

}