#include "TES3GameLua.h"

#include "LuaManager.h"

#include "TES3Game.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3Game() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Game>("TES3Game",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"screenShotsEnabled", &TES3::Game::screenShotsEnabled,

				"renderDistance", &TES3::Game::renderDistance,

				"volumeMaster", &TES3::Game::volumeMaster,
				"volumeVoice", &TES3::Game::volumeVoice,
				"volumeEffect", &TES3::Game::volumeEffect,
				"volumeFootsteps", &TES3::Game::volumeFootsteps,
				"volumeMedia", &TES3::Game::volumeMedia,
				"soundQuality", &TES3::Game::soundQuality,

				"windowHandle", sol::readonly_property(&TES3::Game::windowHandle),

				"playerTarget", sol::readonly_property(&TES3::Game::playerTarget)

			);
		}
	}
}
