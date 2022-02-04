#pragma once

template <class T>
class MemAccess {
public:
	static inline T Get(uintptr_t address) {
		return *reinterpret_cast<T*>(address);
	}

	static inline void Set(uintptr_t address, T value) {
		*reinterpret_cast<T*>(address) = value;
	}
};
