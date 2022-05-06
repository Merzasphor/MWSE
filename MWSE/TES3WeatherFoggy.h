#pragma once

#include "TES3Weather.h"

namespace TES3 {
	struct WeatherFoggy : Weather {
		WeatherFoggy() = delete;
		~WeatherFoggy() = delete;
	};
	static_assert(sizeof(WeatherFoggy) == 0x318, "TES3::WeatherFoggy failed size validation");
}
