#pragma once

#include "NIGeometry.h"
#include "NiTriBasedGeometryData.h"

namespace NI {
	struct TriBasedGeometry : Geometry {

		//
		// vTable type overwriting.
		//

		TriBasedGeometryData* getModelData() { return static_cast<TriBasedGeometryData*>(modelData.get()); }

	};
	static_assert(sizeof(TriBasedGeometry) == 0xAC, "NI::TriBasedGeometry failed size validation");
}
