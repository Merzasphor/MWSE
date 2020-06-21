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

	nonstd::span<ColorA> GeometryData::getColors() {
		return nonstd::span(color, vertexCount);
	}

	nonstd::span<TES3::Vector3> GeometryData::getVertices() {
		return nonstd::span(vertex, vertexCount);
	}

	nonstd::span<TES3::Vector3> GeometryData::getNormals() {
		return nonstd::span(normal, vertexCount);
	}

	nonstd::span<TES3::Vector2> GeometryData::getTextureCoordinates() {
		return nonstd::span(texture, vertexCount);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::GeometryData)
