#include "TES3MobileNPCLua.h"

#include "LuaManager.h"

#include "TES3MobileNPC.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileNPC() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MobileNPC>("TES3MobileNPC",
				// Disable construction of this type.
				"new", sol::no_constructor,

				"reference", &TES3::MobileNPC::reference,
				"collidingReference", &TES3::MobileNPC::collidingReference,

				"height", &TES3::MobileNPC::height,
				"boundSize", &TES3::MobileNPC::boundSize,

				"position", &TES3::MobileNPC::position,
				"velocity", &TES3::MobileNPC::velocity,
				"impulseVelocity", &TES3::MobileNPC::impulseVelocity,

				"action", &TES3::MobileNPC::actionData,
				"actionBeforeCombat", &TES3::MobileNPC::actionBeforeCombat,

				"health", &TES3::MobileNPC::health,
				"magicka", &TES3::MobileNPC::magicka,
				"fatigue", &TES3::MobileNPC::fatigue,
				"magickaMultiplier", &TES3::MobileNPC::magickaMultiplier

				);
		}
	}
}
