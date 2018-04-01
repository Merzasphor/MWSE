#include "TES3SpellLua.h"

#include "LuaManager.h"

#include "TES3Spell.h"

namespace mwse {
	namespace lua {
		void bindTES3Spell() {
			LuaManager::getInstance().getState().new_usertype<TES3::Spell>("TES3Spell",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Spell::objectType,

				"id", sol::readonly_property(&TES3::Spell::getObjectID),
				"name", sol::property(&TES3::Spell::getName, &TES3::Spell::setName),

				"flags", &TES3::Spell::spellFlags,
				"autoCalc", sol::property(&TES3::Spell::getAutoCalc, &TES3::Spell::setAutoCalc),

				"effects", sol::readonly_property([](TES3::Spell& self) { return std::ref(self.effects); }),

				"castType", &TES3::Spell::castType,
				"magickaCost", &TES3::Spell::magickaCost

				);
		}
	}
}
