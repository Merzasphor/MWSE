#include "NISkinInstance.h"

namespace NI {
	std::span<unsigned short> SkinPartition::Partition::getBones() {
		if (bones) {
			return std::span<unsigned short>(bones, numBones);
		}
		return {};
	}

	std::span<unsigned short> SkinPartition::Partition::getStripLengths() {
		if (bones) {
			return std::span<unsigned short>(stripLengths, numStripLengths);
		}
		return {};
	}

	std::span<Triangle> SkinPartition::Partition::getTriangles() {
		if (triangles) {
			return std::span<Triangle>(triangles, numTriangles);
		}
		return {};
	}

	std::span<unsigned short> SkinPartition::Partition::getVertices() {
		if (vertices) {
			return std::span<unsigned short>(vertices, numVertices);
		}
		return {};
	}

	std::span<SkinPartition::Partition> SkinPartition::getPartitions() {
		if (partitions) {
			return std::span<Partition>(partitions, partitionCount);
		}
		return {};
	}

	std::span<SkinData::BoneData::VertexWeight> SkinData::BoneData::getWeights() {
		if (weights) {
			return std::span<VertexWeight>(weights, weightCount);
		}
		return {};
	}

	std::span<SkinData::BoneData> SkinData::getBones() {
		if (boneData) {
			return std::span<BoneData>(boneData, numBones);
		}
		return {};
	}

	std::span<AVObject*> SkinInstance::getBoneObjects() {
		if (bones) {
			return std::span<AVObject*>(bones, skinData->numBones);
		}
		return {};
	}
}
