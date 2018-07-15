#include "TES3Vectors.h"

#include <cmath>

namespace TES3 {
	Vector3 Vector3::operator+(const Vector3& vec3) {
		return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
	}

	Vector3 Vector3::operator-(const Vector3& vec3) {
		return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
	}

	Vector3 Vector3::operator*(const Vector3 & vec3) {
		return Vector3(x * vec3.x, y * vec3.y, z * vec3.z);
	}

	Vector3 Vector3::operator*(const float scalar) {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 Vector3::crossProduct(Vector3* vec3) {
		return Vector3(y * vec3->z - z * vec3->y, z * vec3->x - vec3->z * x, x * vec3->y - y * vec3->x);
	}

	float Vector3::dotProduct(Vector3* vec3) {
		return vec3->z * z + vec3->y * y + vec3->x * x;
	}

	float Vector3::heightDifference(Vector3* vec3) {
		return fabs(z - vec3->z);
	}

	float Vector3::distance(Vector3* vec3) {
		float dx = x - vec3->x;
		float dy = y - vec3->y;
		float dz = z - vec3->z;
		return sqrt(dz * dz + dx * dx + dy * dy);
	}

	float Vector3::length() {
		return sqrt(x * x + y * y + z * z);
	}

	void Vector3::negate() {
		x = -x;
		y = -y;
		z = -z;
	}
}
