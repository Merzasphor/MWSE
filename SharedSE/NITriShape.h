#pragma once

#include "NIAVObject.h"
#include "NITriBasedGeometry.h"

namespace NI {
	struct TriShape_vTable : Geometry_vTable {
		void* unknown_0x9C;
		void* unknown_0xA0;
		void* unknown_0xA4;
		void* unknown_0xA8;
	};
	static_assert(sizeof(TriShape_vTable) == 0xAC, "NI::TriShape's vtable failed size validation");

	struct TriShape : TriBasedGeometry {

		//
		// vTable type overwriting.
		//

		TriShapeData* getModelData() const;

		// Convenient access to model data.
		nonstd::span<Vector3> getVertices() const;
		nonstd::span<Vector3> getNormals() const;

	};
	static_assert(sizeof(TriShape) == 0xAC, "NI::TriShape failed size validation");
}
