#include "NIColorData.h"

namespace NI {
	std::span<ColorKey*> ColorData::getKeys() const {
		auto addr = reinterpret_cast<DWORD*>(0x7DF724)[(unsigned int)keyType];
		return std::span(keys, keyCount);
	};
}
