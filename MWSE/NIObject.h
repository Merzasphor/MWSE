#pragma once

#include "NIDefines.h"

namespace NI {
	struct Object {
		union {
			AVObject_vTable * asAVObject;
			DynamicEffect_vTable * asDynamicEffect;
			Geometry_vTable * asGeometry;
			GeometryData_vTable * asGeometryData;
			Node_vTable * asNode;
			Object_vTable * asObject;
			Property_vTable * asProperty;
			Renderer_vTable * asRenderer;
			SourceTexture_vTable * asSourceTexture;
			Texture_vTable * asTexture;
			TriBasedGeometryData_vTable* asTriBasedGeometryData;
			TriShape_vTable * asTriShape;
		} vTable; // 0x0
		int refCount; // 0x4

		//
		// Basic operators.
		//

		Object();
		~Object();

		static void *operator new(size_t size);
		static void operator delete(void *block);

		//
		// vTable Wrappers
		//

		RTTI * getRunTimeTypeInformation();

		Object * createClone();

		//
		// Other related this-call functions.
		//

		void release();

		// Slow, but name-based lookup of nodes.
		bool isOfType(const RTTI*);
		bool isOfType(uintptr_t rtti) { return isOfType(reinterpret_cast<RTTI*>(rtti)); }
		bool isInstanceOfType(const RTTI*);
		bool isInstanceOfType(uintptr_t rtti) { return isInstanceOfType(reinterpret_cast<RTTI*>(rtti)); }

		//
		// Custom functions.
		//

		bool saveBinary(const char* filename);

	};
	static_assert(sizeof(Object) == 0x8, "NI::Object failed size validation");

	struct Object_vTable {
		void (__thiscall * destructor)(Object*, int); // 0x0
		RTTI * (__thiscall * getRTTI)(Object*); // 0x4
		Object * (__thiscall * createClone)(Object*); // 0x8
		Object * (__thiscall * loadBinary)(Object*, Stream*); // 0xC
		void * linkObject; // 0x10
		void * registerStreamables; // 0x14
		void (__thiscall* saveBinary)(Object*, Stream*); // 0x18
		bool (__thiscall * isEqual)(Object*, Object*); // 0x1C
		void * getViewerStrings; // 0x20
		void * addViewerStrings; // 0x24
		void * unknown_0x28; // 0x28
	};
	static_assert(sizeof(Object_vTable) == 0x2C, "NI::Object's vtable failed size validation");
}
