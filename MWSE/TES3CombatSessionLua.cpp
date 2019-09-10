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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::CombatSession>("tes3combatSession");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["alchemyPriority"] = &TES3::CombatSession::alchemyPriority;
			usertypeDefinition["distance"] = &TES3::CombatSession::combatDistance;
			usertypeDefinition["selectedAction"] = &TES3::CombatSession::nextAction;
			usertypeDefinition["selectedAlchemy"] = &TES3::CombatSession::selectedAlchemy;
			usertypeDefinition["selectedShield"] = sol::readonly_property(&TES3::CombatSession::selectedShield);
			usertypeDefinition["selectedSpell"] = &TES3::CombatSession::selectedSpell;
			usertypeDefinition["selectedWeapon"] = sol::readonly_property(&TES3::CombatSession::selectedWeapon);
			usertypeDefinition["selectionPriority"] = &TES3::CombatSession::selectionPriority;

			// Properties that need to be packaged.
			usertypeDefinition["mobile"] = sol::readonly_property([](TES3::CombatSession& self) { return makeLuaObject(self.parentActor); });

			// Basic function binding.
			usertypeDefinition["selectAlchemyWithEffect"] = &TES3::CombatSession::chooseAlchemyWithEffect;
		}
	}
}
