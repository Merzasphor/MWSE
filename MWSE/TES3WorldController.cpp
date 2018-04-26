#include "TES3WorldController.h"

#define TES3_WorldController_mainLoopBeforeInput 0x40F610
#define TES3_WorldController_getMobilePlayer 0x40FF20

namespace TES3 {
	void WorldController::mainLoopBeforeInput() {
		reinterpret_cast<void(__thiscall *)(WorldController*)>(TES3_WorldController_mainLoopBeforeInput)(this);
	}

	MobilePlayer* WorldController::getMobilePlayer() {
		return reinterpret_cast<MobilePlayer*(__thiscall *)(WorldController*)>(TES3_WorldController_getMobilePlayer)(this);
	}
}
