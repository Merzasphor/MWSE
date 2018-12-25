#include "TES3MagicEffectLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3MagicEffect.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffect() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::MagicEffect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MagicEffect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("baseMagickaCost", &TES3::MagicEffect::baseMagickaCost);
				usertypeDefinition.set("flags", &TES3::MagicEffect::flags);
				usertypeDefinition.set("id", sol::readonly_property(&TES3::MagicEffect::id));
				usertypeDefinition.set("lightingBlue", &TES3::MagicEffect::lightingBlue);
				usertypeDefinition.set("lightingGreen", &TES3::MagicEffect::lightingGreen);
				usertypeDefinition.set("lightingRed", &TES3::MagicEffect::lightingRed);
				usertypeDefinition.set("school", &TES3::MagicEffect::school);
				usertypeDefinition.set("size", &TES3::MagicEffect::size);
				usertypeDefinition.set("sizeCap", &TES3::MagicEffect::sizeCap);
				usertypeDefinition.set("speed", &TES3::MagicEffect::speed);

				// Allow access to base effect flags.
				usertypeDefinition.set("baseFlags", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlags()[self.id]; },
					[](TES3::MagicEffect& self, double value) { tes3::getBaseEffectFlags()[self.id] = value; }
				));

				// User-friendly access to those base effects.
				usertypeDefinition.set("targetsSkills", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::TargetSkill); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::TargetSkill, set); }
				));
				usertypeDefinition.set("targetsAttributes", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::TargetAttribute); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::TargetAttribute, set); }
				));
				usertypeDefinition.set("hasNoDuration", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NoDuration); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NoDuration, set); }
				));
				usertypeDefinition.set("hasNoMagnitude", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NoMagnitude); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NoMagnitude, set); }
				));
				usertypeDefinition.set("isHarmful", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::Harmful); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::Harmful, set); }
				));
				usertypeDefinition.set("hasContinuousVFX", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::ContinuousVFX); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::ContinuousVFX, set); }
				));
				usertypeDefinition.set("canCastSelf", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastSelf); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastSelf, set); }
				));
				usertypeDefinition.set("canCastTouch", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTouch); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTouch, set); }
				));
				usertypeDefinition.set("canCastTarget", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTarget); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CanCastTarget, set); }
				));
				usertypeDefinition.set("allowSpellmaking", sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowSpellmaking) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowSpellmaking; }
				));
				usertypeDefinition.set("allowEnchanting", sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowEnchanting) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowEnchanting; }
				));
				usertypeDefinition.set("usesNegativeLighting", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NegativeLighting); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NegativeLighting, set); }
				));
				usertypeDefinition.set("appliesOnce", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::AppliedOnce); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::AppliedOnce, set); }
				));
				usertypeDefinition.set("nonRecastable", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::NonRecastable); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::NonRecastable, set); }
				));
				usertypeDefinition.set("illegalDaedra", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::IllegalDaedra); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::IllegalDaedra, set); }
				));
				usertypeDefinition.set("unreflectable", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::Unreflectable); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::Unreflectable, set); }
				));
				usertypeDefinition.set("casterLinked", sol::property(
					[](TES3::MagicEffect& self) { return tes3::getBaseEffectFlag(self.id, TES3::EffectFlag::CasterLinked); },
					[](TES3::MagicEffect& self, bool set) { tes3::setBaseEffectFlag(self.id, TES3::EffectFlag::CasterLinked, set); }
				));

				// Functions exposed as properties.
				usertypeDefinition.set("areaSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.areaSoundEffect; }));
				usertypeDefinition.set("boltSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.boltSoundEffect; }));
				usertypeDefinition.set("castSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.castSoundEffect; }));
				usertypeDefinition.set("hitSoundEffect", sol::readonly_property([](TES3::MagicEffect& self) { return self.hitSoundEffect; }));
				usertypeDefinition.set("icon", sol::property(
					[](TES3::MagicEffect& self) { return self.icon; },
					[](TES3::MagicEffect& self, const char* value) { if (strlen(value) < 32) strcpy(self.icon, value); }
				));
				usertypeDefinition.set("particleTexture", sol::readonly_property([](TES3::MagicEffect& self) { return self.particleTexture; }));

				// Finish up our usertype.
				state.set_usertype("tes3magicEffect", usertypeDefinition);
			}

			// Binding for TES3::Effect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Effect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Convert to string.
				usertypeDefinition.set(sol::meta_function::to_string, [](TES3::Effect& self) -> sol::optional<std::string> {
					if (self.effectID == -1) {
						return sol::optional<std::string>();
					}
					return self.toString();
				});

				// Basic property binding.
				usertypeDefinition.set("attribute", &TES3::Effect::attributeID);
				usertypeDefinition.set("duration", &TES3::Effect::duration);
				usertypeDefinition.set("id", &TES3::Effect::effectID);
				usertypeDefinition.set("max", &TES3::Effect::magnitudeMax);
				usertypeDefinition.set("min", &TES3::Effect::magnitudeMin);
				usertypeDefinition.set("radius", &TES3::Effect::radius);
				usertypeDefinition.set("rangeType", &TES3::Effect::rangeType);
				usertypeDefinition.set("skill", &TES3::Effect::skillID);

				// Allow easy access to the base magic effect.
				usertypeDefinition.set("object", sol::readonly_property(&TES3::Effect::getEffectData));

				// Finish up our usertype.
				state.set_usertype("tes3effect", usertypeDefinition);
			}
		}
	}
}
