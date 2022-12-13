#pragma once

#include "NIDefines.h"
#include "NIMatrix33.h"
#include "NIVector3.h"

namespace NI {
	struct Quaternion {
		float w;
		float x;
		float y;
		float z;

		Quaternion();
		Quaternion(float w, float x, float y, float z);

		Quaternion operator*(const Quaternion& q) const;

		friend std::ostream& operator<<(std::ostream& str, const Quaternion& q);
		std::string toString() const;
		std::string toJson() const;

		Quaternion copy() const;
		Quaternion invert() const;
		Quaternion slerp(const Quaternion* q, float t) const;

		void fromAngleAxis(float angle, const Vector3* axis);
		std::tuple<float, Vector3> toAngleAxis() const;

		void fromRotation(const Matrix33* rotation);
	};
	static_assert(sizeof(Quaternion) == 0x10, "NI::Quaternion failed size validation");
}
