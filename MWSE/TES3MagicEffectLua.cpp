#include "TES3MagicEffectLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffect() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MagicEffect>("TES3MagicEffect",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::MagicEffect::objectType,

				"flags", &TES3::MagicEffect::flags,

				"id", sol::readonly_property(&TES3::MagicEffect::id),

				"school", &TES3::MagicEffect::school,
				"baseMagickaCost", &TES3::MagicEffect::baseMagickaCost,

				"icon", sol::readonly_property([](TES3::MagicEffect& self) { return self.icon; }),
				"particleTexture", sol::readonly_property([](TES3::MagicEffect& self) { return self.particleTexture; }),
				"castSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.castSoundEffect; }),
				"boltSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.boltSoundEffect; }),
				"hitSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.hitSoundEffect; }),
				"areaSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.areaSoundEffect; }),

				"lightingRed", &TES3::MagicEffect::lightingRed,
				"lightingGreen", &TES3::MagicEffect::lightingGreen,
				"lightingBlue", &TES3::MagicEffect::lightingBlue,

				"size", &TES3::MagicEffect::size,
				"speed", &TES3::MagicEffect::speed,
				"sizeCap", &TES3::MagicEffect::sizeCap

				);

			state.new_usertype<TES3::Effect>("TES3Effect",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"id", &TES3::Effect::effectID,
				"skill", &TES3::Effect::skillID,
				"attribute", &TES3::Effect::attributeID,
				"rangeType", &TES3::Effect::rangeType,
				"radius", &TES3::Effect::radius,
				"duration", &TES3::Effect::duration,
				"min", &TES3::Effect::magnitudeMin,
				"max", &TES3::Effect::magnitudeMax,

				// Access to the root MGEF object.
				"object", sol::readonly_property([](TES3::Effect& self) { return tes3::getDataHandler()->nonDynamicData->magicEffects[self.effectID]; })

				);
		}
	}
}
