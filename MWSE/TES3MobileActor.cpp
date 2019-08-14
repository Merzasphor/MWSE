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
#include "TES3AudioController.h"
#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3ItemData.h"
#include "TES3Reference.h"
#include "TES3WorldController.h"

#include "TES3Util.h"

#define TES3_MobileActor_getCell 0x521630
#define TES3_MobileActor_startCombat 0x530470
#define TES3_MobileActor_stopCombat 0x558720
#define TES3_MobileActor_onDeath 0x523AA0
#define TES3_MobileActor_hasFreeAction 0x527580
#define TES3_MobileActor_calculateRunSpeed 0x527050
#define TES3_MobileActor_calculateSwimSpeed 0x5270B0
#define TES3_MobileActor_calculateSwimRunSpeed 0x527130
#define TES3_MobileActor_calculateFlySpeed 0x5271F0

namespace TES3 {
	const auto TES3_MobileActor_onActorCollision = reinterpret_cast<bool(__thiscall *)(MobileActor*, int)>(0x5234A0);
	const auto TES3_MobileActor_onObjectCollision = reinterpret_cast<bool(__thiscall *)(MobileActor*, int, bool)>(0x5233B0);
	const auto TES3_MobileActor_onTerrainCollision = reinterpret_cast<bool(__thiscall *)(MobileActor*, int)>(0x523310);
	const auto TES3_MobileActor_onActivatorCollision = reinterpret_cast<bool(__thiscall *)(MobileActor*, int)>(0x523590);
	const auto TES3_MobileActor_isInAttackAnim = reinterpret_cast<bool (__thiscall*)(const MobileActor*)>(0x5567D0);
	const auto TES3_MobileActor_wearItem = reinterpret_cast<void (__thiscall*)(MobileActor*, Object*, ItemData*, bool, bool)>(0x52C770);
	const auto TES3_MobileActor_calcDerivedStats = reinterpret_cast<void(__thiscall*)(const MobileActor*, Statistic*)>(0x527BC0);
	const auto TES3_MobileActor_determineModifiedPrice = reinterpret_cast<int(__thiscall*)(const MobileActor*, int, int)>(0x52AA50);
	const auto TES3_MobileActor_playVoiceover = reinterpret_cast<void(__thiscall*)(const MobileActor*, int)>(0x528F80);

	bool MobileActor::onActorCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileActor_onActorCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileActor::onObjectCollision(int collisionIndex, bool flag) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileActor_onObjectCollision(this, collisionIndex, flag);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileActor::onTerrainCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileActor_onTerrainCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	bool MobileActor::onActivatorCollision(int collisionIndex) {
		// Grab the hit reference now, it won't be available after calling the main function.
		TES3::Reference* hitReference = this->arrayCollisionResults[collisionIndex].colliderRef;

		// Call the original function. We can't invoke the vtable here because we overwrite it.
		bool result = TES3_MobileActor_onActivatorCollision(this, collisionIndex);

		// Fire off our hit event.
		if (mwse::lua::event::MobileObjectCollisionEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileObjectCollisionEvent(this, hitReference));
		}

