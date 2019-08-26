#pragma once

#include "NIAVObject.h"
#include "NIPointer.h"

namespace NI {
	struct TriShapeData : Object {
		unsigned short vertices; // 0x8
		unsigned short id; // 0xA
		TES3::Vector3 origin; // 0xC
		float radius; // 0x18
		void * vertex; // 0x1C
		void * normal; // 0x20
		void * color; // 0x24
		void * texture; // 0x28
		mwse::bitset16 dataFlags; // 0x2C
		mwse::bitset16 dirtyFlags; // 0x2E
		bool keepFlags; // 0x30
		bool compressFlags; // 0x31
		bool unknown_0x32;
		unsigned short triangles; // 0x34
		unsigned int triangleListLength; // 0x38
		unsigned short * triangleList; // 0x3C
		void * sharedNormals; // 0x40
		unsigned short sharedNormalsArraySize; // 0x44
	};
	static_assert(sizeof(TriShapeData) == 0x48, "NI::TriShapeData failed size validation");

	struct TriShape : AVObject {
		void * propertyState; // 0x90
		void * effectState; // 0x94
		Pointer<TriShapeData> modelData; // 0x98
		void * skinInstance; // 0x9C
		int unknown_0xA0;
		int unknown_0xA4;
		char unknown_0xA8;
		char unknown_0xA9;

		//
		// vTable wrappers.
		//

		TriShapeData* getModelData();
		void setModelData(TriShapeData* data);

	};
	static_assert(sizeof(TriShape) == 0xAC, "NI::TriShape failed size validation");

	struct TriShape_vTable : AVObject_vTable {
		void * (__thiscall * setModelData)(TriShape*, TriShapeData*); // 0x94
		void * unknown_0x98;
		void * unknown_0x9C;
		void * unknown_0xA0;
		void * unknown_0xA4;
		void * unknown_0xA8;
	};
	static_assert(sizeof(TriShape_vTable) == 0xAC, "NI::TriShape's vtable failed size validation");
}
