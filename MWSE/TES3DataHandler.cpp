#include "TES3DataHandler.h"

#define TES3_NonDynamicData_findScriptByName 0x4BA700
#define TES3_DataHandler_getSoundPlaying 0x48BBD0

namespace TES3 {
	Script* NonDynamicData::findScriptByName(const char* name) {
		return reinterpret_cast<Script*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findScriptByName)(this, name);
	}

	bool DataHandler::getSoundPlaying(Sound* sound, Reference* reference) {
		return reinterpret_cast<Sound*(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_getSoundPlaying)(this, sound, reference);
	}
}
