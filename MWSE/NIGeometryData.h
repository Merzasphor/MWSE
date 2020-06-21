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
		enum Consistency : unsigned short {
			Mutable = 0x0000,
			Static = 0x4000,
			Volatile = 0x8000,
			Mask = 0xF000,
		};
		enum Mask : unsigned short {
			Vertex = 0x0001,
			Normal = 0x0002,
			Color = 0x0004,
			Texture = 0x0008,
			Dirty = 0x0FFF,
		};

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

		//
		// Custom functions.
		//

		Consistency getConsistency();

		void markAsChanged(unsigned short flags);

		nonstd::span<ColorA> getColors();
		nonstd::span<TES3::Vector3> getVertices();
		nonstd::span<TES3::Vector3> getNormals();
		nonstd::span<TES3::Vector2> getTextureCoordinates();

	};
	static_assert(sizeof(GeometryData) == 0x34, "NI::GeometryData failed size validation");
}
