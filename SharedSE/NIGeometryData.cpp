#include "NIGeometryData.h"

namespace NI {
	nonstd::span<Vector3> GeometryData::getVertices() const {
		if (vertex) {
			return nonstd::span(vertex, vertexCount);
		}
		return {};
	}
}
