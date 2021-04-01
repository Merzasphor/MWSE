#pragma once

#include "NIObject.h"

namespace NI {
	struct SkinPartition : Object {
		struct Partition {
			void* vtbl;
			unsigned short* bones; // 0x4
			float* weights; // 0x8
			unsigned short* vertices; // 0xC
			unsigned char* bonePalette; // 0x10
			unsigned short* triangles; // 0x14
			unsigned short* stripLengths; // 0x18
			unsigned short numVertices; // 0x1C
			unsigned short numTriangles; // 0x1E
			unsigned short numBones; // 0x20
			unsigned short numStripLengths; // 0x22
			unsigned short numBonesPerVertex; // 0x24
			void* bufferData; // 0x28
		};
		unsigned int partitionCount; // 0x8
		Partition* partitions; // 0xC
	};
	static_assert(sizeof(SkinPartition) == 0x10, "NI::SkinPartition failed size validation");
	static_assert(sizeof(SkinPartition::Partition) == 0x2C, "NI::SkinPartition::Partition failed size validation");
}
