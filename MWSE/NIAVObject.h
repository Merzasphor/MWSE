#pragma once

#include "NIObjectNET.h"
#include "NILinkedList.h"
#include "NIProperty.h"
#include "NITransform.h"

#include "TES3Collections.h"

#include "Bitset.h"

namespace NI {
	struct AVObject : ObjectNET {
		mwse::bitset16 flags; // 0x14
		short pad_16;
		Node * parentNode; // 0x18
		TES3::Vector3 worldBoundOrigin; // 0x1C
		float worldBoundRadius; // 0x28
		TES3::Matrix33 * localRotation; // 0x2C
		TES3::Vector3 localTranslate; // 0x30
		float localScale; // 0x3C
		TES3::Transform worldTransform; // 0x40
		TES3::Vector3 * velocities; // 0x74
		void * modelABV; // 0x78
		void * worldABV; // 0x7C
		int (__cdecl * collideCallback)(void*); // 0x80
		void * collideCallbackUserData; // 0x84
		PropertyLinkedList propertyNode; // 0x88

		//
		// vTable wrappers.
		//

		__declspec(dllexport) AVObject * getObjectByName(const char*);

		template <typename T>
		__declspec(dllexport) T * getObjectByNameAndType(const char* name) {
			return static_cast<T*>(vTable.asAVObject->getObjectByName(this, name));
		}

		__declspec(dllexport) bool getAppCulled();
		__declspec(dllexport) void setAppCulled(bool culled);
		
		//
		// Other related this-call functions.
		//

		__declspec(dllexport) void update(float fTime = 0.0f, bool bUpdateControllers = false, bool bUpdateBounds = true);
		__declspec(dllexport) void updateEffects();
		__declspec(dllexport) void updateProperties();
		__declspec(dllexport) void setLocalRotationMatrix(TES3::Matrix33* matrix);

		__declspec(dllexport) void attachProperty(Pointer<Property> property);
		__declspec(dllexport) Pointer<Property> * detachProperty(Pointer<Property> * out_detached, PropertyType type);

		//
		// Custom functions.
		//

		__declspec(dllexport) void clearTransforms();
		__declspec(dllexport) Pointer<Property> getProperty(PropertyType type);

	};
	static_assert(sizeof(AVObject) == 0x90, "NI::AVObject failed size validation");

	struct AVObject_vTable : Object_vTable {
		void * unknown_0x2C;
		void * unknown_0x30;
		void * getWorldBound; // 0x34
		void * unknown_0x38;
		void * unknown_0x3C;
		void * unknown_0x40;
		void * unknown_0x44;
		void * unknown_0x48;
		void * unknown_0x4C;
		void (__thiscall * setAppCulled)(AVObject*, bool); // 0x50
		bool (__thiscall * getAppCulled)(AVObject*); // 0x54
		void * unknown_0x58;
		AVObject * (__thiscall * getObjectByName)(AVObject*, const char*); // 0x5C
		void * unknown_0x60;
		void * unknown_0x64;
		void * unknown_0x68;
		void * unknown_0x6C;
		void * unknown_0x70;
		void * unknown_0x74;
		void * unknown_0x78;
		void * unknown_0x7C;
		void * unknown_0x80;
		void * unknown_0x84;
		void * findIntersections; // 0x88
		void * updateWorldData; // 0x8C
		void * updateWorldBound; // 0x90
	};
	static_assert(sizeof(AVObject_vTable) == 0x94, "NI::AVObject's vtable failed size validation");
}
