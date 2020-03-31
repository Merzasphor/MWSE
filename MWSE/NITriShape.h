#pragma once

#include "NIAVObject.h"
#include "NiTriBasedGeometry.h"
#include "NiTriShapeData.h"

namespace NI {
	struct TriShape_vTable : TriBasedGeometry_vTable {
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

		TriShapeData* getModelData() { return static_cast<TriShapeData*>(modelData.get()); }

	};
	static_assert(sizeof(TriShape) == 0xAC, "NI::TriShape failed size validation");
}
