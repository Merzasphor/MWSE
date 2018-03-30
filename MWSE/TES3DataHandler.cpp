#include "TES3DataHandler.h"

#define TES3_DataHandler_getSoundPlaying 0x48BBD0

namespace TES3 {
	bool DataHandler::getSoundPlaying(Sound* sound, Reference* reference) {
		return reinterpret_cast<Sound*(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_getSoundPlaying)(this, sound, reference);
	}
}
