#include "TES3MobController.h"

namespace TES3 {
	const auto TES3_MobController_0x24_checkRadius = reinterpret_cast<void(__thiscall*)(MobController_0x24*, MobileActor*, Iterator<void>*)>(0x5704B0);
	const auto TES3_MobController_0x24_detectPresence = reinterpret_cast<bool(__thiscall*)(MobController_0x24*, MobileActor*, bool)>(0x570A60);

	bool MobController_0x24::detectPresence(MobileActor * actor, bool unknown) {
		return TES3_MobController_0x24_detectPresence(this, actor, unknown);
	}

	void MobController_0x24::checkRadius(MobileActor * actor, Iterator<void> * container) {
		TES3_MobController_0x24_checkRadius(this, actor, container);
	}
}
