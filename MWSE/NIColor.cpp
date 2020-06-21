#include "NIColor.h"

namespace NI {
	bool Color::operator==(const Color& c) {
		return r == c.r && g == c.g && b == c.b;
	}

	bool Color::operator!=(const Color& c) {
		return r != c.r || g != c.g || b != c.b;
	}

	Color Color::operator+(const Color& c) {
		return Color(r + c.r, g + c.g, b + c.b);
	}

	Color Color::operator-(const Color& c) {
		return Color(r - c.r, g - c.g, b - c.b);
	}

	Color Color::operator*(const Color & c) {
		return Color(r * c.r, g * c.g, b * c.b);
	}

	Color Color::operator*(const float scalar) {
		return Color(r * scalar, g * scalar, b * scalar);
	}

	Color Color::copy() {
		return *this;
	}

	TES3::Vector3 Color::toVector3() {
		return TES3::Vector3(r, g, b);
	}

	void Color::clamp() {
		r = std::fmax(0.0f, std::fmin(r, 1.0f));
		g = std::fmax(0.0f, std::fmin(g, 1.0f));
		b = std::fmax(0.0f, std::fmin(b, 1.0f));
	}

	std::string Color::toString() {
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << "<" << r << ", " << g << ", " << b << ">";
		return std::move(ss.str());
	}

	std::string ColorA::toString() {
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << "<" << r << ", " << g << ", " << b << ", " << a << ">";
		return std::move(ss.str());
	}
}
