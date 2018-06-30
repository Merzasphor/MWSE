#pragma once

#include "TES3Weather.h"

namespace TES3 {
	struct WeatherClear : Weather {
	};
	static_assert(sizeof(WeatherClear) == 0x318, "TES3::WeatherClear failed size validation");
}
