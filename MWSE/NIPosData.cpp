#include "NIPosData.h"

namespace NI {
	const auto NI_PosData_getKeyDataSize = reinterpret_cast<unsigned int(__cdecl*)(AnimationKey::Type)>(0x7239F0);
	unsigned int PosData::getKeyDataSize() const {
		return NI_PosData_getKeyDataSize(keyType);
	}
}
