#include "NIParticleModifier.h"

namespace NI {
	//
	// SphericalCollider
	//

	float SphericalCollider::getRadius() const {
		return radius;
	}
	void SphericalCollider::setRadius(float r) {
		radius = r;
		radiusSquared = r * r;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleModifier)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Gravity)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleBomb)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleColorModifier)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleGrowFade)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleRotation)

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ParticleCollider)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::PlanarCollider)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::SphericalCollider)
