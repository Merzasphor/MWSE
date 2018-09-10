#include "TES3CombatSessionLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3CombatSession.h"
#include "TES3Inventory.h"
#include "TES3MobileActor.h"
#include "TES3Spell.h"

namespace mwse {
	namespace lua {
		void bindTES3CombatSession() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::CombatSession>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Basic property binding.
			usertypeDefinition.set("action", &TES3::CombatSession::nextAction);
			usertypeDefinition.set("distance", &TES3::CombatSession::combatDistance);
			usertypeDefinition.set("shield", sol::readonly_property(&TES3::CombatSession::selectedShield));
			usertypeDefinition.set("spell", &TES3::CombatSession::nextSpell);
			usertypeDefinition.set("weapon", sol::readonly_property(&TES3::CombatSession::selectedWeapon));

			usertypeDefinition.set("mobile", sol::readonly_property([](TES3::CombatSession& self) { return makeLuaObject(self.parentActor); }));

			// Finish up our usertype.
			state.set_usertype("tes3combatSession", usertypeDefinition);
		}
	}
}
