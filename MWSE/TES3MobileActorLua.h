#pragma once

#include "TES3MobileObjectLua.h"

#include "TES3ActorAnimationData.h"
#include "TES3AIData.h"
#include "TES3Cell.h"
#include "TES3CombatSession.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForMobileActor(T& usertypeDefinition) {
			setUserdataForMobileObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["actionBeforeCombat"] = sol::readonly_property(&TES3::MobileActor::actionBeforeCombat);
			usertypeDefinition["actionData"] = sol::readonly_property(&TES3::MobileActor::actionData);
			usertypeDefinition["activeMagicEffectList"] = sol::readonly_property(&TES3::MobileActor::activeMagicEffects);
			usertypeDefinition["actorType"] = sol::readonly_property(&TES3::MobileActor::actorType);
			usertypeDefinition["aiPlanner"] = sol::readonly_property(&TES3::MobileActor::aiPlanner);
			usertypeDefinition["alarm"] = &TES3::MobileActor::alarm;
			usertypeDefinition["barterGold"] = &TES3::MobileActor::barterGold;
			usertypeDefinition["collidingReference"] = sol::readonly_property(&TES3::MobileActor::collidingReference);
			usertypeDefinition["combatSession"] = sol::readonly_property(&TES3::MobileActor::combatSession);
			usertypeDefinition["corpseHourstamp"] = &TES3::MobileActor::corpseHourstamp;
			usertypeDefinition["currentEnchantedItem"] = sol::readonly_property(&TES3::MobileActor::currentEnchantedItem);
			usertypeDefinition["encumbrance"] = sol::readonly_property(&TES3::MobileActor::encumbrance);
			usertypeDefinition["fatigue"] = sol::readonly_property(&TES3::MobileActor::fatigue);
			usertypeDefinition["fight"] = &TES3::MobileActor::fight;
			usertypeDefinition["flee"] = &TES3::MobileActor::flee;
			usertypeDefinition["friendlyActors"] = sol::readonly_property(&TES3::MobileActor::listFriendlyActors);
			usertypeDefinition["greetDuration"] = &TES3::MobileActor::greetDuration;
			usertypeDefinition["greetTimer"] = sol::readonly_property(&TES3::MobileActor::greetTimer);
			usertypeDefinition["health"] = sol::readonly_property(&TES3::MobileActor::health);
			usertypeDefinition["hello"] = &TES3::MobileActor::hello;
			usertypeDefinition["holdBreathTime"] = &TES3::MobileActor::holdBreathTime;
			usertypeDefinition["hostileActors"] = sol::readonly_property(&TES3::MobileActor::listTargetActors);
			usertypeDefinition["isDead"] = sol::readonly_property(&TES3::MobileActor::isDead);
			usertypeDefinition["lastGroundZ"] = &TES3::MobileActor::lastGroundZ;
			usertypeDefinition["magicka"] = sol::readonly_property(&TES3::MobileActor::magicka);
			usertypeDefinition["magickaMultiplier"] = sol::readonly_property(&TES3::MobileActor::magickaMultiplier);
			usertypeDefinition["nextActionWeight"] = sol::readonly_property(&TES3::MobileActor::nextActionWeight);
			//usertypeDefinition["powers"] = sol::readonly_property(&TES3::MobileActor::powers);
			usertypeDefinition["readiedAmmo"] = &TES3::MobileActor::readiedAmmo;
			usertypeDefinition["readiedAmmoCount"] = &TES3::MobileActor::readiedAmmoCount;
			usertypeDefinition["readiedShield"] = &TES3::MobileActor::readiedShield;
			usertypeDefinition["readiedWeapon"] = &TES3::MobileActor::readiedWeapon;
			usertypeDefinition["scanInterval"] = sol::readonly_property(&TES3::MobileActor::scanInterval);
			usertypeDefinition["scanTimer"] = sol::readonly_property(&TES3::MobileActor::scanTimer);
			usertypeDefinition["torchSlot"] = &TES3::MobileActor::torchSlot;
			usertypeDefinition["width"] = sol::readonly_property(&TES3::MobileActor::widthInUnits);

			// Indirect bindings to unions and arrays.
			usertypeDefinition["animationData"] = sol::readonly_property([](TES3::MobileActor& self) { return self.animationData.asActor; });
			usertypeDefinition["attributes"] = sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.attributes); });
			usertypeDefinition["currentSpell"] = sol::readonly_property([](TES3::MobileActor& self) { return self.currentSpell.source.asGeneric; });
			usertypeDefinition["effectAttributes"] = sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.effectAttributes); });

			// Friendly access to actor flags.
			usertypeDefinition["activeAI"] = sol::property(
				[](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::ActiveAI); },
				[](TES3::MobileActor& self, bool set) { self.setMobileActorFlag(TES3::MobileActorFlag::ActiveAI, set); }
			);
			usertypeDefinition["attacked"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Attacked); });
			usertypeDefinition["idleAnim"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IdleAnim); });
			usertypeDefinition["inCombat"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::InCombat); });
			usertypeDefinition["isCrittable"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IsCrittable); });
			usertypeDefinition["spellReadied"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::SpellReadied); });
			usertypeDefinition["underwater"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Underwater); });
			usertypeDefinition["weaponDrawn"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::WeaponDrawn); });
			usertypeDefinition["werewolf"] = sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Werewolf); });

			// Provide some friendly exposure to attributes by name.
			usertypeDefinition["agility"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Agility]; });
			usertypeDefinition["endurance"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Endurance]; });
			usertypeDefinition["intelligence"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Intelligence]; });
			usertypeDefinition["luck"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Luck]; });
			usertypeDefinition["personality"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Personality]; });
			usertypeDefinition["speed"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Speed]; });
			usertypeDefinition["strength"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Strength]; });
			usertypeDefinition["willpower"] = sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Willpower]; });

			// Provide some friendly exposure to effect attributes.
			usertypeDefinition["attackBonus"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::AttackBonus]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::AttackBonus] = value; }
			);
			usertypeDefinition["blind"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Blind]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Blind] = value; }
			);
			usertypeDefinition["chameleon"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Chameleon]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Chameleon] = value; }
			);
			usertypeDefinition["invisibility"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Invisibility]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Invisibility] = value; }
			);
			usertypeDefinition["jump"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Jump]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Jump] = value; }
			);
			usertypeDefinition["levitate"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Levitate]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Levitate] = value; }
			);
			usertypeDefinition["paralyze"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Paralyze]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Paralyze] = value; }
			);
			usertypeDefinition["resistBlightDisease"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistBlightDisease]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistBlightDisease] = value; }
			);
			usertypeDefinition["resistCommonDisease"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistCommonDisease]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistCommonDisease] = value; }
			);
			usertypeDefinition["resistCorprus"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistCorprus]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistCorprus] = value; }
			);
			usertypeDefinition["resistFire"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistFire]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistFire] = value; }
			);
			usertypeDefinition["resistFrost"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistFrost]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistFrost] = value; }
			);
			usertypeDefinition["resistMagicka"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistMagicka]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistMagicka] = value; }
			);
			usertypeDefinition["resistNormalWeapons"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistNormalWeapons]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistNormalWeapons] = value; }
			);
			usertypeDefinition["resistParalysis"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistParalysis]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistParalysis] = value; }
			);
			usertypeDefinition["resistPoison"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistPoison]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistPoison] = value; }
			);
			usertypeDefinition["resistShock"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::ResistShock]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::ResistShock] = value; }
			);
			usertypeDefinition["sanctuary"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Sanctuary]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Sanctuary] = value; }
			);
			usertypeDefinition["shield"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Shield]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Shield] = value; }
			);
			usertypeDefinition["silence"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Silence]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Silence] = value; }
			);
			usertypeDefinition["sound"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::Sound]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::Sound] = value; }
			);
			usertypeDefinition["swiftSwim"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::SwiftSwim]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::SwiftSwim] = value; }
			);
			usertypeDefinition["waterBreathing"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::WaterBreathing]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::WaterBreathing] = value; }
			);
			usertypeDefinition["waterWalking"] = sol::property(
				[](TES3::MobileActor& self) { return self.effectAttributes[TES3::EffectAttribute::WaterWalking]; },
				[](TES3::MobileActor& self, int value) { self.effectAttributes[TES3::EffectAttribute::WaterWalking] = value; }
			);

			// Provide some friendly exposure for movement flags.
			usertypeDefinition["isFlying"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Flying)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Flying, state); }
			);
			usertypeDefinition["isJumping"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Jumping)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Jumping, state); }
			);
			usertypeDefinition["isMovingBack"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Back)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Back, state); }
			);
			usertypeDefinition["isMovingForward"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Forward)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Forward, state); }
			);
			usertypeDefinition["isMovingLeft"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Left)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Left, state); }
			);
			usertypeDefinition["isMovingRight"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Right)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Right, state); }
			);
			usertypeDefinition["isRunning"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Running)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Running, state); }
			);
			usertypeDefinition["isSneaking"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Sneaking)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Sneaking, state); }
			);
			usertypeDefinition["isStartingJump"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Jumped)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Jumped, state); }
			);
			usertypeDefinition["isSwimming"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Swimming)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Swimming, state); }
			);
			usertypeDefinition["isTurningLeft"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::TurnLeft)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::TurnLeft, state); }
			);
			usertypeDefinition["isTurningRight"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::TurnRight)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::TurnRight, state); }
			);
			usertypeDefinition["isWalking"] = sol::property(
				[](TES3::MobileActor& self) { return (self.getMobileActorMovementFlag(TES3::ActorMovement::Walking)); },
				[](TES3::MobileActor& self, bool state) { self.setMobileActorMovementFlag(TES3::ActorMovement::Walking, state); }
			);

			// Basic function binding.
			usertypeDefinition["applyHealthDamage"] = &TES3::MobileActor::applyHealthDamage;
			usertypeDefinition["getSkillStatistic"] = &TES3::MobileActor::getSkillStatistic;
			usertypeDefinition["getSkillValue"] = &TES3::MobileActor::getSkillValue;
			usertypeDefinition["startCombat"] = &TES3::MobileActor::startCombat;
			usertypeDefinition["startDialogue"] = &TES3::MobileActor::startDialogue;
			usertypeDefinition["stopCombat"] = &TES3::MobileActor::stopCombat;
			usertypeDefinition["updateDerivedStatistics"] = &TES3::MobileActor::updateDerivedStatistics;
			usertypeDefinition["updateOpacity"] = &TES3::MobileActor::updateOpacity;

			// Provide single function for isAffectedByAlchemy, etc.
			usertypeDefinition["isAffectedByObject"] = [](TES3::MobileActor& self, sol::object param) {
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
			};

			// Functions exposed as properties.
			usertypeDefinition["cell"] = sol::property(&TES3::MobileActor::getCell);
			usertypeDefinition["hasFreeAction"] = sol::property(&TES3::MobileActor::hasFreeAction);

			// Legacy support for old structures.
			usertypeDefinition["activeMagicEffects"] = sol::readonly_property([](TES3::MobileActor& self) { return self.activeMagicEffects.firstEffect; });
			usertypeDefinition["activeMagicEffectCount"] = sol::readonly_property([](TES3::MobileActor& self) { return self.activeMagicEffects.count; });
		}

		void bindTES3MobileActor();
	}
}
