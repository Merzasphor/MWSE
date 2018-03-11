#pragma once

namespace D3D {
	struct Vector {
		float x;
		float y;
		float z;
	};
	static_assert(sizeof(Vector) == 0xC, "TES3::Vector failed size validation");
}
