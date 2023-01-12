#pragma once

#include "NiTriBasedGeometryData.h"

#include "NITriangle.h"

namespace NI {
	struct TriShapeData : TriBasedGeometryData {
		unsigned int triangleListLength; // 0x38
		Triangle* triangleList; // 0x3C
		void* sharedNormals; // 0x40
		unsigned short sharedNormalsArraySize; // 0x44

		//
		// Other related this-call functions.
		//

		static Pointer<TriShapeData> create(unsigned short _vertexCount, Vector3* _vertices, Vector3* _normals, PackedColor* _colors, Vector2* _textureCoords, unsigned short _triangleCount, unsigned short* _triangleList, int unused = 0);

		//
		// Custom functions.
		//

		Pointer<TriShapeData> copyData(bool copyNormals = true, bool copyColors = true, bool copyTextureCoordinates = true) const;
		nonstd::span<Triangle> getTriangles();

	};
	static_assert(sizeof(TriShapeData) == 0x48, "NI::TriShapeData failed size validation");
}
