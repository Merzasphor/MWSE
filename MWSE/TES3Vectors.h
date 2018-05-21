#pragma once

namespace TES3 {
	struct Vector2 {
		float x;
		float y;

		Vector2() : x(0), y(0) {}
		Vector2(float _x, float _y) : x(_x), y(_y) {}
	};
	static_assert(sizeof(Vector2) == 0x8, "TES3::Vector2 failed size validation");

	struct Vector3 : Vector2 {
		float z;

		Vector3() : Vector2(), z(0) {}
		Vector3(float _x, float _y, float _z) : Vector2(_x, _y), z(_z) {}
	};
	static_assert(sizeof(Vector3) == 0xC, "TES3::Vector3 failed size validation");

	struct Vector4 : Vector3 {
		float w;

		Vector4() : Vector3(), w(0) {}
		Vector4(float _x, float _y, float _z, float _w) : Vector3(_x, _y, _z), w(_w) {}
	};
	static_assert(sizeof(Vector4) == 0x10, "TES3::Vector4 failed size validation");

	struct Matrix33 {
		Vector3 m0;
		Vector3 m1;
		Vector3 m2;
	};
	static_assert(sizeof(Matrix33) == 0x24, "TES3::Matrix33 failed size validation");

	struct BoundingBox {
		Vector3 minimum;
		Vector3 maximum;
	};
	static_assert(sizeof(BoundingBox) == 0x18, "TES3::BoundingBox failed size validation");
}
