#pragma once

#include "TES3MobileObjectLua.h"

#include "TES3ActorAnimationData.h"
#include "TES3AIData.h"
#include "TES3Cell.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForMobileActor(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForMobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("actionBeforeCombat", sol::readonly_property(&TES3::MobileActor::actionBeforeCombat));
			usertypeDefinition.set("actionData", sol::readonly_property(&TES3::MobileActor::actionData));
			usertypeDefinition.set("activeMagicEffectList", sol::readonly_property(&TES3::MobileActor::activeMagicEffects));
			usertypeDefinition.set("actorType", sol::readonly_property(&TES3::MobileActor::actorType));
			usertypeDefinition.set("aiPlanner", sol::readonly_property(&TES3::MobileActor::aiPlanner));
			usertypeDefinition.set("alarm", &TES3::MobileActor::alarm);
			usertypeDefinition.set("barterGold", &TES3::MobileActor::barterGold);
			usertypeDefinition.set("collidingReference", sol::readonly_property(&TES3::MobileActor::collidingReference));
			usertypeDefinition.set("corpseHourstamp", &TES3::MobileActor::corpseHourstamp);
			usertypeDefinition.set("currentEnchantedItem", sol::readonly_property(&TES3::MobileActor::currentEnchantedItem));
			usertypeDefinition.set("encumbrance", sol::readonly_property(&TES3::MobileActor::encumbrance));
			usertypeDefinition.set("fatigue", sol::readonly_property(&TES3::MobileActor::fatigue));
			usertypeDefinition.set("fight", &TES3::MobileActor::fight);
			usertypeDefinition.set("flee", &TES3::MobileActor::flee);
			usertypeDefinition.set("friendlyActors", sol::readonly_property(&TES3::MobileActor::listFriendlyActors));
			usertypeDefinition.set("greetDuration", &TES3::MobileActor::greetDuration);
			usertypeDefinition.set("greetTimer", sol::readonly_property(&TES3::MobileActor::greetTimer));
			usertypeDefinition.set("health", sol::readonly_property(&TES3::MobileActor::health));
			usertypeDefinition.set("hello", &TES3::MobileActor::hello);
			usertypeDefinition.set("holdBreathTime", &TES3::MobileActor::holdBreathTime);
			usertypeDefinition.set("hostileActors", sol::readonly_property(&TES3::MobileActor::listTargetActors));
			usertypeDefinition.set("lastGroundZ", &TES3::MobileActor::lastGroundZ);
			usertypeDefinition.set("magicka", sol::readonly_property(&TES3::MobileActor::magicka));
			usertypeDefinition.set("magickaMultiplier", sol::readonly_property(&TES3::MobileActor::magickaMultiplier));
			usertypeDefinition.set("nextActionWeight", sol::readonly_property(&TES3::MobileActor::nextActionWeight));
			//usertypeDefinition.set("powers", sol::readonly_property(&TES3::MobileActor::powers));
			usertypeDefinition.set("readiedAmmo", &TES3::MobileActor::readiedAmmo);
			usertypeDefinition.set("readiedAmmoCount", &TES3::MobileActor::readiedAmmoCount);
			usertypeDefinition.set("readiedShield", &TES3::MobileActor::readiedShield);
			usertypeDefinition.set("readiedWeapon", &TES3::MobileActor::readiedWeapon);
			usertypeDefinition.set("scanInterval", sol::readonly_property(&TES3::MobileActor::scanInterval));
			usertypeDefinition.set("scanTimer", sol::readonly_property(&TES3::MobileActor::scanTimer));
			usertypeDefinition.set("torchSlot", &TES3::MobileActor::torchSlot);
			usertypeDefinition.set("width", sol::readonly_property(&TES3::MobileActor::widthInUnits));

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("animationData", sol::readonly_property([](TES3::MobileActor& self) { return self.animationData.asActor; }));
			usertypeDefinition.set("attributes", sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.attributes); }));
			usertypeDefinition.set("currentSpell", sol::readonly_property([](TES3::MobileActor& self) { return makeLuaObject(self.currentSpell.source.asGeneric); }));
			usertypeDefinition.set("effectAttributes", sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.effectAttributes); }));

			// Friendly access to actor flags.
			usertypeDefinition.set("activeAI", sol::property(
				[](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::ActiveAI); },
				[](TES3::MobileActor& self, bool set) { self.setMobileActorFlag(TES3::MobileActorFlag::ActiveAI, set); }
			));
			usertypeDefinition.set("attacked", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Attacked); }));
			usertypeDefinition.set("idleAnim", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IdleAnim); }));
			usertypeDefinition.set("inCombat", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::InCombat); }));
			usertypeDefinition.set("isCrittable", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IsCrittable); }));
			usertypeDefinition.set("spellReadied", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::SpellReadied); }));
			usertypeDefinition.set("underwater", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Underwater); }));
			usertypeDefinition.set("weaponDrawn", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::WeaponDrawn); }));
			usertypeDefinition.set("werewolf", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Werewolf); }));

			// Provide some friendly exposure to attributes by name.
			usertypeDefinition.set("agility", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Agility]; }));
			usertypeDefinition.set("endurance", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Endurance]; }));
			usertypeDefinition.set("intelligence", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Intelligence]; }));
			usertypeDefinition.set("luck", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Luck]; }));
			usertypeDefinition.set("personality", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Personality]; }));
			usertypeDefinition.set("speed", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Speed]; }));
			usertypeDefinition.set("strength", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Strength]; }));
			usertypeDefinition.set("willpower", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Willpower]; }));

			// Provide some friendly exposure to effect attributes.
			usertypeDefinition.set("attackBonus", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::AttackBonus]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::AttackBonus] = value; }
			));
			usertypeDefinition.set("blind", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Blind]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Blind] = value; }
			));
			usertypeDefinition.set("chameleon", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Chameleon]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Chameleon] = value; }
			));
			usertypeDefinition.set("invisibility", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Invisibility]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Invisibility] = value; }
			));
			usertypeDefinition.set("jump", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Jump]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Jump] = value; }
			));
			usertypeDefinition.set("levitate", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Levitate]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Levitate] = value; }
			));
			usertypeDefinition.set("paralyze", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Paralyze]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Paralyze] = value; }
			));
			usertypeDefinition.set("resistBlightDisease", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistBlightDisease]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistBlightDisease] = value; }
			));
			usertypeDefinition.set("resistCommonDisease", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistCommonDisease]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistCommonDisease] = value; }
			));
			usertypeDefinition.set("resistCorprus", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistCorprus]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistCorprus] = value; }
			));
			usertypeDefinition.set("resistFire", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistFire]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistFire] = value; }
			));
			usertypeDefinition.set("resistFrost", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistFrost]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistFrost] = value; }
			));
			usertypeDefinition.set("resistMagicka", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistMagicka]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistMagicka] = value; }
			));
			usertypeDefinition.set("resistNormalWeapons", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistNormalWeapons]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistNormalWeapons] = value; }
			));
			usertypeDefinition.set("resistParalysis", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistParalysis]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistParalysis] = value; }
			));
			usertypeDefinition.set("resistPoison", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistPoison]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistPoison] = value; }
			));
			usertypeDefinition.set("resistShock", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistShock]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistShock] = value; }
			));
			usertypeDefinition.set("sanctuary", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Sanctuary]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Sanctuary] = value; }
			));
			usertypeDefinition.set("shield", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Shield]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Shield] = value; }
			));
			usertypeDefinition.set("silence", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Silence]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Silence] = value; }
			));
			usertypeDefinition.set("sound", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Sound]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Sound] = value; }
			));
			usertypeDefinition.set("swiftSwim", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::SwiftSwim]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::SwiftSwim] = value; }
			));
			usertypeDefinition.set("waterBreathing", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::WaterBreathing]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::WaterBreathing] = value; }
			));
			usertypeDefinition.set("waterWalking", sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::WaterWalking]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::WaterWalking] = value; }
			));

			// Provide some friendly exposure for movement flags.
			usertypeDefinition.set("isFlying", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Flying)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Flying, state); }
			));
			usertypeDefinition.set("isJumping", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Jumping)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Jumping, state); }
			));
			usertypeDefinition.set("isMovingBack", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Back)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Back, state); }
			));
			usertypeDefinition.set("isMovingForward", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Forward)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Forward, state); }
			));
			usertypeDefinition.set("isMovingLeft", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Left)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Left, state); }
			));
			usertypeDefinition.set("isMovingRight", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Right)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Right, state); }
			));
			usertypeDefinition.set("isRunning", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Running)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Running, state); }
			));
			usertypeDefinition.set("isSneaking", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Sneaking)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Sneaking, state); }
			));
			usertypeDefinition.set("isStartingJump", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Jumped)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Jumped, state); }
			));
			usertypeDefinition.set("isSwimming", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Swimming)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Swimming, state); }
			));
			usertypeDefinition.set("isTurningLeft", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::TurnLeft)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::TurnLeft, state); }
			));
			usertypeDefinition.set("isTurningRight", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::TurnRight)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::TurnRight, state); }
			));
			usertypeDefinition.set("isWalking", sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Walking)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Walking, state); }
			));

			// Basic function binding.
			usertypeDefinition.set("applyHealthDamage", &TES3::MobileActor::applyHealthDamage);
			usertypeDefinition.set("getSkillStatistic", &TES3::MobileActor::getSkillStatistic);
			usertypeDefinition.set("getSkillValue", &TES3::MobileActor::getSkillValue);
			usertypeDefinition.set("startCombat", &TES3::MobileActor::startCombat);
			usertypeDefinition.set("startDialogue", &TES3::MobileActor::startDialogue);
			usertypeDefinition.set("stopCombat", &TES3::MobileActor::stopCombat);
			usertypeDefinition.set("updateDerivedStatistics", &TES3::MobileActor::updateDerivedStatistics);

			// Provide single function for isAffectedByAlchemy, etc.
			usertypeDefinition.set("isAffectedByObject", [](TES3::MobileActor& self, sol::object param) {
				if (param.is<TES3::Alchemy>()) {
					return self.isAffectedByAlchemy(param.as<TES3::Alchemy*>());
				}
				else if (param.is<TES3::Enchantment>()) {
					return self.isAffectedByEnchantment(param.as<TES3::Enchantment*>());
				}
				else if (param.is<TES3::Spell>()) {
					return self.isAffectedBySpell(param.as<TES3::Spell*>());
				}

				return false;
			});

			// Functions exposed as properties.
			usertypeDefinition.set("cell", sol::property(&TES3::MobileActor::getCell));
			usertypeDefinition.set("hasFreeAction", sol::property(&TES3::MobileActor::hasFreeAction));

			// Legacy support for old structures.
			usertypeDefinition.set("activeMagicEffects", sol::readonly_property([](TES3::MobileActor& self) { return self.activeMagicEffects.firstEffect; }));
			usertypeDefinition.set("activeMagicEffectCount", sol::readonly_property([](TES3::MobileActor& self) { return self.activeMagicEffects.count; }));
		}

		void bindTES3MobileActor();
	}
}
