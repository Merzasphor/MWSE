#pragma once

#include "TES3Lockpick.h"

namespace TES3 {
	// Probes are effectively just lockpicks.
	struct Probe : Lockpick {

	};
	static_assert(sizeof(Probe) == 0xB8, "TES3::Probe failed size validation");
}
