#include "CSLight.h"

namespace se::cs {
	void Light::updateLightingData(NI::Light* light, void* lightingController, bool flag) {
		const auto Light_updateLightingData = reinterpret_cast<void(__thiscall*)(Light*, NI::Light*, void*, bool)>(0x403567);
		Light_updateLightingData(this, light, lightingController, flag);
	}
}
