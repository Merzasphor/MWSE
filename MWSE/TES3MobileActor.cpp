#include "TES3MobileActor.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#define TES3_MobileActor_onActorCollision 0x5234A0
#define TES3_MobileActor_onObjectCollision 0x5233B0
#define TES3_MobileActor_onTerrainCollision 0x523310
#define TES3_MobileActor_onActivatorCollision 0x523590
#define TES3_MobileActor_getCell 0x521630
#define TES3_MobileActor_startCombat 0x530470
#define TES3_MobileActor_stopCombat 0x558720
#define TES3_MobileActor_onDeath 0x523AA0
#define TES3_MobileActor_applyHealthDamage 0x557CF0

namespace TES3 {
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

	bool MobileActor::applyHealthDamage(float damage, bool flag1, bool flag2, bool flag3) {
		// Invoke our combat stop event and check if it is blocked.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::DamageEvent(this, damage));
		if (eventData.valid()) {
			if (eventData["block"] == true) {
				return false;
			}

			damage = eventData["damage"];
		}

		bool result = reinterpret_cast<signed char(__thiscall *)(MobileActor*, float, signed char, signed char, signed char)>(TES3_MobileActor_applyHealthDamage)(this, damage, flag1, flag2, flag3);

		// Do our follow up event.
		luaManager.triggerEvent(new mwse::lua::event::DamagedEvent(this, damage));

		return true;
	}

	bool MobileActor::getMobileActorFlag(unsigned int flag) {
		return (actorFlags & flag) != 0;
	}

	void MobileActor::setMobileActorFlag(unsigned int flag, bool set) {
		if (set) {
			actorFlags |= flag;
		}
		else {
			actorFlags &= ~flag;
		}
	}
}
