#include "NIGeometryData.h"

#include "NIColor.h"

namespace NI {
	unsigned short GeometryData::getActiveVertexCount() const {
		return vTable.asGeometryData->getActiveVertexCount(this);
	}

	void GeometryData::markAsChanged() {
		++revisionID;
		// Avoid revisionID 0, which implies static data
		if (revisionID == 0) {
			++revisionID;
		}
	}

	const auto NI_Bound_ComputeFromData = reinterpret_cast<void(__thiscall*)(NI::Bound*, int, TES3::Vector3*, unsigned int)>(0x6ED170);
	void GeometryData::updateModelBound() {
		NI_Bound_ComputeFromData(&bounds, vertexCount, vertex, sizeof(TES3::Vector3));
	}

	std::span<PackedColor> GeometryData::getColors() {
		if (color) {
			return std::span(color, vertexCount);
		}
		return {};
	}

	std::span<TES3::Vector3> GeometryData::getVertices() {
		if (vertex) {
			return std::span(vertex, vertexCount);
		}
		return {};
	}

	std::span<TES3::Vector3> GeometryData::getNormals() {
		if (normal) {
			return std::span(normal, vertexCount);
		}
		return {};
	}

	std::span<TES3::Vector2> GeometryData::getTextureCoordinates() {
		if (textureCoords) {
			return std::span(textureCoords, vertexCount * textureSets);
		}
		return {};
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::GeometryData)
