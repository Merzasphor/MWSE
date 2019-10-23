#pragma once

#include "NiTriBasedGeometryData.h"

namespace NI {
	struct TriShapeData : TriBasedGeometryData {
		unsigned int triangleListLength; // 0x38
		unsigned short* triangleList; // 0x3C
		void* sharedNormals; // 0x40
		unsigned short sharedNormalsArraySize; // 0x44
	};
	static_assert(sizeof(TriShapeData) == 0x48, "NI::TriShapeData failed size validation");
}
