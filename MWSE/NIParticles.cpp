#include "NIParticles.h"

#include "NIQuaternion.h"

namespace NI {
	std::span<float> ParticlesData::getSizes() {
		if (sizes) {
			return std::span(sizes, vertexCount);
		}
		return {};
	}

	std::span<NI::Quaternion> RotatingParticlesData::getRotations() {
		if (rotations) {
			return std::span(rotations, vertexCount);
		}
		return {};
	}
}