#pragma once

namespace se::math {
	constexpr auto M_PI = 3.14159265358979323846; // pi
	constexpr auto M_PIf = float(M_PI);

	constexpr auto M_2PI = 2.0 * M_PI; // 2pi
	constexpr auto M_2PIf = float(M_2PI);

	constexpr double M_PI_2 = M_PI / 2; // pi/2
	constexpr double M_PI_2f = float(M_PI_2);

	template <typename T>
	constexpr T radiansToDegrees(T radians) {
		if constexpr (std::is_arithmetic_v<T>) {
			return T(radians * 180.0 / M_PI);
		}
	}

	template <typename T>
	constexpr T degreesToRadians(T degrees) {
		if constexpr (std::is_arithmetic_v<T>) {
			return T(degrees * M_PI / 180.0);
		}
	}

	void standardizeAngleRadians(float& value);
}
