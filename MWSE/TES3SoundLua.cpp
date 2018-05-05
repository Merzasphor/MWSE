#include "TES3SoundLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Sound() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::Sound>("TES3Sound",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"id", sol::readonly_property([](TES3::Sound& self) { return self.id; }),
				"filename", sol::readonly_property([](TES3::Sound& self) { return self.filename; })

				);

			state.new_usertype<TES3::SoundGenerator>("TES3SoundGenerator",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"id", sol::readonly_property([](TES3::SoundGenerator& self) { return self.name; }),
				"sound", &TES3::SoundGenerator::sound,
				"type", &TES3::SoundGenerator::soundType

				);
		}
	}
}
