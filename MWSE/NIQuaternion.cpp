#include "NIQuaternion.h"
#include "TES3Vectors.h"

namespace NI {

	const auto NI_Quaternion_multiplyQuaternion = reinterpret_cast<Quaternion*(__thiscall*)(const Quaternion*, Quaternion*, const Quaternion*)>(0x6FB6A0);

	const auto NI_Quaternion_FromRotation = reinterpret_cast<TES3::Matrix33*(__thiscall*)(Quaternion*, const TES3::Matrix33*)>(0x6FBFC0);
	const auto NI_Quaternion_FromAngleAxis = reinterpret_cast<void(__thiscall*)(Quaternion*, float angle, const TES3::Vector3* axis)>(0x6FBDF0);
	const auto NI_Quaternion_ToAngleAxis = reinterpret_cast<void(__thiscall*)(const Quaternion*, float* angle, const TES3::Vector3* axis)>(0x6FBE20);

	const auto NI_Quaternion_Dot = reinterpret_cast<float (__cdecl*)(const Quaternion*, const Quaternion*)>(0x6FD9A0);
	const auto NI_Quaternion_Exp = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, const Quaternion*)>(0x6FD9D0);
	const auto NI_Quaternion_Log = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, const Quaternion*)>(0x6FB760);
	const auto NI_Quaternion_UnitInverse = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, const Quaternion*)>(0x6FB730);

	const auto NI_Quaternion_Slerp = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, float, const Quaternion*, const Quaternion*)>(0x6FB7F0);

	Quaternion::Quaternion() :
		w(0),
		x(0),
		y(0),
		z(0)
	{
	}

	Quaternion::Quaternion(float _w, float _x, float _y, float _z) :
		w(_w),
		x(_x),
		y(_y),
		z(_z)
	{
	}

	Quaternion Quaternion::operator-() const {
		return Quaternion { -w, -x, -y, -z };
	}

	Quaternion Quaternion::operator*(const Quaternion& q) const {
		Quaternion result;
		NI_Quaternion_multiplyQuaternion(this, &result, &q);
		return result;
	}

	std::ostream& operator<<(std::ostream& str, const Quaternion& q) {
		str << "{" << q.w << "," << q.x << "," << q.y << "," << q.z << "}";
		return str;
	}

	std::string Quaternion::toString() const {
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << std::dec << *this;
		return std::move(ss.str());
	}

	std::string Quaternion::toJson() const {
		std::ostringstream ss;
		ss << "{\"w\":" << w << ",\"x\":" << x << ",\"y\":" << y << ",\"z\":" << z << "}";
		return std::move(ss.str());
	}

	Quaternion Quaternion::copy() const {
		return Quaternion(w, x, y, z);
	}

	Quaternion Quaternion::invert() const {
		Quaternion result;
		NI_Quaternion_UnitInverse(&result, this);
		return result;
	}

	Quaternion Quaternion::exp() const {
		Quaternion result;
		NI_Quaternion_Exp(&result, this);
		return result;
	}

	Quaternion Quaternion::log() const {
		Quaternion result;
		NI_Quaternion_Log(&result, this);
		return result;
	}

	double Quaternion::dot(const Quaternion* q) const {
		// double precision as quaternions are sensitive to numerical issues.
		return NI_Quaternion_Dot(this, q);
	}

	bool Quaternion::normalize() {
		double length = std::sqrt(this->dot(this));
		if (length > 1e-5) {
			w = float(w / length);
			x = float(x / length);
			y = float(y / length);
			z = float(z / length);
			return true;
		}
		else {
			w = x = y = z = 0.0;
			return false;
		}
	}

	Quaternion Quaternion::normalized() const {
		Quaternion result = *this;
		result.normalize();
		return result;
	}

	Quaternion Quaternion::slerp(const Quaternion* q, float t) const {
		// Use shortest path interpolation.
		Quaternion q_closest = (this->dot(q) >= 0) ? *q : -*q;
		Quaternion result;

		// Normalize after interpolation to avoid numeric instability.
		NI_Quaternion_Slerp(&result, t, this, &q_closest);
		result.normalize();
		return result;
	}

	Quaternion Quaternion::slerpKeyframe(const Quaternion* q, float t) const {
		// As used in the animation system.
		Quaternion result;
		NI_Quaternion_Slerp(&result, t, this, q);
		return result;
	}

	Quaternion Quaternion::rotateTowards(const Quaternion* to, float rotationLimit) const {
		// Use shortest path inner product, clamp for numerical stability.
		double innerProduct = std::min(1.0, std::abs(this->dot(to)));
		double angle = 2.0 * std::acos(innerProduct);
		double t = 1.0;

		if (angle > 1e-5 && angle > rotationLimit) {
			t = std::max(0.0, std::min(1.0, rotationLimit / angle));
		}

		return slerp(to, float(t));
	}

	void Quaternion::fromAngleAxis(float angle, const TES3::Vector3* axis) {
		NI_Quaternion_FromAngleAxis(this, angle, axis);
	}

	std::tuple<float, TES3::Vector3> Quaternion::toAngleAxis() const {
		float angle;
		TES3::Vector3 axis;
		NI_Quaternion_ToAngleAxis(this, &angle, &axis);
		return std::make_tuple(angle, axis);
	}

	void Quaternion::fromRotation(const TES3::Matrix33* rotation) {
		NI_Quaternion_FromRotation(this, rotation);
	}

	TES3::Matrix33 Quaternion::toRotation() const {
		TES3::Matrix33 result;
		result.fromQuaternion(this);
		return result;
	}
}
