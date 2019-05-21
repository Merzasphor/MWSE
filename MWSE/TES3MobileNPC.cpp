#include "TES3MobileNPC.h"

#include "LuaManager.h"

#include "LuaUtil.h"

#include "LuaCalcMovementSpeedEvent.h"
#include "LuaCalcHitArmorPieceEvent.h"

#include "TES3AudioController.h"
#include "TES3Class.h"
#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3NPC.h"
#include "TES3ItemData.h"
#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

#define TES3_MobileNPC_calcWalkSpeed 0x526F70

namespace TES3 {
	float MobileNPC::applyArmorRating(float damage, float swing, bool damageEquipment) {
		auto attackAnimState = actionData.animStateAttack;
		if (attackAnimState == AttackAnimationState::Dying || attackAnimState == AttackAnimationState::Dead || damage <= 0.001f) {
			return 0.0f;
		}

		auto dataHandler = DataHandler::get();
		auto nonDynamicData = dataHandler->nonDynamicData;
		auto worldController = WorldController::get();

		float totalAR = calculateArmorRating();

		float adjustedDamage = damage / (totalAR + damage) * damage;

		float adjustedDamageRatio = adjustedDamage / damage;
		float fCombatArmorMinMult = nonDynamicData->GMSTs[GMST::fCombatArmorMinMult]->value.asFloat;
		if (adjustedDamageRatio < fCombatArmorMinMult) {
			adjustedDamage = fCombatArmorMinMult * damage;
		}

		float armorDamage = damage - adjustedDamage;
		if (adjustedDamage < 1.0f) {
			adjustedDamage = 1.0f;
		}

		// Figure out what slot we're going to hit.
		ArmorSlot::ArmorSlot primarySlot = ArmorSlot::Invalid;
		ArmorSlot::ArmorSlot fallbackSlot = ArmorSlot::Invalid;
		int hitSlotRoll = mwse::tes3::rand() % 100;
		if (hitSlotRoll < 30) {
			primarySlot = ArmorSlot::Cuirass;
		}
		else if (hitSlotRoll < 35) {
			primarySlot = ArmorSlot::Shield;
			fallbackSlot = ArmorSlot::Cuirass;
		}
		else if (hitSlotRoll < 40) {
			primarySlot = ArmorSlot::Shield;
			fallbackSlot = ArmorSlot::LeftPauldron;
		}
		else if (hitSlotRoll < 50) {
			primarySlot = ArmorSlot::LeftPauldron;
		}
		else if (hitSlotRoll < 60) {
			primarySlot = ArmorSlot::RightPauldron;
		}
		else if (hitSlotRoll < 70) {
			primarySlot = ArmorSlot::Greaves;
		}
		else if (hitSlotRoll < 80) {
			primarySlot = ArmorSlot::Helmet;
		}
		else if (hitSlotRoll < 90) {
			primarySlot = ArmorSlot::Boots;
		}
		else if (hitSlotRoll < 95) {
			primarySlot = ArmorSlot::RightGauntlet;
			fallbackSlot = ArmorSlot::RightBracer;
		}
		else {
			primarySlot = ArmorSlot::LeftGauntlet;
			fallbackSlot = ArmorSlot::LeftBracer;
		}

		// Fire off an event to let lua change what slot is hit.
		{
			auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalcHitArmorPiece(this, primarySlot, fallbackSlot));
			if (eventData.valid()) {
				primarySlot = mwse::lua::getOptionalParam<ArmorSlot::ArmorSlot>(eventData, "slot", ArmorSlot::Invalid);
				fallbackSlot = mwse::lua::getOptionalParam<ArmorSlot::ArmorSlot>(eventData, "fallback", ArmorSlot::Invalid);
			}
		}

		// Get the equipment we're hitting.
		EquipmentStack * hitArmorStack = nullptr;
		if (primarySlot != ArmorSlot::Invalid) {
			hitArmorStack = npcInstance->getEquippedArmorBySlot(primarySlot);
			if (hitArmorStack == nullptr && fallbackSlot != ArmorSlot::Invalid) {
				hitArmorStack = npcInstance->getEquippedArmorBySlot(fallbackSlot);
			}
		}

		int hitArmorClass = -1;
		if (hitArmorStack) {
			hitArmorClass = reinterpret_cast<Armor*>(hitArmorStack->object)->getWeightClass();
			if (damageEquipment) {
				auto stackVars = hitArmorStack->variables;
				stackVars->condition -= armorDamage;
				if (stackVars->condition <= 0) {
					stackVars->condition = 0;
					npcInstance->unequipItem(hitArmorStack->object, true, this, true, nullptr);
				}
			}
		}

		TES3::Sound * hitSound = nullptr;
		if (hitArmorClass == ArmorWeightClass::Light) {
			hitSound = worldController->soundLightArmorHit;
		}
		else if (hitArmorClass == ArmorWeightClass::Medium) {
			hitSound = worldController->soundMediumArmorHit;
		}
		else if (hitArmorClass == ArmorWeightClass::Heavy) {
			hitSound = worldController->soundHeavyArmorHit;
		}

		if (hitSound) {
			// Calculate the hit volume based on the strength of the swing.
			float volume = (swing * 50.0f + 200.0f) * worldController->audioController->getMixVolume(AudioMixType::Effects);;
			dataHandler->addSound(hitSound, reference, 0, volume);
		}

		if (actorType == TES3::MobileActorType::Player) {
			TES3::SkillID::SkillID leveledSkill = TES3::SkillID::Unarmored;

			if (hitArmorClass == ArmorWeightClass::Light) {
				leveledSkill = TES3::SkillID::LightArmor;
			}
			else if (hitArmorClass == ArmorWeightClass::Medium) {
				leveledSkill = TES3::SkillID::MediumArmor;
			}
			else if (hitArmorClass == ArmorWeightClass::Heavy) {
				leveledSkill = TES3::SkillID::HeavyArmor;
			}

			float progress = nonDynamicData->skills[leveledSkill].progressActions[0];
			worldController->getMobilePlayer()->exerciseSkill(leveledSkill, progress);
		}

		return adjustedDamage;
	}

	float MobileNPC::calculateWalkSpeed() {
		// Call the original function to get the default walk value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileNPC*)>(TES3_MobileNPC_calcWalkSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		auto stateHandle = luaManager.getThreadSafeStateHandle();
		sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Walk, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	int MobileNPC::getDisposition() {
		return this->vTable.mobileNPC->getDisposition(this);
	}

	float MobileNPC::getSkillRequirement(int skillId) {
		const SkillStatistic& skill = skills[skillId];

		DataHandler* dataHandler = DataHandler::get();
		GameSetting ** gmsts = dataHandler->nonDynamicData->GMSTs;

		// Multiply requirement by skill type bonus.
		float requirement = skill.base + 1.0f;
		if (skill.type == SkillType::Misc) {
			requirement *= gmsts[GMST::fMiscSkillBonus]->value.asFloat;
		}
		else if (skill.type == SkillType::Minor) {
			requirement *= gmsts[GMST::fMinorSkillBonus]->value.asFloat;
		}
		else if (skill.type == SkillType::Major) {
			requirement *= gmsts[GMST::fMajorSkillBonus]->value.asFloat;
		}

		// Multiply requirement by specialization bonus.
		Class* classRecord = npcInstance->getClass();
		if (dataHandler->nonDynamicData->skills[skillId].specialization == classRecord->specialization) {
			requirement *= gmsts[GMST::fSpecialSkillBonus]->value.asFloat;
		}

		return requirement;
	}
}
