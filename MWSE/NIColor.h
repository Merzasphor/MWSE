#pragma once

namespace NI {
	struct Color {
		float r; // 0x0
		float g; // 0x4
		float b; // 0x8

		__declspec(dllexport) Color() : r(0.0f), g(0.0f), b(0.0f) {}
		__declspec(dllexport) Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}

		__declspec(dllexport) bool operator==(const Color& c);
		__declspec(dllexport) bool operator!=(const Color& c);
		__declspec(dllexport) Color operator+(const Color&);
		__declspec(dllexport) Color operator-(const Color&);
		__declspec(dllexport) Color operator*(const Color&);
		__declspec(dllexport) Color operator*(const float);

		__declspec(dllexport) void clamp();
	};
	static_assert(sizeof(Color) == 0xC, "NI::Color failed size validation");
}
