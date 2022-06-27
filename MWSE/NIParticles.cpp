#include "NIParticles.h"

namespace NI {
	nonstd::span<float> ParticlesData::getSizes() {
		if (sizes) {
			return nonstd::span(sizes, vertexCount);
		}
		return {};
	}

	nonstd::span<NI::Quaternion> RotatingParticlesData::getRotations() {
		if (rotations) {
			return nonstd::span(rotations, vertexCount);
		}
		return {};
	}
}