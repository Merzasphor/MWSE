#include "NITriShapeData.h"

#include "ExceptionUtil.h"
#include "MemoryUtil.h"

namespace NI {
	Pointer<TriShapeData> TriShapeData::create(unsigned short _vertexCount, Vector3* _vertices, Vector3* _normals, PackedColor* _colors, Vector2* _textureCoords, unsigned short _triangleCount, unsigned short* _triangleList, int unused) {
#if defined(SE_NI_TRISHAPEDATA_FNADDR_CREATE) && SE_NI_TRISHAPEDATA_FNADDR_CREATE > 0
		const auto NI_TriShapeData_ctor = reinterpret_cast<void(__thiscall*)(TriShapeData*, unsigned short, Vector3*, Vector3*, PackedColor*, Vector2*, unsigned short, unsigned short*, int)>(SE_NI_TRISHAPEDATA_FNADDR_CREATE);

		auto ptr = se::memory::_new<TriShapeData>();
		NI_TriShapeData_ctor(ptr, _vertexCount, _vertices, _normals, _colors, _textureCoords, _triangleCount, _triangleList, unused);
		return ptr;
#else
		throw not_implemented_exception();
#endif
	}

	Pointer<TriShapeData> TriShapeData::copyData(bool copyNormals, bool copyColors, bool copyTextureCoordinates) const {
		auto vertexCount = getActiveVertexCount();

		Vector3* _vertices = se::memory::_new<Vector3>(vertexCount);
		memcpy_s(_vertices, sizeof(Vector3) * vertexCount, vertex, sizeof(Vector3) * vertexCount);

		Vector3* _normals = nullptr;
		if (normal && copyNormals) {
			_normals = se::memory::_new<Vector3>(vertexCount);
			memcpy_s(_normals, sizeof(Vector3) * vertexCount, normal, sizeof(Vector3) * vertexCount);
		}

		PackedColor* _colors = nullptr;
		if (color && copyColors) {
			_colors = se::memory::_new<PackedColor>(vertexCount);
			memcpy_s(_colors, sizeof(PackedColor) * vertexCount, color, sizeof(PackedColor) * vertexCount);
		}

		Vector2* _textureCoords = nullptr;
		if (textureCoords && copyTextureCoordinates) {
			_textureCoords = se::memory::_new<Vector2>(vertexCount);
			memcpy_s(_textureCoords, sizeof(Vector2) * vertexCount, textureCoords, sizeof(Vector2) * vertexCount);
		}

		unsigned short* _triangleList = nullptr;
		if (triangleList) {
			_triangleList = se::memory::_new<unsigned short>(triangleListLength);
			memcpy_s(_triangleList, sizeof(unsigned short) * triangleListLength, triangleList, sizeof(unsigned short) * triangleListLength);
		}

		auto result = create(vertexCount, _vertices, _normals, _colors, _textureCoords, triangleCount, _triangleList);

		// Copy over any other necessary data.
		result->bounds = bounds;

		return result;
	}
}
