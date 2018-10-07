#pragma once

#include "NIObjectNET.h"
#include "NIProperty.h"
#include "NITransform.h"

#include "TES3Collections.h"

namespace NI {
	struct AVObject : ObjectNET {
		struct PropertyListNode {
			Property * data;
			PropertyListNode * next;
		};
		unsigned short flags; // 0x14
		short unknown_0x16;
		Node * parentNode; // 0x18
		TES3::Vector3 worldBoundOrigin; // 0x1C
		float worldBoundRadius; // 0x28
		TES3::Matrix33 * localRotation; // 0x2C
		TES3::Vector3 localTranslate; // 0x30
		float localScale; // 0x3C
		TES3::Transform worldTransform; // 0x40
		void * localBound; // 0x74
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		PropertyListNode propertyNode; // 0x88

		//
		// vTable wrappers.
		//

		__declspec(dllexport) AVObject * getObjectByName(const char*);

		template <typename T>
		__declspec(dllexport) T * getObjectByNameAndType(const char* name) {
			return reinterpret_cast<T*>(vTable.asAVObject->getObjectByName(this, name));
		}
		
		//
		// Other related this-call functions.
		//

		__declspec(dllexport) void updateNodeEffects();
		__declspec(dllexport) void updateTextureProperties();
		__declspec(dllexport) void propagatePositionChange(float unk1 = 0.0f, int unk2 = 0, int unk3 = 1);
		__declspec(dllexport) void setLocalRotationMatrix(TES3::Matrix33* matrix);

		__declspec(dllexport) void attachProperty(Pointer<Property> property);
		__declspec(dllexport) Pointer<Property> * detachProperty(Pointer<Property> * out_detached, int type);

		//
		// Custom functions.
		//

		__declspec(dllexport) void clearTransforms();
		Pointer<Property> getProperty(int type);

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
		void * setAppCulled; // 0x50
		void * getAppCulled; // 0x54
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
