#pragma once

#include "TES3Vectors.h"

namespace NI {
	struct Color {
		float r; // 0x0
		float g; // 0x4
		float b; // 0x8

		Color() : r(0.0f), g(0.0f), b(0.0f) {}
		Color(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
		Color(TES3::Vector3& vector);
		Color(sol::table table);
		Color(sol::object object);

		Color& operator=(const TES3::Vector3& vector);
		Color& operator=(const sol::table table);
		Color& operator=(const sol::object object);

		bool operator==(const Color& c);
		bool operator!=(const Color& c);
		Color operator+(const Color&);
		Color operator-(const Color&);
		Color operator*(const Color&);
		Color operator*(const float);

		//
		// Custom functions.
		//

		Color copy();
		TES3::Vector3 toVector3();

		void clamp();

		std::string toString();

	};
	static_assert(sizeof(Color) == 0xC, "NI::Color failed size validation");

	struct ColorA : Color {
		float a;

		ColorA() : Color(), a(0.0f) {}
		ColorA(float _r, float _g, float _b) : Color(_r, _g, _b), a(0.0f) {}
		ColorA(float _r, float _g, float _b, float _a) : Color(_r, _g, _b), a(_a) {}

		//
		// Custom functions.
		//

		std::string toString();

	};
	static_assert(sizeof(ColorA) == 0x10, "NI::ColorA failed size validation");
}
