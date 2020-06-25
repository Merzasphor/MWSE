#include "TES3MobController.h"

#include "LuaManager.h"

#include "LuaMobileActorActivatedEvent.h"
#include "LuaMobileActorDeactivatedEvent.h"
#include "LuaDetectSneakEvent.h"

namespace TES3 {
	const auto TES3_MobController_0x24_checkRadius = reinterpret_cast<void(__thiscall*)(MobController_0x24*, MobileActor*, IteratedList<AIPlanner*>*)>(0x5704B0);
	const auto TES3_MobController_0x24_detectPresence = reinterpret_cast<bool(__thiscall*)(MobController_0x24*, MobileActor*, bool)>(0x570A60);
	const auto TES3_MobController_0x24_detectSneak = reinterpret_cast<bool(__thiscall*)(MobController_0x24*, MobileActor*, MobileActor*, bool)>(0x570600);
	const auto TES3_MobController_0x24_checkPlayerDist = reinterpret_cast<void(__thiscall*)(MobController_0x24*)>(0x56F730);

	const auto TES3_MobController_addMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5636A0);
	const auto TES3_MobController_removeMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5637F0);

	bool MobController_0x24::detectPresence(MobileActor * actor, bool unknown) {
		return TES3_MobController_0x24_detectPresence(this, actor, unknown);
	}

	bool MobController_0x24::detectSneak(MobileActor* detector, MobileActor* target, bool unknown)
	{
		// Call the original function to get the default sneak detection.
		bool isDetected = TES3_MobController_0x24_detectSneak(this, detector, target, unknown);

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

	void MobController_0x24::checkRadius(MobileActor * actor, IteratedList<AIPlanner*> * container) {
		TES3_MobController_0x24_checkRadius(this, actor, container);
	}

	void MobController_0x24::checkPlayerDistance() {
		TES3_MobController_0x24_checkPlayerDist(this);
	}

	void MobController::addMob(Reference * reference) {
		TES3_MobController_addMob(this, reference);

		if (mwse::lua::event::MobileActorActivatedEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileActorActivatedEvent(reference));
		}
	}

	void MobController::removeMob(Reference * reference) {
		TES3_MobController_removeMob(this, reference);

		if (mwse::lua::event::MobileActorDeactivatedEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MobileActorDeactivatedEvent(reference));
		}
	}

	void MobController::checkPlayerDistance() {
		mobController_0x24->checkPlayerDistance();
	}
}
