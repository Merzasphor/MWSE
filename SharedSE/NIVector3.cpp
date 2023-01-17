#include "NIVector3.h"

namespace NI {
	const Vector3 Vector3::DirectionDown = { 0.0f, 0.0f, -1.0f };

	Vector3::Vector3() :
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{

	}

	Vector3::Vector3(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z)
	{

	}

	Vector3::Vector3(NI::Color& color) {
		x = color.r;
		y = color.g;
		z = color.b;
	}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
	Vector3::Vector3(sol::table table) {
		x = table.get_or("x", table.get_or(1, 0.0f));
		y = table.get_or("y", table.get_or(2, 0.0f));
		z = table.get_or("z", table.get_or(3, 0.0f));
	}
#endif

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
	Vector3::Vector3(sol::object object) {
		if (object.is<NI::Color>()) {
			*this = NI::Color(object.as<NI::Color>());
		}
		else if (object.is<sol::table>()) {
			*this = NI::Color(object.as<sol::table>());
		}
		throw std::invalid_argument("Could not convert lua object to TES3Vector3.");
	}
#endif

	Vector3& Vector3::operator=(const NI::Color& vector) {
		x = vector.r;
		y = vector.g;
		z = vector.b;
		return *this;
	}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
	Vector3& Vector3::operator=(const sol::table table) {
		x = table.get_or("x", table.get_or(1, 0.0f));
		y = table.get_or("y", table.get_or(2, 0.0f));
		z = table.get_or("z", table.get_or(3, 0.0f));
		return *this;
	}

	Vector3& Vector3::operator=(const sol::object object) {
		if (object.is<NI::Color>()) {
			*this = object.as<NI::Color>();
		}
		else if (object.is<sol::table>()) {
			*this = object.as<sol::table>();
		}
		else {
			throw std::invalid_argument("Could not convert lua object to NiColor.");
		}
		return *this;
	}
#endif

	bool Vector3::operator==(const Vector3& vec3) const {
		return x == vec3.x && y == vec3.y && z == vec3.z;
	}

	bool Vector3::operator!=(const Vector3& vec3) const {
		return x != vec3.x || y != vec3.y || z != vec3.z;
	}

	Vector3 Vector3::operator+(const Vector3& vec3) const {
		return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
	}

	Vector3 Vector3::operator-() const {
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator-(const Vector3& vec3) const {
		return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
	}

	Vector3 Vector3::operator*(const Vector3& vec3) const {
		return Vector3(x * vec3.x, y * vec3.y, z * vec3.z);
	}

	Vector3 Vector3::operator*(const float scalar) const {
		return Vector3(x * scalar, y * scalar, z * scalar);
	}

	Vector3 Vector3::operator/(const float scalar) const {
		return Vector3(x / scalar, y / scalar, z / scalar);
	}

	std::ostream& operator<<(std::ostream& str, const Vector3& vector) {
		str << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
		return str;
	}

	std::string Vector3::toString() const {
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << std::dec << *this;
		return std::move(ss.str());
	}

	std::string Vector3::toJson() const {
		std::ostringstream ss;
		ss << "{\"x\":" << x << ",\"y\":" << y << ",\"z\":" << z << "}";
		return std::move(ss.str());
	}

	Vector3 Vector3::copy() const {
		return *this;
	}

	NI::Color Vector3::toNiColor() const {
		return NI::Color(x, y, z);
	}

	Vector3 Vector3::crossProduct(const Vector3* vec3) const {
		return Vector3(y * vec3->z - z * vec3->y, z * vec3->x - vec3->z * x, x * vec3->y - y * vec3->x);
	}

	float Vector3::dotProduct(const Vector3* vec3) const {
		return vec3->z * z + vec3->y * y + vec3->x * x;
	}

	Vector3 Vector3::lerp(const Vector3& to, float transition) const {
		auto transA = 1.0f - transition;
		return Vector3(x * transA + to.x * transition, y * transA + to.y * transition, z * transA + to.z * transition);
	}

	float Vector3::heightDifference(const Vector3* vec3) const {
		return fabs(z - vec3->z);
	}

	float Vector3::distance(const Vector3* vec3) const {
		float dx = x - vec3->x;
		float dy = y - vec3->y;
		float dz = z - vec3->z;
		return sqrt(dz * dz + dx * dx + dy * dy);
	}

	float Vector3::angle(const Vector3* v) const {
		return acosf(dotProduct(v) / (length() * v->length()));
	}

	float Vector3::length() const {
		return sqrt(x * x + y * y + z * z);
	}

	void Vector3::negate() {
		x = -x;
		y = -y;
		z = -z;
	}

	bool Vector3::normalize() {
		float len = length();
		if (len > 0.0f) {
			x = x / len;
			y = y / len;
			z = z / len;
			return true;
		}
		x = 0;
		y = 0;
		z = 0;
		return false;
	}

	Vector3 Vector3::normalized() const {
		auto copy = Vector3(x, y, z);
		copy.normalize();
		return copy;
	}

	Vector3 Vector3::interpolate(const Vector3& targetPoint, const float distance) const {
		auto line = targetPoint - *this;
		if (line.normalize()) {
			return *this + (line * distance);
		}
		return Vector3();
	}
}
