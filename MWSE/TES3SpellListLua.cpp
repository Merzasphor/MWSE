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
			sol::state& state = LuaManager::getInstance().getState();
			
			state.new_usertype<TES3::SpellList>("TES3SpellList",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"iterator", &TES3::SpellList::list,

				//
				// Functions
				//

				"add", [](TES3::SpellList& self, sol::object value)
			{
				if (value.is<TES3::Spell*>()) {
					return self.add(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.add(value.as<const char*>());
				}

				return false;
			},

				"remove", [](TES3::SpellList& self, sol::object value)
			{
				if (value.is<TES3::Spell*>()) {
					return self.remove(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.remove(value.as<const char*>());
				}

				return false;
			},

				"contains", [](TES3::SpellList& self, sol::object value)
			{
				if (value.is<TES3::Spell*>()) {
					return self.contains(value.as<TES3::Spell*>());
				}
				else if (value.is<const char*>()) {
					return self.contains(value.as<const char*>());
				}

				return false;
			},

				"containsType", &TES3::SpellList::containsType,

				"getCheapest", &TES3::SpellList::getCheapest

			);
		}
	}
}
