#include "NIGeometryData.h"

namespace NI {
	nonstd::span<Vector3> GeometryData::getVertices() const {
		if (vertex) {
			return nonstd::span(vertex, vertexCount);
		}
		return {};
	}

	void GeometryData::markAsChanged() {
		++revisionID;
		// Avoid revisionID 0, which implies static data
		if (revisionID == 0) {
			++revisionID;
		}
	}
}
