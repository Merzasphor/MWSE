#pragma once

namespace TES3 {
	struct Matrix33;

	template <typename T>
	struct Range {
		T min;
		T max;
	};
	static_assert(sizeof(Range<int>) == 0x8, "TES3::Range<int> failed size validation");

	struct Vector2 {
		float x;
		float y;

		__declspec(dllexport) Vector2() : x(0), y(0) {}
		__declspec(dllexport) Vector2(float _x, float _y) : x(_x), y(_y) {}
	};
	static_assert(sizeof(Vector2) == 0x8, "TES3::Vector2 failed size validation");

	struct Vector3 : Vector2 {
		float z;

		__declspec(dllexport) Vector3() : Vector2(), z(0) {}
		__declspec(dllexport) Vector3(float _x, float _y, float _z) : Vector2(_x, _y), z(_z) {}

		__declspec(dllexport) bool operator==(const Vector3& matrix);
		__declspec(dllexport) bool operator!=(const Vector3& matrix);
		__declspec(dllexport) Vector3 operator+(const Vector3&);
		__declspec(dllexport) Vector3 operator-(const Vector3&);
		__declspec(dllexport) Vector3 operator*(const Vector3&);
		__declspec(dllexport) Vector3 operator*(const float);

		//
		// Associated functions.
		//

		__declspec(dllexport) Vector3 crossProduct(Vector3*);
		__declspec(dllexport) float dotProduct(Vector3*);
		__declspec(dllexport) Matrix33 outerProduct(Vector3*);
			
		__declspec(dllexport) float heightDifference(Vector3*);
		__declspec(dllexport) float distance(Vector3*);
		__declspec(dllexport) float length();
		__declspec(dllexport) void negate();
		__declspec(dllexport) bool normalize();
		__declspec(dllexport) Vector3 normalized();

	};
	static_assert(sizeof(Vector3) == 0xC, "TES3::Vector3 failed size validation");

	struct Vector4 : Vector3 {
		float w;

		__declspec(dllexport) Vector4() : Vector3(), w(0) {}
		__declspec(dllexport) Vector4(float _x, float _y, float _z, float _w) : Vector3(_x, _y, _z), w(_w) {}
	};
	static_assert(sizeof(Vector4) == 0x10, "TES3::Vector4 failed size validation");

	struct Matrix33 {
		Vector3 m0;
		Vector3 m1;
		Vector3 m2;

		__declspec(dllexport) Matrix33();
		__declspec(dllexport) Matrix33(Vector3* m0, Vector3* m1, Vector3* m2);
		__declspec(dllexport) Matrix33(float m0x, float m0y, float m0z, float m1x, float m1y, float m1z, float m2x, float m2y, float m2z);

		//
		// Basic operators.
		//

		__declspec(dllexport) bool operator==(const Matrix33& matrix);
		__declspec(dllexport) bool operator!=(const Matrix33& matrix);
		__declspec(dllexport) Matrix33 operator+(const Matrix33& matrix);
		__declspec(dllexport) Matrix33 operator-(const Matrix33& matrix);
		__declspec(dllexport) Matrix33 operator*(const Matrix33& matrix);
		__declspec(dllexport) Vector3 operator*(const Vector3& vector);
		__declspec(dllexport) Matrix33 operator*(float scalar);

		//
		// Set the matrix to specific useful values.
		//

		__declspec(dllexport) void toZero();
		__declspec(dllexport) void toIdentity();
		__declspec(dllexport) void toRotationX(float x);
		__declspec(dllexport) void toRotationY(float y);
		__declspec(dllexport) void toRotationZ(float z);
		__declspec(dllexport) void toRotation(float angle, float x, float y, float z);

		//
		// Other related helper functions.
		//

		__declspec(dllexport) Matrix33 transpose();

		__declspec(dllexport) Matrix33 invert();
		__declspec(dllexport) bool invert(Matrix33 * out_matrix);

		__declspec(dllexport) void fromEulerXYZ(float x, float y, float z);
		__declspec(dllexport) bool toEulerXYZ(float * x, float * y, float * z);
		__declspec(dllexport) bool toEulerZYX(float * x, float * y, float * z);

		__declspec(dllexport) bool reorthogonalize();

	};
	static_assert(sizeof(Matrix33) == 0x24, "TES3::Matrix33 failed size validation");

	struct BoundingBox {
		Vector3 minimum;
		Vector3 maximum;
	};
	static_assert(sizeof(BoundingBox) == 0x18, "TES3::BoundingBox failed size validation");

	struct Transform {
		TES3::Matrix33 rotation;
		TES3::Vector3 translation;
		float scale;
	};
	static_assert(sizeof(Transform) == 0x34, "TES3::Transform failed size validation");
}
