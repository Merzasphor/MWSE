#pragma once

namespace NI {
	struct Color {
		float r; // 0x0
		float g; // 0x4
		float b; // 0x8

		Color() : r(0.0f), g(0.0f), b(0.0f) {}
		Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}

		bool operator==(const Color& c);
		bool operator!=(const Color& c);
		Color operator+(const Color&);
		Color operator-(const Color&);
		Color operator*(const Color&);
		Color operator*(const float);

		void clamp();
	};
	static_assert(sizeof(Color) == 0xC, "NI::Color failed size validation");
}
