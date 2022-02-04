#pragma once

namespace mwse {
	class Flags {
	public:
		template<class T> static inline void setFlags(T& value) {
			positive = (value >= 0);
			zero = (value == 0);
		}

		static inline bool getPositive(void) {
			return positive;
		}

		static inline bool getZero(void) {
			return zero;
		}
	private:
		static bool positive;
		static bool zero;
	};
}