#pragma once

#include "NiTriBasedGeometry.h"

namespace NI {
	struct ParticlesData : TriBasedGeometryData {
		float radius; // 0x38
		unsigned short activeCount; // 0x3C
		float* sizes; // 0x40

		//
		// Accessor methods.
		//

		nonstd::span<float> getSizes();
	};
	static_assert(sizeof(ParticlesData) == 0x44, "NI::ParticlesData failed size validation");

	struct RotatingParticlesData : ParticlesData {
		NI::Quaternion* rotations; // 0x48

		//
		// Accessor methods.
		//

		nonstd::span<NI::Quaternion> getRotations();
	};
	static_assert(sizeof(RotatingParticlesData) == 0x48, "NI::RotatingParticlesData failed size validation");

	struct Particles : TriBasedGeometry {
		AVObject* unknown_0xAC;

		//
		// Accessor methods.
		//

		ParticlesData* getModelData() const { return static_cast<ParticlesData*>(modelData.get()); }
	};
	static_assert(sizeof(Particles) == 0xB0, "NI::Particles failed size validation");

	struct RotatingParticles : Particles {
		//
		// Accessor methods.
		//

		RotatingParticlesData* getModelData() const { return static_cast<RotatingParticlesData*>(modelData.get()); }
	};
	static_assert(sizeof(RotatingParticles) == 0xB0, "NI::RotatingParticles failed size validation");
}