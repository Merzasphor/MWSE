#include "TES3WorldController.h"

#define TES3_WorldController_mainLoopBeforeInput 0x40F610
#define TES3_WorldController_getMobilePlayer 0x40FF20
#define TES3_WorldController_playItemUpDownSound 0x411050

namespace TES3 {
	void WorldController::mainLoopBeforeInput() {
		reinterpret_cast<void(__thiscall *)(WorldController*)>(TES3_WorldController_mainLoopBeforeInput)(this);
	}

	MobilePlayer* WorldController::getMobilePlayer() {
		return reinterpret_cast<MobilePlayer*(__thiscall *)(WorldController*)>(TES3_WorldController_getMobilePlayer)(this);
	}

	void WorldController::playItemUpDownSound(BaseObject* item, bool pickup, Reference* reference) {
		reinterpret_cast<void(__thiscall *)(WorldController*, BaseObject*, int, Reference*)>(TES3_WorldController_playItemUpDownSound)(this, item, pickup, reference);
	}
}
