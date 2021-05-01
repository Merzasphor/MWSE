#include "NISkinInstance.h"

namespace NI {
	nonstd::span<unsigned short> SkinPartition::Partition::getBones() {
		return nonstd::span<unsigned short>(bones, numBones);
	}

	nonstd::span<unsigned short> SkinPartition::Partition::getStripLengths() {
		return nonstd::span<unsigned short>(bones, numBones);
	}

	nonstd::span<unsigned short> SkinPartition::Partition::getTriangles() {
		return nonstd::span<unsigned short>(triangles, numTriangles);
	}

	nonstd::span<unsigned short> SkinPartition::Partition::getVertices() {
		return nonstd::span<unsigned short>(vertices, numVertices);
	}

	nonstd::span<SkinPartition::Partition> SkinPartition::getPartitions() {
		return nonstd::span<Partition>(partitions, partitionCount);
	}

	nonstd::span<SkinData::BoneData::VertexWeight> SkinData::BoneData::getWeights() {
		return nonstd::span<VertexWeight>(weights, weightCount);
	}

	nonstd::span<SkinData::BoneData> SkinData::getBones() {
		return nonstd::span<BoneData>(boneData, numBones);
	}

	nonstd::span<AVObject*> SkinInstance::getBoneObjects() {
		return nonstd::span<AVObject*>(bones, skinData->numBones);
	}
}
