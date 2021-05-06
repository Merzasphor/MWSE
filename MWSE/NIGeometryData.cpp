#include "NIGeometryData.h"

namespace NI {
	unsigned short GeometryData::getActiveVertexCount() {
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
		return nonstd::span(textureCoords, vertexCount * textureSets);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::GeometryData)
