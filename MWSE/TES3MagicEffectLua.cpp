#include "TES3MagicEffectLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Util.h"

#include "TES3MagicEffect.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffect() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::MagicEffect>("TES3MagicEffect",
				// Disable construction of this type.
				"new", sol::no_constructor,

				sol::base_classes, sol::bases<TES3::BaseObject>(),

				//
				// Properties.
				//

				"objectType", &TES3::MagicEffect::objectType,

				"flags", &TES3::MagicEffect::flags,
				"baseFlags", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlags()[self.id]; },
					[](TES3::MagicEffect& self, double value) { tes3::getBaseEffectFlags()[self.id] = value; }
					),

				// Nicer access to flags.
				"targetsSkills", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::TargetSkill); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::TargetSkill, set); }
					),
				"targetsAttributes", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::TargetAttribute); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::TargetAttribute, set); }
					),
				"hasNoDuration", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NoDuration); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NoDuration, set); }
					),
				"hasNoMagnitude", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NoMagnitude); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NoMagnitude, set); }
					),
				"isHarmful", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::Harmful); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::Harmful, set); }
					),
				"hasContinuousVFX", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::ContinuousVFX); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::ContinuousVFX, set); }
					),
				"canCastSelf", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastSelf); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastSelf, set); }
					),
				"canCastTouch", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTouch); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTouch, set); }
					),
				"canCastTarget", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTarget); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTarget, set); }
					),
				"allowSpellmaking", sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowSpellmaking) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowSpellmaking; }
					),
				"allowEnchanting", sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowEnchanting) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowEnchanting; }
					),
				"usesNegativeLighting", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NegativeLighting); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NegativeLighting, set); }
					),
				"appliesOnce", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::AppliedOnce); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::AppliedOnce, set); }
					),
				"nonRecastable", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NonRecastable); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NonRecastable, set); }
					),
				"illegalDaedra", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::IllegalDaedra); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::IllegalDaedra, set); }
					),
				"unreflectable", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::Unreflectable); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::Unreflectable, set); }
					),
				"casterLinked", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CasterLinked); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CasterLinked, set); }
					),

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
