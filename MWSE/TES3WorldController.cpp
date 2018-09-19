#include "TES3WorldController.h"

#include "TES3GlobalVariable.h"

#define TES3_WorldController_mainLoopBeforeInput 0x40F610
#define TES3_WorldController_getMobilePlayer 0x40FF20
#define TES3_WorldController_playItemUpDownSound 0x411050
#define TES3_WorldController_getSimulationTimestamp 0x411000

#define TES3_Data_cumulativeDaysForMonth 0x775E58

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

	float WorldController::getSimulationTimestamp() {
		return reinterpret_cast<float(__thiscall *)(WorldController*)>(TES3_WorldController_getSimulationTimestamp)(this);
	}

	unsigned short WorldController::getDaysInMonth(int month) {
		return reinterpret_cast<unsigned short*>(TES3_Data_cumulativeDaysForMonth)[month];
	}

	double WorldController::getHighPrecisionSimulationTimestamp() {
		return (gvarYear->value * 365.0 + getDaysInMonth((int)gvarMonth->value) + gvarDay->value) * 24.0 + gvarGameHour->value;
	}
}
