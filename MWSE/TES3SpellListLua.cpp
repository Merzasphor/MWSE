#include "TES3SpellLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Util.h"

#include "TES3Spell.h"
#include "TES3SpellList.h"

namespace mwse {
	namespace lua {
		void bindTES3SpellList() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::SpellList>();
			usertypeDefinition.set("new", sol::no_constructor);

			// 
			usertypeDefinition.set("iterator", sol::readonly_property(&TES3::SpellList::list));

			// Basic function binding.
			usertypeDefinition.set("containsType", &TES3::SpellList::containsType);
			usertypeDefinition.set("getCheapest", &TES3::SpellList::getCheapest);

			// Ambiguous function binding.
			usertypeDefinition.set("add", [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.add(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.add(value.as<const char*>());
				}

				return false;
			});
			usertypeDefinition.set("remove", [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.remove(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.remove(value.as<const char*>());
				}

				return false;
			});
			usertypeDefinition.set("contains", [](TES3::SpellList& self, sol::object value) {
				if (value.is<TES3::Spell*>()) {
					return self.contains(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.contains(value.as<const char*>());
				}

				return false;
			});

			// Finish up our usertype.
			state.set_usertype("tes3spellList", usertypeDefinition);
		}
	}
}
