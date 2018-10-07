#include "TES3GameLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "NINode.h"

#include "TES3Game.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3Game() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Game>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("parentWindowHandle", sol::readonly_property(&TES3::Game::parentWindowHandle));
			usertypeDefinition.set("playerTarget", sol::readonly_property(&TES3::Game::playerTarget));
			usertypeDefinition.set("renderDistance", &TES3::Game::renderDistance);
			usertypeDefinition.set("screenShotsEnabled", &TES3::Game::screenShotsEnabled);
			usertypeDefinition.set("screenX", sol::readonly_property(&TES3::Game::screenX));
			usertypeDefinition.set("screenY", sol::readonly_property(&TES3::Game::screenY));
			usertypeDefinition.set("soundQuality", &TES3::Game::soundQuality);
			usertypeDefinition.set("volumeEffect", &TES3::Game::volumeEffect);
			usertypeDefinition.set("volumeFootsteps", &TES3::Game::volumeFootsteps);
			usertypeDefinition.set("volumeMaster", &TES3::Game::volumeMaster);
			usertypeDefinition.set("volumeMedia", &TES3::Game::volumeMedia);
			usertypeDefinition.set("volumeVoice", &TES3::Game::volumeVoice);
			usertypeDefinition.set("windowHandle", sol::readonly_property(&TES3::Game::windowHandle));
			usertypeDefinition.set("wireframeProperty", sol::readonly_property(&TES3::Game::wireframeProperty));
			usertypeDefinition.set("worldSceneGraphRoot", sol::readonly_property(&TES3::Game::worldRoot));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("playerTarget", sol::readonly_property([](TES3::Game& self) { return makeLuaObject(self.playerTarget); }));

			// Finish up our usertype.
			state.set_usertype("tes3game", usertypeDefinition);
		}
	}
}
