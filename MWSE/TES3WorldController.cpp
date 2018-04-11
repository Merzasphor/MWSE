#include "TES3WorldController.h"

#define TES3_WorldController_getMobilePlayer 0x40FF20

namespace TES3 {
	MobilePlayer* WorldController::getMobilePlayer() {
		return reinterpret_cast<MobilePlayer*(__thiscall *)(WorldController*)>(TES3_WorldController_getMobilePlayer)(this);
	}
}
