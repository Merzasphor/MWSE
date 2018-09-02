#include "TES3MobController.h"

#include "LuaManager.h"

#include "LuaMobileActorActivatedEvent.h"
#include "LuaMobileActorDeactivatedEvent.h"

namespace TES3 {
	const auto TES3_MobController_0x24_checkRadius = reinterpret_cast<void(__thiscall*)(MobController_0x24*, MobileActor*, Iterator<void>*)>(0x5704B0);
	const auto TES3_MobController_0x24_detectPresence = reinterpret_cast<bool(__thiscall*)(MobController_0x24*, MobileActor*, bool)>(0x570A60);
	const auto TES3_MobController_0x24_checkPlayerDist = reinterpret_cast<void(__thiscall*)(MobController_0x24*)>(0x56F730);

	const auto TES3_MobController_addMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5636A0);
	const auto TES3_MobController_removeMob = reinterpret_cast<void(__thiscall*)(MobController*, Reference*)>(0x5637F0);

	bool MobController_0x24::detectPresence(MobileActor * actor, bool unknown) {
		return TES3_MobController_0x24_detectPresence(this, actor, unknown);
	}

	void MobController_0x24::checkRadius(MobileActor * actor, Iterator<void> * container) {
		TES3_MobController_0x24_checkRadius(this, actor, container);
	}

	void MobController_0x24::checkPlayerDistance() {
		TES3_MobController_0x24_checkPlayerDist(this);
	}

	void MobController::addMob(Reference * reference) {
		TES3_MobController_addMob(this, reference);

		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileActorActivatedEvent(reference));
	}

	void MobController::removeMob(Reference * reference) {
		TES3_MobController_removeMob(this, reference);

		mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::MobileActorDeactivatedEvent(reference));
	}

	void MobController::checkPlayerDistance() {
		unknown_0x24->checkPlayerDistance();
	}
}
