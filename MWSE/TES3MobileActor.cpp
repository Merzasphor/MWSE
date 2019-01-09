#include "TES3MobileActor.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaCalcMovementSpeedEvent.h"
#include "LuaCombatStartedEvent.h"
#include "LuaCombatStartEvent.h"
#include "LuaCombatStopEvent.h"
#include "LuaCombatStoppedEvent.h"
#include "LuaDamagedEvent.h"
#include "LuaDamageEvent.h"
#include "LuaDeathEvent.h"
#include "LuaMobileObjectCollisionEvent.h"

#include "TES3Actor.h"
#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3Reference.h"
#include "TES3Util.h"

#define TES3_MobileActor_onActorCollision 0x5234A0
#define TES3_MobileActor_onObjectCollision 0x5233B0
#define TES3_MobileActor_onTerrainCollision 0x523310
#define TES3_MobileActor_onActivatorCollision 0x523590
#define TES3_MobileActor_getCell 0x521630
#define TES3_MobileActor_startCombat 0x530470
#define TES3_MobileActor_stopCombat 0x558720
#define TES3_MobileActor_onDeath 0x523AA0
#define TES3_MobileActor_applyHealthDamage 0x557CF0
#define TES3_MobileActor_hasFreeAction 0x527580
#define TES3_MobileActor_calculateRunSpeed 0x527050
#define TES3_MobileActor_calculateSwimSpeed 0x5270B0
#define TES3_MobileActor_calculateSwimRunSpeed 0x527130
#define TES3_MobileActor_calculateFlySpeed 0x5271F0

namespace TES3 {
	const auto TES3_MobileActor_isInAttackAnim = reinterpret_cast<bool (__thiscall*)(const MobileActor*)>(0x5567D0);
	const auto TES3_MobileActor_wearItem = reinterpret_cast<void (__thiscall*)(MobileActor*, Object*, ItemData*, bool, bool)>(0x52C770);
	const auto TES3_MobileActor_calcDerivedStats = reinterpret_cast<void(__thiscall*)(const MobileActor*, Statistic*)>(0x527BC0);
	const auto TES3_MobileActor_determineModifiedPrice = reinterpret_cast<int(__thiscall*)(const MobileActor*, int, int)>(0x52AA50);
	const auto TES3_MobileActor_playVoiceover = reinterpret_cast<void(__thiscall*)(const MobileActor*, int)>(0x528F80);

