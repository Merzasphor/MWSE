#pragma once

#include "NIObject.h"

#include "NISkinPartition.h"
#include "NIBound.h"

#include "TES3Vectors.h"

namespace NI {
	struct SkinData : Object {
		struct BoneData {
			struct VertexWeight {
				unsigned short index; // 0x0
				float weight; // 0x4
			};
			TES3::Matrix33 rotation; // 0x0
			TES3::Vector3 translation; // 0x24
			float scale; // 0x30
			Bound bounds; // 0x34
			VertexWeight* weights; // 0x48
			unsigned short weightCount; // 0x48
		};
		Pointer<SkinPartition> partition; // 0x8
		TES3::Matrix33 rotation; // 0xC
		TES3::Vector3 translation; // 0x30
		float scale; // 0x3C
		unsigned int numBones; // 0x40
		BoneData* boneData; // 0x44
	};
	static_assert(sizeof(SkinData) == 0x48, "NI::SkinData failed size validation");
	static_assert(sizeof(SkinData::BoneData) == 0x4C, "NI::SkinData::BoneData failed size validation");
	static_assert(sizeof(SkinData::BoneData::VertexWeight) == 0x8, "NI::SkinData::VertexWeight failed size validation");

	struct SkinInstance : Object {
		Pointer<SkinData> skinData; // 0x8
		Pointer<Node> rootParent; // 0xC
		void* bones; // 0x10
		int unknown_0x14;
	};
	static_assert(sizeof(SkinInstance) == 0x18, "NI::SkinInstance failed size validation");
}
