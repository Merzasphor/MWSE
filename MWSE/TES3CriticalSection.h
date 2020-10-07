#pragma once

namespace TES3 {
	struct CriticalSection : _RTL_CRITICAL_SECTION {
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
	};
	static_assert(sizeof(CriticalSection) == 0x24, "TES3::CriticalSection failed size validation");
}
