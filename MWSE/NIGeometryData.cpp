#include "NIGeometryData.h"

namespace NI {
	unsigned short GeometryData::getVertexCount() {
		return vTable.asGeometryData->getVertexCount(this);
	}

	GeometryData::Consistency GeometryData::getConsistency() {
		return (Consistency)(dirtyFlags & Consistency::Mask);
	}

	void GeometryData::markAsChanged(unsigned short flags) {
		if (getConsistency() == Consistency::Static) {
			throw std::runtime_error("Consistency for geometry cannot be static.");
		}
		dirtyFlags |= (flags & Mask::Dirty);
	}
}
