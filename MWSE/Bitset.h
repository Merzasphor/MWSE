#pragma once

namespace mwse {
	template <typename T>
	class bitset {
	public:
		bitset() {
			value = 0;
		}

		const bitset<T>& operator=(const T& b) {
			value = b;
			return *this;
		}

		operator T() const {
			return value;
		}

		void operator&=(T v) {
			value &= v;
		}
		
		void operator|=(T v) {
			value |= v;
		}

		void clear() {
			value = 0;
		}

		const bool test(size_t position) {
			return value & (1 << position);
		}

		void set(size_t position, bool set) {
			if (set) {
				value |= (1 << position);
			}
			else {
				value &= ~(1 << position);
			}
		}

		const bool testMask(T mask) {
			return (value & mask) == mask;
		}

		void setMask(T mask, bool set) {
			if (set) {
				value |= mask;
			}
			else {
				value &= ~mask;
			}
		}

	protected:
		T value;
	};

	typedef bitset<unsigned char> bitset8;
	typedef bitset<unsigned short> bitset16;
	typedef bitset<unsigned long> bitset32;

	static_assert(sizeof(bitset8) == 0x1, "mwse::bitset8 failed size validation");
	static_assert(sizeof(bitset16) == 0x2, "mwse::bitset16 failed size validation");
	static_assert(sizeof(bitset32) == 0x4, "mwse::bitset32 failed size validation");
}
