#include "NIQuaternion.h"

#include "ExceptionUtil.h"

namespace NI {
	Quaternion::Quaternion() :
		w(0.0f),
		x(0.0f),
		y(0.0f),
		z(0.0f)
	{

	}

	Quaternion::Quaternion(float _w, float _x, float _y, float _z) :
		w(_w),
		x(_x),
		y(_y),
		z(_z)
	{

	}

	Quaternion Quaternion::operator*(const Quaternion& q) const {
#if defined(SE_NI_QUATERNION_FNADDR_MULTIPLYQUATERNION) && SE_NI_QUATERNION_FNADDR_MULTIPLYQUATERNION > 0
		const auto NI_Quaternion_multiplyQuaternion = reinterpret_cast<Quaternion * (__thiscall*)(const Quaternion*, Quaternion*, const Quaternion*)>(SE_NI_QUATERNION_FNADDR_MULTIPLYQUATERNION);

		Quaternion result;
		NI_Quaternion_multiplyQuaternion(this, &result, &q);
		return result;
#else
		throw not_implemented_exception();
#endif
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
#if defined(SE_NI_QUATERNION_FNADDR_INVERT) && SE_NI_QUATERNION_FNADDR_INVERT > 0
		const auto NI_Quaternion_UnitInverse = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, const Quaternion*)>(SE_NI_QUATERNION_FNADDR_INVERT);

		Quaternion result;
		NI_Quaternion_UnitInverse(&result, this);
		return result;
#else
		throw not_implemented_exception();
#endif
	}

	Quaternion Quaternion::slerp(const Quaternion* q, float t) const {
#if defined(SE_NI_QUATERNION_FNADDR_SLERP) && SE_NI_QUATERNION_FNADDR_SLERP > 0
		const auto NI_Quaternion_Slerp = reinterpret_cast<Quaternion * (__cdecl*)(Quaternion*, float, const Quaternion*, const Quaternion*)>(SE_NI_QUATERNION_FNADDR_SLERP);

		Quaternion result;
		NI_Quaternion_Slerp(&result, t, this, q);
		return result;
#else
		throw not_implemented_exception();
#endif
	}

	void Quaternion::fromAngleAxis(float angle, const NI::Vector3* axis) {
#if defined(SE_NI_QUATERNION_FNADDR_FROMANGLEAXIS) && SE_NI_QUATERNION_FNADDR_FROMANGLEAXIS > 0
		const auto NI_Quaternion_FromAngleAxis = reinterpret_cast<void(__thiscall*)(Quaternion*, float angle, const NI::Vector3 * axis)>(SE_NI_QUATERNION_FNADDR_FROMANGLEAXIS);

		NI_Quaternion_FromAngleAxis(this, angle, axis);
#else
		throw not_implemented_exception();
#endif
	}

	std::tuple<float, NI::Vector3> Quaternion::toAngleAxis() const {
#if defined(SE_NI_QUATERNION_FNADDR_TOANGLEAXIS) && SE_NI_QUATERNION_FNADDR_TOANGLEAXIS > 0
		const auto NI_Quaternion_ToAngleAxis = reinterpret_cast<void(__thiscall*)(const Quaternion*, float* angle, const NI::Vector3 * axis)>(SE_NI_QUATERNION_FNADDR_TOANGLEAXIS);

		float angle;
		NI::Vector3 axis;
		NI_Quaternion_ToAngleAxis(this, &angle, &axis);
		return std::make_tuple(angle, axis);
#else
		throw not_implemented_exception();
#endif
	}

	void Quaternion::fromRotation(const NI::Matrix33* rotation) {
#if defined(SE_NI_QUATERNION_FNADDR_FROMROTATION) && SE_NI_QUATERNION_FNADDR_FROMROTATION > 0
		const auto NI_Quaternion_FromRotation = reinterpret_cast<NI::Matrix33 * (__thiscall*)(Quaternion*, const NI::Matrix33*)>(SE_NI_QUATERNION_FNADDR_FROMROTATION);

		NI_Quaternion_FromRotation(this, rotation);
#else
		throw not_implemented_exception();
#endif
	}
}
