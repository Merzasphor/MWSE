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
			auto usertypeDefinition = state.new_usertype<TES3::MagicSourceInstance>("tes3magicSourceInstance");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["castChanceOverride"] = &TES3::MagicSourceInstance::overrideCastChance;
			usertypeDefinition["itemData"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemCondition; });
			usertypeDefinition["itemID"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.castingItemID; });
			usertypeDefinition["magicID"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.magicID; });
			usertypeDefinition["serialNumber"] = sol::readonly_property(&TES3::MagicSourceInstance::serialNumber);
			usertypeDefinition["sourceType"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.sourceType; });
			usertypeDefinition["state"] = &TES3::MagicSourceInstance::state;
			usertypeDefinition["timestampCastBegin"] = &TES3::MagicSourceInstance::timestampCastBegin;

			// Basic function binding.
			usertypeDefinition["getMagnitudeForIndex"] = &TES3::MagicSourceInstance::getMagnitude;
			usertypeDefinition["playVisualEffect"] = [](TES3::MagicSourceInstance& self, sol::table params) {
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
			};

			// Access to other objects that need to be packaged.
			usertypeDefinition["target"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.target); });
			usertypeDefinition["projectile"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.magicProjectile); });
			usertypeDefinition["caster"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.caster); });
			usertypeDefinition["item"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.castingItem); });
			usertypeDefinition["source"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return makeLuaObject(self.sourceCombo.source.asGeneric); });

			// Functions exposed as properties.
			usertypeDefinition["sourceEffects"] = sol::readonly_property([](TES3::MagicSourceInstance& self) { return self.sourceCombo.getSourceEffects(); });
		}
	}
}
