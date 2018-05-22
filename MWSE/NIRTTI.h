#pragma once

namespace NI {
	struct RTTI {
		const char* name; // 0x0
		RTTI * baseRTTI; // 0x4
	};
	static_assert(sizeof(RTTI) == 0x8, "NI::RTTI failed size validation");
}
