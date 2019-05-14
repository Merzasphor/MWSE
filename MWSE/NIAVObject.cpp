#include "NIAVObject.h"

#include "NIProperty.h"
#include "NIPointer.h"

#define NI_AVObject_updateEffects 0x6EB380
#define NI_AVObject_updateProperties 0x6EB0E0
#define NI_AVObject_update 0x6EB000

namespace NI {
	const auto NI_AVObject_detachPropertyByType = reinterpret_cast<Pointer<Property> *(__thiscall*)(AVObject*, Pointer<Property>*, int)>(0x6EAE20);

	const auto NI_PropertyList_addHead = reinterpret_cast<void(__thiscall*)(PropertyLinkedList*, Pointer<Property>)>(0x405840);

	AVObject * AVObject::getObjectByName(const char* name) {
		return vTable.asAVObject->getObjectByName(this, name);
	}

	bool AVObject::getAppCulled() {
		return vTable.asAVObject->getAppCulled(this);
	}

	void AVObject::setAppCulled(bool culled) {
		vTable.asAVObject->setAppCulled(this, culled);
	}

	void AVObject::update(float fTime, bool bUpdateControllers, bool bUpdateBounds) {
		reinterpret_cast<void(__thiscall*)(AVObject*, float, int, int)>(NI_AVObject_update)(this, fTime, bUpdateControllers, bUpdateBounds);
	}

	void AVObject::updateEffects() {
		reinterpret_cast<void(__thiscall *)(AVObject *)>(NI_AVObject_updateEffects)(this);
	}

	void AVObject::updateProperties() {
		reinterpret_cast<void(__thiscall *)(AVObject *)>(NI_AVObject_updateProperties)(this);
	}

	void AVObject::setLocalRotationMatrix(TES3::Matrix33 * matrix) {
		reinterpret_cast<void(__thiscall *)(AVObject*, TES3::Matrix33*)>(0x50E020)(this, matrix);
	}

	void AVObject::attachProperty(Pointer<Property> property) {
		NI_PropertyList_addHead(&propertyNode, property);
	}

	Pointer<Property> * AVObject::detachProperty(Pointer<Property> * out_detached, PropertyType type) {
		return NI_AVObject_detachPropertyByType(this, out_detached, int(type));
	}

	void AVObject::clearTransforms() {
		localScale = 1.0f;
		localTranslate.x = 0.0f;
		localTranslate.y = 0.0f;
		localTranslate.z = 0.0f;
		setLocalRotationMatrix(reinterpret_cast<TES3::Matrix33*>(0x7DE664));
	}

	Pointer<Property> AVObject::getProperty(PropertyType type) {
		auto propNode = &propertyNode;
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
