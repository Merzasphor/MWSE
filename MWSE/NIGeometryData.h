#pragma once

#include "NIBound.h"
#include "NIObject.h"

namespace NI {
	struct GeometryData_vTable : Object_vTable {
		void* unknown_0x2C;
		unsigned short(__thiscall* getVertexCount)(GeometryData*); // 0x30
		void* unknown_0x34;
	};
	static_assert(sizeof(GeometryData_vTable) == 0x38, "NI::GeometryData_vTable failed size validation");

	struct GeometryData : Object {
		unsigned short vertexCount; // 0x8
		unsigned short id; // 0xA
		Bound bounds; // 0xC
		TES3::Vector3* vertex; // 0x1C
		TES3::Vector3* normal; // 0x20
		ColorA* color; // 0x24
		TES3::Vector2* texture; // 0x28
		unsigned short dataFlags; // 0x2C
		unsigned short dirtyFlags; // 0x2E
		bool keepFlags; // 0x30
		bool compressFlags; // 0x31
		bool unknown_0x32;

		//
		// vTable wrappers.
		//

		unsigned short getVertexCount();

	};
	static_assert(sizeof(GeometryData) == 0x34, "NI::GeometryData failed size validation");
}
