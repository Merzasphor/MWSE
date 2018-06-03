#include "TES3MagicSourceInstanceLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicSourceInstance() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MagicSourceInstance>("TES3MagicSourceInstance",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				//
				// Properties.
				//

				"objectType", &TES3::MagicSourceInstance::objectType,

				"source", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.sourceCombo.source.asGeneric); }),
				"sourceType", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.sourceType; }),
				"state", &TES3::MagicSourceInstance::state,
				"caster", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.caster); }),
				"item", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.castingItem); }),
				"itemData", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemCondition; }),
				"text", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.text; }),

				"sourceEffects", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.getSourceEffects(); })

				//
				// Functions
				//

				

			);
		}
	}
}
