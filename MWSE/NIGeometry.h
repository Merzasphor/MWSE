#pragma once

#include "NIAVObject.h"
#include "NIGeometryData.h"

namespace NI {
	struct Geometry_vTable : AVObject_vTable {
		void* (__thiscall* setModelData)(Geometry*, GeometryData*); // 0x94
		void* unknown_0x98;
	};
	static_assert(sizeof(Geometry_vTable) == 0x9C, "NI::Geometry_vTable failed size validation");

	struct Geometry : AVObject {
		void* propertyState; // 0x90
		void* effectState; // 0x94
		Pointer<GeometryData> modelData; // 0x98
		void* skinInstance; // 0x9C
		int unknown_0xA0;
		int unknown_0xA4;
		char unknown_0xA8;
		char unknown_0xA9;

		//
		// vTable wrappers.
		//

		GeometryData* getModelData();
		void setModelData(GeometryData* data);

	};
	static_assert(sizeof(Geometry) == 0xAC, "NI::Geometry failed size validation");
}
