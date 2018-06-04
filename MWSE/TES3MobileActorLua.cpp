#include "TES3MobilePlayerLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MobileActor.h"
#include "TES3ActorAnimationData.h"
#include "TES3Cell.h"
#include "TES3Spell.h"
#include "TES3Statistic.h"
#include "TES3Weapon.h"

namespace mwse {
	namespace lua {
		void bindTES3MobileActor() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype for TES3::MobileActor. We must finish this with state.set_usertype.
			auto mobileActorUsertype = state.create_simple_usertype<TES3::MobileActor>();

			// We inherit MobileObject.
			mobileActorUsertype.set(sol::base_classes, sol::bases<TES3::MobileObject>());

			// Basic property binding.
			mobileActorUsertype.set("friendlyActors", sol::readonly_property(&TES3::MobileActor::listFriendlyActors));
			mobileActorUsertype.set("hostileActors", sol::readonly_property(&TES3::MobileActor::listTargetActors));
			mobileActorUsertype.set("scanTimer", sol::readonly_property(&TES3::MobileActor::scanTimer));
			mobileActorUsertype.set("scanInterval", sol::readonly_property(&TES3::MobileActor::scanInterval));
			mobileActorUsertype.set("greetTimer", sol::readonly_property(&TES3::MobileActor::greetTimer));
			mobileActorUsertype.set("actionData", sol::readonly_property(&TES3::MobileActor::actionData));
			mobileActorUsertype.set("actionBeforeCombat", sol::readonly_property(&TES3::MobileActor::actionBeforeCombat));
			//mobileActorUsertype.set("activeMagicEffects", sol::readonly_property(&TES3::MobileActor::activeMagicEffects));
			mobileActorUsertype.set("activeMagicEffectCount", sol::readonly_property(&TES3::MobileActor::activeMagicEffectCount));
			//mobileActorUsertype.set("powers", sol::readonly_property(&TES3::MobileActor::powers));
			mobileActorUsertype.set("nextActionWeight", sol::readonly_property(&TES3::MobileActor::nextActionWeight));
			mobileActorUsertype.set("actorType", sol::readonly_property(&TES3::MobileActor::actorType));
			mobileActorUsertype.set("lastGroundZ", &TES3::MobileActor::lastGroundZ);
			mobileActorUsertype.set("collidingReference", sol::readonly_property(&TES3::MobileActor::collidingReference));
			mobileActorUsertype.set("health", sol::readonly_property(&TES3::MobileActor::health));
			mobileActorUsertype.set("magicka", sol::readonly_property(&TES3::MobileActor::magicka));
			mobileActorUsertype.set("encumbrance", sol::readonly_property(&TES3::MobileActor::encumbrance));
			mobileActorUsertype.set("fatigue", sol::readonly_property(&TES3::MobileActor::fatigue));
			mobileActorUsertype.set("magickaMultiplier", sol::readonly_property(&TES3::MobileActor::magickaMultiplier));
			mobileActorUsertype.set("health", sol::readonly_property(&TES3::MobileActor::health));
			mobileActorUsertype.set("fight", &TES3::MobileActor::fight);
			mobileActorUsertype.set("flee", &TES3::MobileActor::flee);
			mobileActorUsertype.set("hello", &TES3::MobileActor::hello);
			mobileActorUsertype.set("alarm", &TES3::MobileActor::alarm);
			mobileActorUsertype.set("barterGold", &TES3::MobileActor::barterGold);
			mobileActorUsertype.set("width", sol::readonly_property(&TES3::MobileActor::widthInUnits));
			mobileActorUsertype.set("readiedAmmoCount", sol::readonly_property(&TES3::MobileActor::readiedAmmoCount));
			mobileActorUsertype.set("corpseHourstamp", &TES3::MobileActor::corpseHourstamp);
			mobileActorUsertype.set("greetDuration", &TES3::MobileActor::greetDuration);
			mobileActorUsertype.set("holdBreathTime", &TES3::MobileActor::holdBreathTime);
			mobileActorUsertype.set("currentSpell", &TES3::MobileActor::currentSpell);
			mobileActorUsertype.set("spellSource", sol::readonly_property(&TES3::MobileActor::spellSource));
			mobileActorUsertype.set("currentEnchItem", &TES3::MobileActor::currentEnchItem);
			mobileActorUsertype.set("currentEnchItemData", &TES3::MobileActor::currentEnchItemData);
			mobileActorUsertype.set("readiedWeapon", &TES3::MobileActor::readiedWeapon);
			mobileActorUsertype.set("readiedAmmo", &TES3::MobileActor::readiedAmmo);
			mobileActorUsertype.set("readiedShield", &TES3::MobileActor::readiedShield);
			mobileActorUsertype.set("torchSlot", &TES3::MobileActor::torchSlot);

