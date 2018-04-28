#pragma once

namespace TES3 {
	struct Vector2 {
		float x;
		float y;
	};
	static_assert(sizeof(Vector2) == 0x8, "TES3::Vector2 failed size validation");

	struct Vector3 : Vector2 {
		float z;
	};
	static_assert(sizeof(Vector3) == 0xC, "TES3::Vector3 failed size validation");

	struct Vector4 : Vector3 {
		float w;
	};
	static_assert(sizeof(Vector4) == 0x10, "TES3::Vector4 failed size validation");

	struct Matrix33 {
		Vector3 m0;
		Vector3 m1;
		Vector3 m2;
	};
	static_assert(sizeof(Matrix33) == 0x24, "TES3::Vector3 failed size validation");
}
