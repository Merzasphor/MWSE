#include "TES3SpellInstanceLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3SpellInstance() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::SpellInstance>("TES3SpellInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::SpellInstance::objectType,

				"spell", sol::readonly_property([](TES3::SpellInstance& self) { return makeLuaObject(self.spell); }),
				"type", &TES3::SpellInstance::sourceType,
				"state", &TES3::SpellInstance::spellState,
				"target", sol::readonly_property([](TES3::SpellInstance& self) { return makeLuaObject(self.targetReference); }),
				"item", sol::readonly_property([](TES3::SpellInstance& self) { return makeLuaObject(self.castingItem); }),
				"itemData", sol::readonly_property([](TES3::SpellInstance& self) { return self.castingItemCondition; }),
				"text", sol::readonly_property([](TES3::SpellInstance& self) { return self.spellText; })

				//
				// Functions
				//



			);
		}
	}
}
