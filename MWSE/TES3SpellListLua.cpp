#include "TES3SpellLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Util.h"

#include "TES3MobileActor.h"
#include "TES3Spell.h"
#include "TES3SpellList.h"

namespace mwse {
	namespace lua {
		void bindTES3SpellList() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::SpellList>("tes3spellList");
			usertypeDefinition["new"] = sol::no_constructor;

			// 
			usertypeDefinition["iterator"] = sol::readonly_property(&TES3::SpellList::list);

			// Basic function binding.
			usertypeDefinition["containsType"] = &TES3::SpellList::containsType;
			usertypeDefinition["getCheapest"] = &TES3::SpellList::getCheapest;

			// Ambiguous function binding.
			usertypeDefinition["add"] = [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.add(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.add(value.as<const char*>());
				}

				return false;
			};
			usertypeDefinition["remove"] = [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.remove(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.remove(value.as<const char*>());
				}

				return false;
			};
			usertypeDefinition["contains"] = [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.contains(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.contains(value.as<const char*>());
				}

				return false;
			};
		}
	}
}
