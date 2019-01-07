#pragma once

namespace D3D {
	struct Vector {
		float x;
		float y;
		float z;
	};
	static_assert(sizeof(Vector) == 0xC, "D3D::Vector failed size validation");
}
