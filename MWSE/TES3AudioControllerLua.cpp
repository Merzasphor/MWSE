#include "TES3AudioControllerLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3AudioController.h"

namespace mwse {
	namespace lua {
		void bindTES3AudioController() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::AudioController>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("disableAudio", &TES3::AudioController::disableAudio);
			usertypeDefinition.set("listenerPosition", &TES3::AudioController::listenerPosition);
			usertypeDefinition.set("musicFadeBeginTimestamp", &TES3::AudioController::timestampBeginFade);
			usertypeDefinition.set("musicNextTrackStartTimestamp", &TES3::AudioController::timestampNextTrackStart);
			usertypeDefinition.set("musicNextTrackVolume", &TES3::AudioController::volumeNextTrack);
			usertypeDefinition.set("pitchAxis", &TES3::AudioController::pitchAxisApproximated);
			usertypeDefinition.set("yawAxis", &TES3::AudioController::yawAxis);

			// Properties bound as functions.
			usertypeDefinition.set("currentMusicFilePath", sol::property(&TES3::AudioController::getCurrentMusicFilePath, &TES3::AudioController::setCurrentMusicFilePath));
			usertypeDefinition.set("nextMusicFilePath", sol::property(&TES3::AudioController::getNextMusicFilePath, &TES3::AudioController::setNextMusicFilePath));
			usertypeDefinition.set("volumeEffects", sol::property(&TES3::AudioController::getNormalizedEffectsVolume, &TES3::AudioController::setNormalizedEffectsVolume));
			usertypeDefinition.set("volumeFootsteps", sol::property(&TES3::AudioController::getNormalizedFootstepsVolume, &TES3::AudioController::setNormalizedFootstepsVolume));
			usertypeDefinition.set("volumeMaster", sol::property(&TES3::AudioController::getNormalizedMasterVolume, &TES3::AudioController::setNormalizedMasterVolume));
			usertypeDefinition.set("volumeMusic", sol::property(&TES3::AudioController::getMusicVolume, &TES3::AudioController::setMusicVolume));
			usertypeDefinition.set("volumeVoice", sol::property(&TES3::AudioController::getNormalizedVoiceVolume, &TES3::AudioController::setNormalizedVoiceVolume));

			// Basic function binding.
			usertypeDefinition.set("getMixVolume", &TES3::AudioController::getMixVolume);
			
			// Wrapped functions.
			usertypeDefinition.set("changeMusicTrack", [](TES3::AudioController& self, const char* filename, sol::optional<int> crossfade, sol::optional<float> volume) {
				self.changeMusicTrack(filename, crossfade.value_or(1000), volume.value_or(1.0f));
			});

			// Finish up our usertype.
			state.set_usertype("tes3audioController", usertypeDefinition);
		}
	}
}
