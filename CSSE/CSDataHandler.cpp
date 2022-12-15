#include "CSDataHandler.h"

namespace se::cs {
	void DataHandler::maybeUpdateLightForReference(Reference* reference) {
		const auto DataHandler_maybeUpdateLightForReference = reinterpret_cast<void(__thiscall*)(DataHandler*, Reference*)>(0x403A99);
		DataHandler_maybeUpdateLightForReference(this, reference);
	}

	void DataHandler::updateAllLights() {
		const auto DataHandler_updateAllLights = reinterpret_cast<void(__thiscall*)(DataHandler*)>(0x401F5A);
		DataHandler_updateAllLights(this);
	}
}
