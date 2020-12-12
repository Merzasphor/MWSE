#include "TES3Vectors.h"

#include "NIColor.h"

namespace TES3 {
	constexpr double MATH_PI = 3.14159265358979323846;
	constexpr double MATH_PI_2 = MATH_PI / 2;

	//
	// Vector2
	//

	Vector2::Vector2() :
		x(0),
		y(0)
	{

	}

	Vector2::Vector2(float _x, float _y) :
		x(_x),
		y(_y)
	{

	}

	Vector2 Vector2::copy() const {
		return *this;
	}

	//
	// Vector3
	//

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

	Vector3::Vector3(sol::table table) {
		x = table.get_or("x", table.get_or(1, 0.0f));
		y = table.get_or("y", table.get_or(2, 0.0f));
		z = table.get_or("z", table.get_or(3, 0.0f));
	}

	Vector3::Vector3(sol::object object) {
		if (object.is<NI::Color>()) {
			*this = NI::Color(object.as<NI::Color>());
		}
		else if (object.is<sol::table>()) {
			*this = NI::Color(object.as<sol::table>());
		}
		throw std::invalid_argument("Could not convert lua object to TES3Vector3.");
	}

	Vector3& Vector3::operator=(const NI::Color& vector) {
		x = vector.r;
		y = vector.g;
		z = vector.b;
		return *this;
	}

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

	bool Vector3::operator==(const Vector3& vec3) const {
		return x == vec3.x && y == vec3.y && z == vec3.z;
	}

	bool Vector3::operator!=(const Vector3& vec3) const {
		return x != vec3.x || y != vec3.y || z != vec3.z;
	}

