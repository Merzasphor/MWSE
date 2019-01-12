#include "TES3MagicSourceInstanceLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Item.h"
#include "TES3ItemData.h"
#include "TES3MagicSourceInstance.h"
#include "TES3MobileProjectile.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicSourceInstance() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MagicSourceInstance>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("castChanceOverride", &TES3::MagicSourceInstance::overrideCastChance);
			usertypeDefinition.set("itemData", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemCondition; }));
			usertypeDefinition.set("sourceType", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.sourceType; }));
			usertypeDefinition.set("timestampCastBegin", &TES3::MagicSourceInstance::timestampCastBegin);
			usertypeDefinition.set("state", &TES3::MagicSourceInstance::state);
			usertypeDefinition.set("itemID", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemID; }));
			usertypeDefinition.set("magicID", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.magicID; }));

			// Basic function binding.
			usertypeDefinition.set("getMagnitudeForIndex", &TES3::MagicSourceInstance::getMagnitude);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("target", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.target); }));
			usertypeDefinition.set("projectile", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.magicProjectile); }));
			usertypeDefinition.set("caster", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.caster); }));
			usertypeDefinition.set("item", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.castingItem); }));
			usertypeDefinition.set("source", sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.sourceCombo.source.asGeneric); }));

			// Functions exposed as properties.
			usertypeDefinition.set("sourceEffects", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.getSourceEffects(); }));

			// Finish up our usertype.
			state.set_usertype("tes3magicSourceInstance", usertypeDefinition);
		}
	}
}
