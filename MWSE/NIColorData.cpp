#include "NIColorData.h"

namespace NI {
	nonstd::span<ColorKey*> ColorData::getKeys() const {
		auto addr = reinterpret_cast<DWORD*>(0x7DF724)[(unsigned int)keyType];
		return nonstd::span(keys, keyCount);
	};
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ColorData)