			// Indirect bindings to unions and arrays.
			mobileActorUsertype.set("animationData", sol::readonly_property([](TES3::MobileActor& self) { return self.animationData.asActor; }));
			mobileActorUsertype.set("attributes", sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.attributes); }));
			mobileActorUsertype.set("effectAttributes", sol::readonly_property([](TES3::MobileActor& self) { return std::ref(self.effectAttributes); }));

			// Friendly access to actor flags.
			mobileActorUsertype.set("activeAI", sol::property(
				[](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::ActiveAI); },
				[](TES3::MobileActor& self, bool set) { self.setMobileActorFlag(TES3::MobileActorFlag::ActiveAI, set); }
			));
			mobileActorUsertype.set("werewolf", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Werewolf); }));
			mobileActorUsertype.set("underwater", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Underwater); }));
			mobileActorUsertype.set("weaponDrawn", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::WeaponDrawn); }));
			mobileActorUsertype.set("spellReadied", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::SpellReadied); }));
			mobileActorUsertype.set("inCombat", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::InCombat); }));
			mobileActorUsertype.set("attacked", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::Attacked); }));
			mobileActorUsertype.set("isCrittable", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IsCrittable); }));
			mobileActorUsertype.set("idleAnim", sol::property([](TES3::MobileActor& self) { return self.getMobileActorFlag(TES3::MobileActorFlag::IdleAnim); }));

			// Provide some friendly exposure to attributes by name.
			mobileActorUsertype.set("strength", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Strength]; }));
			mobileActorUsertype.set("intelligence", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Intelligence]; }));
			mobileActorUsertype.set("willpower", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Willpower]; }));
			mobileActorUsertype.set("agility", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Agility]; }));
			mobileActorUsertype.set("speed", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Speed]; }));
			mobileActorUsertype.set("endurance", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Endurance]; }));
			mobileActorUsertype.set("personality", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Personality]; }));
			mobileActorUsertype.set("luck", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::Attribute::Luck]; }));

			// Provide some friendly exposure to effect attributes.
			mobileActorUsertype.set("attackBonus", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::AttackBonus]; }));
			mobileActorUsertype.set("sanctuary", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Sanctuary]; }));
			mobileActorUsertype.set("resistMagicka", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistMagicka]; }));
			mobileActorUsertype.set("resistFire", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistFire]; }));
			mobileActorUsertype.set("resistFrost", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistFrost]; }));
			mobileActorUsertype.set("resistShock", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistShock]; }));
			mobileActorUsertype.set("resistCommonDisease", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistCommonDisease]; }));
			mobileActorUsertype.set("resistBlightDisease", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistBlightDisease]; }));
			mobileActorUsertype.set("resistCorprus", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistCorprus]; }));
			mobileActorUsertype.set("resistPoison", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistPoison]; }));
			mobileActorUsertype.set("resistParalysis", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistParalysis]; }));
			mobileActorUsertype.set("chameleon", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Chameleon]; }));
			mobileActorUsertype.set("resistNormalWeapons", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::ResistNormalWeapons]; }));
			mobileActorUsertype.set("waterBreathing", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::WaterBreathing]; }));
			mobileActorUsertype.set("waterWalking", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::WaterWalking]; }));
			mobileActorUsertype.set("swiftSwim", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::SwiftSwim]; }));
			mobileActorUsertype.set("jump", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Jump]; }));
			mobileActorUsertype.set("levitate", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Levitate]; }));
			mobileActorUsertype.set("shield", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Shield]; }));
			mobileActorUsertype.set("sound", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Sound]; }));
			mobileActorUsertype.set("silence", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Silence]; }));
			mobileActorUsertype.set("blind", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Blind]; }));
			mobileActorUsertype.set("paralyze", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Paralyze]; }));
			mobileActorUsertype.set("invisibility", sol::readonly_property([](TES3::MobileActor& self) { return &self.attributes[TES3::EffectAttribute::Invisibility]; }));

			// Basic function binding.
			mobileActorUsertype.set("startCombat", &TES3::MobileActor::startCombat);
			mobileActorUsertype.set("stopCombat", &TES3::MobileActor::stopCombat);
			mobileActorUsertype.set("applyHealthDamage", &TES3::MobileActor::applyHealthDamage);

			// Functions exposed as read-only properties.
			mobileActorUsertype.set("cell", sol::readonly_property(&TES3::MobileActor::getCell));
			mobileActorUsertype.set("hasFreeAction", sol::readonly_property(&TES3::MobileActor::hasFreeAction));

			// Finish up our usertype.
			state.set_usertype("TES3MobileActor", mobileActorUsertype);
		}
	}
}