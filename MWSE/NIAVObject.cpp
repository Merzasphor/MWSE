#include "NIAVObject.h"

#include "NIProperty.h"
#include "NIPointer.h"

#define NI_AVObject_updateNodeEffects 0x6EB380
#define NI_AVObject_updateTextureProperties 0x6EB0E0
#define NI_AVObject_propagatePositionChange 0x6EB000

namespace NI {
	const auto NI_AVObject_detachPropertyByType = reinterpret_cast<Pointer<Property> *(__thiscall*)(AVObject*, Pointer<Property>*, int)>(0x6EAE20);

	const auto NI_PropertyList_addHead = reinterpret_cast<void(__thiscall*)(AVObject::PropertyListNode*, Pointer<Property>)>(0x405840);

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

	void AVObject::attachProperty(Pointer<Property> property) {
		NI_PropertyList_addHead(&propertyNode, property);
	}

	Pointer<Property> * AVObject::detachProperty(Pointer<Property> * out_detached, int type) {
		return NI_AVObject_detachPropertyByType(this, out_detached, type);
	}

	void AVObject::clearTransforms() {
		localScale = 1.0f;
		localTranslate.x = 0.0f;
		localTranslate.y = 0.0f;
		localTranslate.z = 0.0f;
		setLocalRotationMatrix(reinterpret_cast<TES3::Matrix33*>(0x7DE664));
	}

	Pointer<Property> AVObject::getProperty(int type) {
		PropertyListNode * propNode = &propertyNode;
		if (propNode->data == nullptr) {
			return nullptr;
		}

		while (propNode) {
			if (propNode->data->getType() == type) {
				return propNode->data;
			}
			propNode = propNode->next;
		}

		return nullptr;
	}
}