		return result;
	}

	SkillStatistic * MobileActor::getSkillStatistic(int skillId) {
		return vTable.mobileActor->getSkillStatistic(this, skillId);
	}

	float MobileActor::getSkillValue(int skillId) {
		return vTable.mobileActor->getSkillValue(this, skillId);
	}

	float MobileActor::applyArmorRating(float damage, float swing, bool damageEquipment) {
		return vTable.mobileActor->applyArmorRating(this, damage, swing, damageEquipment);
	}

	float MobileActor::calculateArmorRating(int * armorItemCount) {
		return vTable.mobileActor->calculateArmorRating(this, armorItemCount);
	}

	const auto TES3_MobileActor_applyHitModifiers = reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*, MobileActor*, float, float, MobileProjectile*, bool)>(0x5568F0);
	void MobileActor::applyHitModifiers(MobileActor * attacker, MobileActor * defender, float unknown, float swing, MobileProjectile * projectile, bool unknown2) {
		// Clean up damage event data.
		mwse::lua::event::DamageEvent::m_Attacker = attacker;
		mwse::lua::event::DamageEvent::m_Projectile = projectile;

		// Call original function.
		TES3_MobileActor_applyHitModifiers(this, attacker, defender, unknown, swing, projectile, unknown2);

		// Setup damage event data.
		mwse::lua::event::DamageEvent::m_Attacker = nullptr;
		mwse::lua::event::DamageEvent::m_Projectile = nullptr;
	}

	Cell* MobileActor::getCell() {
		return reinterpret_cast<Cell*(__thiscall *)(MobileActor*)>(TES3_MobileActor_getCell)(this);
	}

	const auto TES3_MobileActor_getFatigueTerm = reinterpret_cast<float(__thiscall *)(MobileActor*)>(0x527610);
	float MobileActor::getFatigueTerm() {
		return TES3_MobileActor_getFatigueTerm(this);
	}

	void MobileActor::startCombat(MobileActor* target) {
		// Invoke our first event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		if (mwse::lua::event::CombatStartEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CombatStartEvent(this, target));
			if (eventData.valid() && eventData["block"] == true) {
				return;
			}
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*)>(TES3_MobileActor_startCombat)(this, target);

		// Do our follow up started event.
		if (mwse::lua::event::CombatStartedEvent::getEventEnabled()) {
			luaManager.getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::CombatStartedEvent(this, target));
		}
	}

	void MobileActor::stopCombat(bool something) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		if (mwse::lua::event::CombatStopEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CombatStopEvent(this));
			if (eventData.valid() && eventData["block"] == true) {
				return;
			}
		}

		// Call original function.
		reinterpret_cast<void(__thiscall *)(MobileActor*, bool)>(TES3_MobileActor_stopCombat)(this, something);

		// Do our follow up stopped event.
		if (mwse::lua::event::CombatStoppedEvent::getEventEnabled()) {
			luaManager.getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::CombatStoppedEvent(this));
		}
	}

	void MobileActor::onDeath() {
		reinterpret_cast<void(__thiscall *)(MobileActor*)>(TES3_MobileActor_onDeath)(this);

		// Trigger death event.
		if (mwse::lua::event::DeathEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::DeathEvent(this));
		}
	}

	const auto TES3_MobileActor_applyHealthDamage = reinterpret_cast<void(__thiscall *)(MobileActor*, MobileActor*, MobileActor*, float, float, MobileProjectile*, bool)>(0x5568F0);
	bool MobileActor::applyHealthDamage(float damage, bool flipDifficultyScale, bool scaleWithDifficulty, bool takeHealth) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		if (mwse::lua::event::DamageEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::DamageEvent(this, damage));
			if (eventData.valid()) {
				if (eventData["block"] == true) {
					return false;
				}

				damage = eventData["damage"];
			}
		}

		bool checkForKnockdown = reinterpret_cast<bool (__thiscall *)(MobileActor*, float, bool, bool, bool)>(0x557CF0)(this, damage, flipDifficultyScale, scaleWithDifficulty, takeHealth);

		// Do our follow up event.
		if (mwse::lua::event::DamagedEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::DamagedEvent(this, damage, checkForKnockdown));
			if (eventData.valid()) {
				checkForKnockdown = eventData["checkForKnockdown"];
			}
		}

		return checkForKnockdown;
	}

	bool MobileActor::hasFreeAction() {
		return reinterpret_cast<bool(__thiscall *)(MobileActor*)>(TES3_MobileActor_hasFreeAction)(this);
	}

	float MobileActor::calculateRunSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateRunSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		if (mwse::lua::event::CalculateMovementSpeed::getEventEnabled()) {
			mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Run, this, speed));
			if (eventData.valid()) {
				speed = eventData["speed"];
			}
		}

		return speed;
	}

	float MobileActor::calculateSwimSpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateSwimSpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		if (mwse::lua::event::CalculateMovementSpeed::getEventEnabled()) {
			mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Swim, this, speed));
			if (eventData.valid()) {
				speed = eventData["speed"];
			}
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
		if (mwse::lua::event::CalculateMovementSpeed::getEventEnabled()) {
			mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::SwimRun, this, speed));
			if (eventData.valid()) {
				speed = eventData["speed"];
			}
		}

		return speed;
	}

	float MobileActor::calculateFlySpeed() {
		// Call the original function to get the default movement speed value.
		float speed = reinterpret_cast<float(__thiscall *)(MobileActor*)>(TES3_MobileActor_calculateFlySpeed)(this);

		// Launch our event, and overwrite the speed with what was given back to us.
		if (mwse::lua::event::CalculateMovementSpeed::getEventEnabled()) {
			mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::CalculateMovementSpeed(mwse::lua::event::CalculateMovementSpeed::Fly, this, speed));
			if (eventData.valid()) {
				speed = eventData["speed"];
			}
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

	const auto TES3_MobileActor_startDialogue = reinterpret_cast<void(__thiscall*)(const MobileActor*)>(0x529260);
	void MobileActor::startDialogue() {
		TES3_MobileActor_startDialogue(this);
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

	const auto TES3_MobileActor_getCombatSpellList = reinterpret_cast<Iterator<Spell> *(__thiscall*)(const MobileActor*)>(0x52B3C0);
	Iterator<Spell> * MobileActor::getCombatSpellList() {
		return TES3_MobileActor_getCombatSpellList(this);
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

	const auto TES3_MobileActor_dropItem = reinterpret_cast<void (__thiscall*)(MobileActor*, Object*, ItemData*, int, bool)>(0x52C460);
	void MobileActor::dropItem(Object * item, ItemData * itemData, int count, bool exact) {
		return TES3_MobileActor_dropItem(this, item, itemData, count, exact);
	}

	const auto TES3_MobileActor_persuade = reinterpret_cast<bool(__thiscall*)(MobileActor*, int, int)>(0x529D10);
	bool MobileActor::persuade(int random, int persuasionIndex) {
		return TES3_MobileActor_persuade(this, random, persuasionIndex);
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

	bool MobileActor::equipItem(Object* item, ItemData* itemData, bool addItem, bool selectBestCondition, bool selectWorstCondition) {
		Actor* actor = static_cast<Actor*>(reference->baseObject);

		// Equipping weapons while they are in use breaks animations and AI.
		if (item->objectType == ObjectType::Weapon && TES3_MobileActor_isInAttackAnim(this)) {
			return false;
		}

		// Check if item exists in the inventory.
		ItemStack* s = actor->inventory.findItemStack(item);
		if (!s) {
			if (addItem) {
				TES3_MobileActor_wearItem(this, item, itemData, addItem, false);
				return true;
			}
			return false;
		}
		else if (itemData && !s->variables->contains(itemData)) {
			return false;
		}

		// Prefer an already equipped item when selecting an item data match.
		EquipmentStack* equipped = actor->getEquippedItem(item);

		// Select item based on best/worst condition.
		if (selectBestCondition) {
			// Use already equipped item if it has full condition.
			if (equipped && ItemData::isFullyRepaired(equipped->variables, static_cast<TES3::Item*>(equipped->object))) {
				return true;
			}

			// Scan for best item condition.
			itemData = nullptr;

			// Only scan if necessary; fully repaired items exist if stack count is greater than variables count.
			if (s->variables && s->count == s->variables->filledCount) {
				int bestCondition = -1;
				float bestCharge = -1.0f;

				for (ItemData **it = &s->variables->storage[0]; it < &s->variables->storage[s->variables->endIndex]; ++it) {
					// Select best condition, secondarily select best charge.
					ItemData *i = *it;
					if (i && i->condition > bestCondition || (i->condition == bestCondition && i->charge > bestCharge)) {
						itemData = i;
						bestCondition = i->condition;
						bestCharge = i->charge;
					}
				}
			}
		}
		else if (selectWorstCondition) {
			// Scan for worst item condition.
			itemData = nullptr;

			if (s->variables) {
				int worstCondition = s->variables->storage[0]->condition;
				float worstCharge = s->variables->storage[0]->charge;
				itemData = s->variables->storage[0];

				for (ItemData **it = &s->variables->storage[0]; it < &s->variables->storage[s->variables->endIndex]; ++it) {
					// Select worst condition, secondarily select worst charge.
					ItemData *i = *it;
					if (i && i->condition < worstCondition || (i->condition == worstCondition && i->charge < worstCharge)) {
						itemData = i;
						worstCondition = i->condition;
						worstCharge = i->charge;
					}
				}
			}
		}
		// Get any matching item if no itemdata and no flags are set.
		else if (itemData == nullptr) {
			// Prefer to match an already equipped item.
			if (equipped) {
				return true;
			}
			// Get first available itemdata if one isn't provided.
			else if (s->variables != nullptr) {
				itemData = s->variables->storage[0];
			}
		}

		// Check if selected item is already equipped, to avoid a Morrowind crash.
		// wearItem unequips the slot first, and unequipping a fully repaired item may deallocate the existing itemData.
		if (actor->getEquippedItemExact(item, itemData)) {
			return true;
		}

		TES3_MobileActor_wearItem(this, item, itemData, false, false);
		return true;
	}

}
