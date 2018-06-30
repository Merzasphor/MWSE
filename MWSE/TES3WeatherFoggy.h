#pragma once

#include "TES3Weather.h"

namespace TES3 {
	struct WeatherFoggy : Weather {
	};
	static_assert(sizeof(WeatherFoggy) == 0x318, "TES3::WeatherFoggy failed size validation");
}