	Vector3 Vector3::operator+(const Vector3& vec3) const {
		return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
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
		ss << "[\"x\":" << x << ",\"y\":" << y << ",\"z\":" << z << "]";
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

	Matrix33 Vector3::outerProduct(const Vector3* vec3) const {
		return Matrix33(
			(x * vec3->x), (y * vec3->x), (z * vec3->x),
			(x * vec3->y), (y * vec3->y), (z * vec3->y),
			(x * vec3->z), (y * vec3->z), (z * vec3->z)
		);
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

	//
	// Vector4
	//

	Vector4::Vector4() :
		x(0.0f),
		y(0.0f),
		z(0.0f),
		w(0.0f)
	{

	}

	Vector4::Vector4(float _x, float _y, float _z, float _w) :
		x(_x),
		y(_y),
		z(_z),
		w(_w)
	{

	}

	Vector4 Vector4::copy() const {
		return *this;
	}

	//
	// Matrix33
	//

	const auto TES3_Matrix33_testEqual = reinterpret_cast<bool(__thiscall*)(Matrix33*, const Matrix33*)>(0x6E7ED0);
	const auto TES3_Matrix33_addMatrix = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*, const Matrix33*)>(0x6E7F60);
	const auto TES3_Matrix33_subtractMatrix = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*, const Matrix33*)>(0x6E8000);
	const auto TES3_Matrix33_multiplyMatrix = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*, const Matrix33*)>(0x6E80A0);
	const auto TES3_Matrix33_multiplyVector = reinterpret_cast<Vector3 * (__thiscall*)(Matrix33*, Vector3*, const Vector3*)>(0x6E8230);
	const auto TES3_Matrix33_multiplyScalar = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*, float)>(0x6E81B0);

	const auto TES3_Matrix33_toIdentity = reinterpret_cast<void(__thiscall*)(Matrix33*)>(0x6E7CF0);
	const auto TES3_Matrix33_toRotationX = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x6E7D20);
	const auto TES3_Matrix33_toRotationY = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x6E7D60);
	const auto TES3_Matrix33_toRotationZ = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x6E7DA0);
	const auto TES3_Matrix33_toRotationXYZ = reinterpret_cast<void(__thiscall*)(Matrix33*, float, float, float, float)> (0x6E7DE0);

	const auto TES3_Matrix33_fromEulerXYZ = reinterpret_cast<void(__thiscall*)(Matrix33*, float, float, float)> (0x6E8D60);
	const auto TES3_Matrix33_toEulerXYZ = reinterpret_cast<bool(__thiscall*)(const Matrix33*, float*, float*, float*)> (0x6E8C50);

	const auto TES3_Matrix33_transpose = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*)> (0x6E8420);
	const auto TES3_Matrix33_inverseRaw = reinterpret_cast<bool(__thiscall*)(const Matrix33*, Matrix33*)> (0x6E82F0);
	const auto TES3_Matrix33_inverse = reinterpret_cast<Matrix33 * (__thiscall*)(const Matrix33*, Matrix33*)> (0x6E83E0);

	const auto TES3_Matrix33_reorthogonalize = reinterpret_cast<bool(__thiscall*)(Matrix33*)> (0x6E84A0);

	Matrix33::Matrix33() : m0(), m1(), m2() {

	}

	Matrix33::Matrix33(Vector3* in_m0, Vector3* in_m1, Vector3* in_m2) {
		m0 = *in_m0;
		m1 = *in_m1;
		m2 = *in_m2;
	}

	Matrix33::Matrix33(float m0x, float m0y, float m0z, float m1x, float m1y, float m1z, float m2x, float m2y, float m2z) {
		m0.x = m0x;
		m0.y = m0y;
		m0.z = m0z;
		m1.x = m1x;
		m1.y = m1y;
		m1.z = m1z;
		m2.x = m2x;
		m2.y = m2y;
		m2.z = m2z;
	}

	bool Matrix33::operator==(const Matrix33& matrix) {
		return TES3_Matrix33_testEqual(this, &matrix);
	}

	bool Matrix33::operator!=(const Matrix33& matrix) {
		return m0.x != matrix.m0.x
			|| m0.y != matrix.m0.y
			|| m0.z != matrix.m0.z
			|| m1.x != matrix.m1.x
			|| m1.y != matrix.m1.y
			|| m1.z != matrix.m1.z
			|| m2.x != matrix.m2.x
			|| m2.y != matrix.m2.y
			|| m2.z != matrix.m2.z;
	}

	Matrix33 Matrix33::operator+(const Matrix33& matrix) {
		Matrix33 result;
		TES3_Matrix33_addMatrix(this, &result, &matrix);
		return result;
	}

	Matrix33 Matrix33::operator-(const Matrix33& matrix) {
		Matrix33 result;
		TES3_Matrix33_subtractMatrix(this, &result, &matrix);
		return result;
	}

	Matrix33 Matrix33::operator*(const Matrix33& matrix) {
		Matrix33 result;
		TES3_Matrix33_multiplyMatrix(this, &result, &matrix);
		return result;
	}

	Vector3 Matrix33::operator*(const Vector3& vector) {
		Vector3 result;
		TES3_Matrix33_multiplyVector(this, &result, &vector);
		return result;
	}

	Matrix33 Matrix33::operator*(float scalar) {
		Matrix33 result;
		TES3_Matrix33_multiplyScalar(this, &result, scalar);
		return result;
	}

	std::ostream& operator<<(std::ostream& str, const Matrix33& matrix) {
		str << "[" << matrix.m0 << "," << matrix.m1 << "," << matrix.m2 << "]";
		return str;
	}

	std::string Matrix33::toString() const {
		std::ostringstream ss;
		ss << std::fixed << std::setprecision(2) << std::dec << *this;
		return std::move(ss.str());
	}

	std::string Matrix33::toJson() const {
		std::ostringstream ss;
		ss << "["
			<< "[" << m0.x << "," << m0.y << "," << m0.z << "],"
			<< "[" << m1.x << "," << m1.y << "," << m1.z << "],"
			<< "[" << m2.x << "," << m2.y << "," << m2.z << "]"
			<< "]";
		return std::move(ss.str());
	}

	Matrix33 Matrix33::copy() const {
		return *this;
	}

	void Matrix33::toZero() {
		m0.x = 0.0f;
		m0.y = 0.0f;
		m0.z = 0.0f;
		m1.x = 0.0f;
		m1.y = 0.0f;
		m1.z = 0.0f;
		m2.x = 0.0f;
		m2.y = 0.0f;
		m2.z = 0.0f;
	}

	void Matrix33::toIdentity() {
		TES3_Matrix33_toIdentity(this);
	}

	void Matrix33::toRotationX(float value) {
		TES3_Matrix33_toRotationX(this, value);
	}

	void Matrix33::toRotationY(float value) {
		TES3_Matrix33_toRotationY(this, value);
	}

	void Matrix33::toRotationZ(float value) {
		TES3_Matrix33_toRotationZ(this, value);
	}

	void Matrix33::toRotation(float angle, float x, float y, float z) {
		TES3_Matrix33_toRotationXYZ(this, angle, x, y, z);
	}

	void Matrix33::fromEulerXYZ(float x, float y, float z) {
		TES3_Matrix33_fromEulerXYZ(this, x, y, z);
	}

	Matrix33 Matrix33::transpose() {
		Matrix33 result;
		TES3_Matrix33_transpose(this, &result);
		return result;
	}

	Matrix33 Matrix33::invert() const {
		Matrix33 result;
		TES3_Matrix33_inverse(this, &result);
		return result;
	}

	bool Matrix33::invert(Matrix33* out_matrix) const {
		return TES3_Matrix33_inverseRaw(this, out_matrix);
	}

	std::tuple<Matrix33, bool> Matrix33::invert_lua() const {
		Matrix33 matrix;
		bool valid = invert(&matrix);
		return std::make_tuple(matrix, valid);
	}

	bool Matrix33::reorthogonalize() {
		return TES3_Matrix33_reorthogonalize(this);
	}

	bool Matrix33::toEulerXYZ(float * x, float * y, float * z) const {
		return TES3_Matrix33_toEulerXYZ(this, x, y, z);
	}

	std::tuple<Vector3, bool> Matrix33::toEulerXYZ_lua() const {
		float x, y, z;
		bool isUnique = toEulerXYZ(&x, &y, &z);
		return std::make_tuple(Vector3(x, y, z), isUnique);
	}

	bool Matrix33::toEulerZYX(float* x, float* y, float* z) const {
		*x = 0; 
		*y = asin(m2.x);
		*z = 0;

		if (*y < MATH_PI_2) {
			if (*y > -MATH_PI_2) {
				*z = -atan2(m1.x, m0.x);
				*x = -atan2(m2.y, m2.z);
				return true;
			}
			else {
				*z = atan2(-m0.y, m0.z);
				return false;
			}
		}
		else {
			*z = -atan2(-m0.y, m0.z);
			return false;
		}
	}

	std::tuple<Vector3, bool> Matrix33::toEulerZYX_lua() const {
		float x, y, z = 0.0f;
		bool isUnique = toEulerZYX(&x, &y, &z);
		return std::make_tuple(Vector3(x, y, z), isUnique);
	}

	//
	// BoundingBox
	//

	BoundingBox BoundingBox::copy() const {
		return *this;
	}

	//
	// Transform
	//

	Transform Transform::copy() const {
		return *this;
	}

}

