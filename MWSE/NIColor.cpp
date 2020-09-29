#include "NIColor.h"

namespace NI {
	Color::Color(TES3::Vector3& vector) {
		r = vector.x;
		g = vector.y;
		b = vector.z;
	}

	Color::Color(sol::table table) {
		r = table.get_or("r", table.get_or(1, 0.0f));
		g = table.get_or("g", table.get_or(2, 0.0f));
		b = table.get_or("b", table.get_or(3, 0.0f));
	}

	Color::Color(sol::object object) {
		if (object.is<TES3::Vector3>()) {
			Color(object.as<TES3::Vector3>());
		}
		else if (object.is<sol::table>()) {
			Color(object.as<sol::table>());
		}
		throw std::invalid_argument("Could not convert lua object to NiColor.");
	}

	Color& Color::operator=(const TES3::Vector3& vector) {
		r = vector.x;
		g = vector.y;
		b = vector.z;
		return *this;
	}

	Color& Color::operator=(const sol::table table) {
		r = table.get_or("r", table.get_or(1, 0.0f));
		g = table.get_or("g", table.get_or(2, 0.0f));
		b = table.get_or("b", table.get_or(3, 0.0f));
		return *this;
	}

	Color& Color::operator=(const sol::object object) {
		if (object.is<TES3::Vector3>()) {
			*this = object.as<TES3::Vector3>();
		}
		else if (object.is<sol::table>()) {
			*this = object.as<sol::table>();
		}
		else {
			throw std::invalid_argument("Could not convert lua object to NiColor.");
		}
		return *this;
	}

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
