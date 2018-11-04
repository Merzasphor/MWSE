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
			usertypeDefinition.set("alchemyPriority", &TES3::CombatSession::alchemyPriority);
			usertypeDefinition.set("distance", &TES3::CombatSession::combatDistance);
			usertypeDefinition.set("selectedAction", &TES3::CombatSession::nextAction);
			usertypeDefinition.set("selectedAlchemy", &TES3::CombatSession::selectedAlchemy);
			usertypeDefinition.set("selectedShield", sol::readonly_property(&TES3::CombatSession::selectedShield));
			usertypeDefinition.set("selectedSpell", &TES3::CombatSession::selectedSpell);
			usertypeDefinition.set("selectedWeapon", sol::readonly_property(&TES3::CombatSession::selectedWeapon));
			usertypeDefinition.set("selectionPriority", &TES3::CombatSession::selectionPriority);

			// Properties that need to be packaged.
			usertypeDefinition.set("mobile", sol::readonly_property([](TES3::CombatSession& self) { return makeLuaObject(self.parentActor); }));

			// Basic function binding.
			usertypeDefinition.set("selectAlchemyWithEffect", &TES3::CombatSession::chooseAlchemyWithEffect);

			// Finish up our usertype.
			state.set_usertype("tes3combatSession", usertypeDefinition);
		}
	}
}
