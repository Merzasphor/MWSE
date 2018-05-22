#include "NIAVObject.h"

#define NI_AVObject_propagatePositionChange 0x6EB000

namespace NI {
	AVObject * AVObject::getObjectByName(const char* name) {
		return vTable.asAVObject->getObjectByName(this, name);
	}

	void AVObject::propagatePositionChange(float unk1, int unk2, int unk3) {
		reinterpret_cast<void(__thiscall*)(AVObject*, float, int, int)>(NI_AVObject_propagatePositionChange)(this, unk1, unk2, unk3);
	}
}
