#include "NIAVObject.h"

#define NI_AVObject_updateNodeEffects 0x6EB380
#define NI_AVObject_updateTextureProperties 0x6EB0E0
#define NI_AVObject_propagatePositionChange 0x6EB000

namespace NI {
	AVObject * AVObject::getObjectByName(const char* name) {
		return vTable.asAVObject->getObjectByName(this, name);
	}

	void AVObject::updateNodeEffects() {
		reinterpret_cast<void(__thiscall *)(AVObject *)>(NI_AVObject_updateNodeEffects)(this);
	}

	void AVObject::updateTextureProperties() {
		reinterpret_cast<void(__thiscall *)(AVObject *)>(NI_AVObject_updateTextureProperties)(this);
	}

	void AVObject::propagatePositionChange(float unk1, int unk2, int unk3) {
		reinterpret_cast<void(__thiscall*)(AVObject*, float, int, int)>(NI_AVObject_propagatePositionChange)(this, unk1, unk2, unk3);
	}

	void AVObject::setLocalRotationMatrix(TES3::Matrix33 * matrix) {
		reinterpret_cast<void(__thiscall *)(AVObject*, TES3::Matrix33*)>(0x50E020)(this, matrix);
	}

	void AVObject::clearTransforms() {
		localScale = 1.0f;
		localTranslate.x = 0.0f;
		localTranslate.y = 0.0f;
		localTranslate.z = 0.0f;
		setLocalRotationMatrix(reinterpret_cast<TES3::Matrix33*>(0x7DE664));
	}
}
