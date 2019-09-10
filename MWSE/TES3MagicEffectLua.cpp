#include "TES3MagicEffectLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3MagicEffect.h"
#include "TES3MagicEffectController.h"

namespace mwse {
	namespace lua {
		void bindTES3MagicEffect() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::MagicEffect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::MagicEffect>("tes3magicEffect");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["areaVisualEffect"] = &TES3::MagicEffect::areaEffect;
				usertypeDefinition["baseMagickaCost"] = &TES3::MagicEffect::baseMagickaCost;
				usertypeDefinition["boltVisualEffect"] = &TES3::MagicEffect::boltEffect;
				usertypeDefinition["castVisualEffect"] = &TES3::MagicEffect::castEffect;
				usertypeDefinition["flags"] = &TES3::MagicEffect::flags;
				usertypeDefinition["hitVisualEffect"] = &TES3::MagicEffect::hitEffect;
				usertypeDefinition["id"] = sol::readonly_property(&TES3::MagicEffect::id);
				usertypeDefinition["lightingBlue"] = &TES3::MagicEffect::lightingBlue;
				usertypeDefinition["lightingGreen"] = &TES3::MagicEffect::lightingGreen;
				usertypeDefinition["lightingRed"] = &TES3::MagicEffect::lightingRed;
				usertypeDefinition["school"] = &TES3::MagicEffect::school;
				usertypeDefinition["size"] = &TES3::MagicEffect::size;
				usertypeDefinition["sizeCap"] = &TES3::MagicEffect::sizeCap;
				usertypeDefinition["speed"] = &TES3::MagicEffect::speed;

				// Allow access to base effect flags.
				usertypeDefinition["baseFlags"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlags(self.id); },
					[](TES3::MagicEffect& self, double value) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlags(self.id, value); }
				);

				// User-friendly access to those base effects.
				usertypeDefinition["targetsSkills"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::TargetSkillBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::TargetSkillBit, set); }
				);
				usertypeDefinition["targetsAttributes"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::TargetAttributeBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::TargetAttributeBit, set); }
				);
				usertypeDefinition["hasNoDuration"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::NoDurationBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::NoDurationBit, set); }
				);
				usertypeDefinition["hasNoMagnitude"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::NoMagnitudeBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::NoMagnitudeBit, set); }
				);
				usertypeDefinition["isHarmful"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::HarmfulBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::HarmfulBit, set); }
				);
				usertypeDefinition["hasContinuousVFX"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::ContinuousVFXBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::ContinuousVFXBit, set); }
				);
				usertypeDefinition["canCastSelf"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::CanCastSelfBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::CanCastSelfBit, set); }
				);
				usertypeDefinition["canCastTouch"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::CanCastTouchBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::CanCastTouchBit, set); }
				);
				usertypeDefinition["canCastTarget"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::CanCastTargetBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::CanCastTargetBit, set); }
				);
				usertypeDefinition["allowSpellmaking"] = sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowSpellmaking) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowSpellmaking; }
				);
				usertypeDefinition["allowEnchanting"] = sol::property(
					[](TES3::MagicEffect& self) { return (self.flags & TES3::EffectFlag::AllowEnchanting) != 0; },
					[](TES3::MagicEffect& self) { self.flags |= TES3::EffectFlag::AllowEnchanting; }
				);
				usertypeDefinition["usesNegativeLighting"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::NegativeLightingBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::NegativeLightingBit, set); }
				);
				usertypeDefinition["appliesOnce"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::AppliedOnceBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::AppliedOnceBit, set); }
				);
				usertypeDefinition["nonRecastable"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::NonRecastableBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::NonRecastableBit, set); }
				);
				usertypeDefinition["illegalDaedra"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::IllegalDaedraBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::IllegalDaedraBit, set); }
				);
				usertypeDefinition["unreflectable"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::UnreflectableBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::UnreflectableBit, set); }
				);
				usertypeDefinition["casterLinked"] = sol::property(
					[](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectFlag(self.id, TES3::EffectFlag::CasterLinkedBit); },
					[](TES3::MagicEffect& self, bool set) { TES3::DataHandler::get()->nonDynamicData->magicEffects->setEffectFlag(self.id, TES3::EffectFlag::CasterLinkedBit, set); }
				);

				// Functions exposed as properties.
				usertypeDefinition["name"] = sol::readonly_property([](TES3::MagicEffect& self) { return TES3::DataHandler::get()->nonDynamicData->magicEffects->getEffectName(self.id); });
				usertypeDefinition["areaSoundEffect"] = sol::readonly_property([](TES3::MagicEffect& self) { return self.areaSoundEffect; });
				usertypeDefinition["boltSoundEffect"] = sol::readonly_property([](TES3::MagicEffect& self) { return self.boltSoundEffect; });
				usertypeDefinition["castSoundEffect"] = sol::readonly_property([](TES3::MagicEffect& self) { return self.castSoundEffect; });
				usertypeDefinition["hitSoundEffect"] = sol::readonly_property([](TES3::MagicEffect& self) { return self.hitSoundEffect; });
				usertypeDefinition["icon"] = sol::property(
					[](TES3::MagicEffect& self) { return self.icon; },
					[](TES3::MagicEffect& self, const char* value) { if (strlen(value) < 32) strcpy(self.icon, value); }
				);
				usertypeDefinition["particleTexture"] = sol::readonly_property([](TES3::MagicEffect& self) { return self.particleTexture; });
			}

			// Binding for TES3::Effect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Effect>("tes3effect");
				usertypeDefinition["new"] = sol::no_constructor;

				// Convert to string.
				usertypeDefinition[sol::meta_function::to_string] = [](TES3::Effect& self) -> sol::optional<std::string> {
					if (self.effectID == -1) {
						return sol::optional<std::string>();
					}
					return self.toString();
				};

				// Basic property binding.
				usertypeDefinition["attribute"] = &TES3::Effect::attributeID;
				usertypeDefinition["duration"] = &TES3::Effect::duration;
				usertypeDefinition["id"] = &TES3::Effect::effectID;
				usertypeDefinition["max"] = &TES3::Effect::magnitudeMax;
				usertypeDefinition["min"] = &TES3::Effect::magnitudeMin;
				usertypeDefinition["radius"] = &TES3::Effect::radius;
				usertypeDefinition["rangeType"] = &TES3::Effect::rangeType;
				usertypeDefinition["skill"] = &TES3::Effect::skillID;

				// Allow easy access to the base magic effect.
				usertypeDefinition["object"] = sol::readonly_property(&TES3::Effect::getEffectData);
			}
		}
	}
}
