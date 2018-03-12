#pragma once

namespace D3D {
	struct ColorValue {
		float r;
		float g;
		float b;
		float a;
	};
	static_assert(sizeof(ColorValue) == 0x10, "TES3::ColorValue failed size validation");
}
