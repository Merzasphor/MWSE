#include "NITransform.h"

namespace NI {
	Transform Transform::operator*(const Transform& b) const {
		return {
			rotation * b.rotation,
			translation + b.translation,
			scale * b.scale
		};
	}

	void Transform::toIdentity() {
		rotation.toIdentity();
		translation = {};
		scale = 1.0f;
	}
}
