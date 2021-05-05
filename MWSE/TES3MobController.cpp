#include "TES3MobController.h"
#include "TES3MobileActor.h"

#include "LuaManager.h"

#include "LuaMobileActorActivatedEvent.h"
#include "LuaMobileActorDeactivatedEvent.h"
#include "LuaDetectSneakEvent.h"

#include "TES3Reference.h"

namespace TES3 {
	const auto TES3_ProcessManager_detectPresence = reinterpret_cast<bool(__thiscall*)(ProcessManager*, MobileActor*, bool)>(0x570A60);
	bool ProcessManager::detectPresence(MobileActor * actor, bool unknown) {
		return TES3_ProcessManager_detectPresence(this, actor, unknown);
	}

	const auto TES3_ProcessManager_detectSneak = reinterpret_cast<bool(__thiscall*)(ProcessManager*, MobileActor*, MobileActor*, bool)>(0x570600);
	bool ProcessManager::detectSneak(MobileActor* detector, MobileActor* target, bool unknown) {
		// Call the original function to get the default sneak detection.
		bool isDetected = TES3_ProcessManager_detectSneak(this, detector, target, unknown);

		// Launch our event, and overwrite the speed with what was given back to us.
		if (mwse::lua::event::DetectSneakEvent::getEventEnabled()) {
			mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::DetectSneakEvent(detector, target, isDetected));
			if (eventData.valid()) {
				isDetected = eventData["isDetected"];
			}
		}

		return isDetected;
	}

	const auto TES3_ProcessManager_checkRadius = reinterpret_cast<void(__thiscall*)(ProcessManager*, MobileActor*, IteratedList<AIPlanner*>*)>(0x5704B0);
	void ProcessManager::checkRadius(MobileActor * actor, IteratedList<AIPlanner*> * container) {
		TES3_ProcessManager_checkRadius(this, actor, container);
	}

	const auto TES3_ProcessManager_checkPlayerDist = reinterpret_cast<void(__thiscall*)(ProcessManager*)>(0x56F730);
	void ProcessManager::checkPlayerDistance() {
		TES3_ProcessManager_checkPlayerDist(this);
	}

	const auto TES3_ProcessManager_canRest = reinterpret_cast<bool(__thiscall*)(ProcessManager*)>(0x56F810);
	bool ProcessManager::canRest() {
		return TES3_ProcessManager_canRest(this);
	}

	float ProcessManager::getAIDistanceScale() const {
		return (aiDistance - 1000.0f) / 6000.0f;
	}

	void ProcessManager::setAIDistanceScale(float scalar) {
		aiDistance = 1000.0f + 6000.0f * scalar;
	}

	const auto TES3_MobController_addMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5636A0);
	void MobController::addMob(Reference * reference) {
		TES3_MobController_addMob(this, reference);

		auto mobile = reference->getAttachedMobileObject();
		if (mwse::lua::event::MobileActorActivatedEvent::getEventEnabled() && mobile) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileActorActivatedEvent(mobile));
		}
	}

	const auto TES3_MobController_removeMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5637F0);
	void MobController::removeMob(Reference * reference) {
		TES3_MobController_removeMob(this, reference);

		if (mwse::lua::event::MobileActorDeactivatedEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileActorDeactivatedEvent(reference));
		}
	}

	void MobController::checkPlayerDistance() {
		processManager->checkPlayerDistance();
	}

	const auto TES3_MobController_addPlayerAsCollider = reinterpret_cast<void(__thiscall*)(MobController*)>(0x563640);
	void MobController::addPlayerAsCollider() {
		TES3_MobController_addPlayerAsCollider(this);
	}

	bool MobController::hasMobileCollision(const MobileActor* mobile) {
		bool result = false;
		if (mobile && (mobile->actorFlags & TES3::MobileActorFlag::ActiveAI)) {
			auto node = mobile->reference->sceneNode;
			criticalSection_Mobs.enter();
			result = mobCollisionGroup->containsCollider(node);
			criticalSection_Mobs.leave();
		}
		return result;
	}

	void MobController::enableMobileCollision(MobileActor* mobile) {
		if (mobile && (mobile->actorFlags & TES3::MobileActorFlag::ActiveAI)) {
			auto node = mobile->reference->sceneNode;
			criticalSection_Mobs.enter();
			if (!mobCollisionGroup->containsCollider(node)) {
				mobCollisionGroup->addCollider(node);
			}
			criticalSection_Mobs.leave();
		}
	}

	void MobController::disableMobileCollision(MobileActor* mobile) {
		if (mobile && (mobile->actorFlags & TES3::MobileActorFlag::ActiveAI)) {
			auto node = mobile->reference->sceneNode;
			criticalSection_Mobs.enter();
			mobCollisionGroup->removeCollider(node);
			criticalSection_Mobs.leave();
		}
	}
}