	signed char MobileActor::onActorCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileActor_onActorCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileActor::onObjectCollision(int hitReferenceIndex, signed char flag) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int, signed char)>(TES3_MobileActor_onObjectCollision)(this, hitReferenceIndex, flag);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileActor::onTerrainCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileActor_onTerrainCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	signed char MobileActor::onActivatorCollision(int hitReferenceIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->hitReferences->hit[hitReferenceIndex].reference;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		signed char result = reinterpret_cast<char(__thiscall *)(MobileObject*, int)>(TES3_MobileActor_onActivatorCollision)(this, hitReferenceIndex);

		// Fire off our hit event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));

		return result;
	}

	SkillStatistic * MobileActor::getSkillStatistic(int skillId) {
		return vTable.mobileActor->getSkillStatistic(this, skillId);
	}

	float MobileActor::getSkillValue(int skillId) {
		return vTable.mobileActor->getSkillValue(this, skillId);
	}

	Cell* MobileActor::getCell() {
		return reinterpret_cast<Cell*(__thiscall *)(MobileActor*)>(TES3_MobileActor_getCell)(this);
	}

	void MobileActor::startCombat(MobileActor* target) {
		// Invoke our first event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CombatStartEvent(this, target));
		if (eventData.valid() && eventData["block"] == true) {
			return;
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*)>(TES3_MobileActor_startCombat)(this, target);

		// Do our follow up started event.
		luaManager.triggerEvent(new mwse::lua::event::CombatStartedEvent(this, target));
	}

	void MobileActor::stopCombat(bool something) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CombatStopEvent(this));
		if (eventData.valid() && eventData["block"] == true) {
			return;
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, bool)>(TES3_MobileActor_stopCombat)(this, something);

		// Do our follow up stopped event.
		luaManager.triggerEvent(new mwse::lua::event::CombatStoppedEvent(this));
	}

	void MobileActor::onDeath() {
		reinterpret_cast<void(__thiscall *)(MobileActor*)>(TES3_MobileActor_onDeath)(this);

		// Trigger death event.
		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::DeathEvent(this));
	}

	bool MobileActor::applyHealthDamage(float damage, bool flipDifficultyScale, bool scaleWithDifficulty, bool takeHealth) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::DamageEvent(this, damage));
		if (eventData.valid()) {
			if (eventData["block"] == true) {
				return false;
			}

			damage = eventData["damage"];
		}

		bool result = reinterpret_cast<signed char(__thiscall *)(MobileActor*, float, bool, bool, bool)>(TES3_MobileActor_applyHealthDamage)(this, damage, flipDifficultyScale, scaleWithDifficulty, takeHealth);

		// Do our follow up event.
		luaManager.triggerEvent(new mwse::lua::event::DamagedEvent(this, damage));

		return result;
	}

	bool MobileActor::hasFreeAction() {
		return reinterpret_cast<bool(__thiscall *)(MobileActor*)>(TES3_MobileActor_hasFreeAction)(this);
	}

	float MobileActor::calculateRunSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateRunSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Run, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	float MobileActor::calculateSwimSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateSwimSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Swim, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	float MobileActor::calculateSwimRunSpeed() {
		// In this case, we don't want to call the original function. We want to redo it so that it calls
		// the calculateSwimSpeed() function.
		TES3::NonDynamicData * nonDynamicData = TES3::DataHandler::get()->nonDynamicData;
		float runMultiplier = nonDynamicData->GMSTs[GMST::fBaseRunMultiplier]->value.asFloat +
			nonDynamicData->GMSTs[GMST::fAthleticsRunBonus]->value.asFloat / 100.0f * getSkillValue(SkillID::Athletics);
		float speed = calculateSwimSpeed() * runMultiplier;

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::SwimRun, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	float MobileActor::calculateFlySpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateFlySpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Fly, this, speed));
		if (eventData.valid()) {
			speed = eventData["speed"];
		}

		return speed;
	}

	void MobileActor::updateDerivedStatistics(Statistic * baseStatistic) {
		TES3_MobileActor_calcDerivedStats(this, baseStatistic);
	}

	int MobileActor::determineModifiedPrice(int basePrice, bool buying) {
		return TES3_MobileActor_determineModifiedPrice(this, basePrice, buying);
	}

	void MobileActor::playVoiceover(int voiceover) {
		TES3_MobileActor_playVoiceover(this, voiceover);
	}

	const auto TES3_MobileActor_isAffectedByAlchemy = reinterpret_cast<bool(__thiscall*)(const MobileActor*, Alchemy*)>(0x52D1A0);
	bool MobileActor::isAffectedByAlchemy(Alchemy * alchemy) {
		return TES3_MobileActor_isAffectedByAlchemy(this, alchemy);
	}

	const auto TES3_MobileActor_isAffectedByEnchantment = reinterpret_cast<bool(__thiscall*)(const MobileActor*, Enchantment*)>(0x52D140);
	bool MobileActor::isAffectedByEnchantment(Enchantment * enchantment) {
		return TES3_MobileActor_isAffectedByEnchantment(this, enchantment);
	}

	const auto TES3_MobileActor_isAffectedBySpell = reinterpret_cast<bool(__thiscall*)(const MobileActor*, Spell*)>(0x52D0E0);
	bool MobileActor::isAffectedBySpell(Spell * spell) {
		return TES3_MobileActor_isAffectedBySpell(this, spell);
	}

	const auto TES3_MobileActor_isActive = reinterpret_cast<bool(__thiscall*)(const MobileActor*)>(0x50F5F0);
	bool MobileActor::isActive() {
		return TES3_MobileActor_isActive(this);
	}

	const auto TES3_MobileActor_setCurrentMagicSourceFiltered = reinterpret_cast<bool(__thiscall*)(const MobileActor*, Object*, int)>(0x52B220);
	void MobileActor::setCurrentMagicSourceFiltered(Object * magic) {
		TES3_MobileActor_setCurrentMagicSourceFiltered(this, magic, 0);
	}

	const auto TES3_MobileActor_setActionTarget = reinterpret_cast<bool(__thiscall*)(const MobileActor*, MobileActor*)>(0x52F790);
	void MobileActor::setActionTarget(MobileActor * target) {
		TES3_MobileActor_setActionTarget(this, target);
	}

	bool MobileActor::getMobileActorFlag(MobileActorFlag::Flag flag) {
		return (actorFlags & flag) != 0;
	}

	void MobileActor::setMobileActorFlag(MobileActorFlag::Flag flag, bool set) {
		if (set) {
			actorFlags |= flag;
		}
		else {
			actorFlags &= ~flag;
		}
	}

	bool MobileActor::getMobileActorMovementFlag(ActorMovement::Flag flag) {
		return (movementFlags & flag) != 0;
	}

	void MobileActor::setMobileActorMovementFlag(ActorMovement::Flag flag, bool set) {
		if (set) {
			movementFlags |= flag;
		}
		else {
			movementFlags &= ~flag;
		}
	}

	bool MobileActor::equipItem(Object* item) {
		Actor* actor = static_cast<Actor*>(reference->baseObject);

		// Equipping weapons while they are in use breaks animations and AI
		if (item->objectType == ObjectType::Weapon && TES3_MobileActor_isInAttackAnim(this)) {
			return false;
		}
		// Check if item exists in the inventory
		ItemStack* s = actor->inventory.findItemStack(item);
		if (!s) {
			return false;
		}
		// Get first available itemdata
		ItemData* data = (s->variables) ? s->variables->storage[0] : nullptr;

		TES3_MobileActor_wearItem(this, item, data, false, false);
		return true;
	}

}
