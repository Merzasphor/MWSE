#pragma once

#include "NIStream.h"

namespace TES3 {
	struct Stream : NI::Stream {
		int unknown_0xAC;
	};
	static_assert(sizeof(Stream) == 0xB0, "TES3::Stream failed size validation");
}
