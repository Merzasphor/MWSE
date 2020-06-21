#include "NIAVObject.h"

#include "NIProperty.h"

#define NI_AVObject_updateEffects 0x6EB380
#define NI_AVObject_updateProperties 0x6EB0E0
#define NI_AVObject_update 0x6EB000

namespace NI {
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

	TES3::Matrix33* AVObject::getLocalRotationMatrix() const {
		return localRotation;
	}

	void AVObject::setLocalRotationMatrix(TES3::Matrix33 * matrix) {
		reinterpret_cast<void(__thiscall *)(AVObject*, TES3::Matrix33*)>(0x50E020)(this, matrix);
	}

	void AVObject::attachProperty(Pointer<Property> property) {
		NI_PropertyList_addHead(&propertyNode, property);
	}

	Pointer<Property> AVObject::detachPropertyByType(PropertyType type) {
		NI::Pointer<NI::Property> prop;
		_detachPropertyByType(this, &prop, type);
		return prop;
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

	void AVObject::update_lua(sol::optional<sol::table> args) {
		if (args) {
			auto values = args.value();
			float time = values.get_or("time", 0.0f);
			bool updateControllers = values.get_or("controllers", false);
			bool updateBounds = values.get_or("bounds", true);

			update(time, updateControllers, updateBounds);
		}
		else {
			update();
		}
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::AVObject)
