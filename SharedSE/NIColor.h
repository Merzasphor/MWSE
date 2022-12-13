#pragma once

namespace NI {
	struct PackedColor {
		unsigned char b; // 0x0
		unsigned char g; // 0x1
		unsigned char r; // 0x2
		unsigned char a; // 0x3
	};
	static_assert(sizeof(PackedColor) == 0x4, "NI::PackedColor failed size validation");

	struct Color {
		float r;
		float b;
		float g;

		Color(float _r, float _g, float _b);
	};
}
