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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::MagicSourceInstance>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("castChanceOverride", &TES3::MagicSourceInstance::overrideCastChance);
			usertypeDefinition.set("itemData", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemCondition; }));
			usertypeDefinition.set("itemID", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemID; }));
			usertypeDefinition.set("magicID", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.magicID; }));
			usertypeDefinition.set("serialNumber", sol::readonly_property(&TES3::MagicSourceInstance::serialNumber));
			usertypeDefinition.set("sourceType", sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.sourceType; }));
			usertypeDefinition.set("state", &TES3::MagicSourceInstance::state);
			usertypeDefinition.set("timestampCastBegin", &TES3::MagicSourceInstance::timestampCastBegin);

			// Basic function binding.
			usertypeDefinition.set("getMagnitudeForIndex", &TES3::MagicSourceInstance::getMagnitude);
			usertypeDefinition.set("playVisualEffect",
				[](TES3::MagicSourceInstance& self, sol::table params) {
					int effectIndex = getOptionalParam<int>(params, "effectIndex", -1);
					if (effectIndex < 0 || effectIndex > 7) {
						throw std::invalid_argument("Invalid 'effectIndex' parameter. Must be a number between 0 and 7.");
					}

					auto position = mwse::lua::getOptionalParamVector3(params, "position");
					if (!position) {
						throw std::invalid_argument("Invalid 'position' parameter. Must be a table[3] or tes3vector3.");
					}

					auto visual = getOptionalParamObject<TES3::PhysicalObject>(params, "visual");
					if (visual == nullptr) {
						throw std::invalid_argument("Invalid 'visual' parameter. Must be a valid tes3physicalObject or string that can resolve into one.");
					}

					float duration = getOptionalParam<float>(params, "duration", 1.0f);
					TES3::Reference* reference = getOptionalParamExecutionReference(params);

					self.playSpellVFX(duration, position.value(), reference, 0, visual, effectIndex, 0);
				}
			);

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
