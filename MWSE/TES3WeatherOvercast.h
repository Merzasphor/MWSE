#pragma once

#include "TES3Weather.h"

namespace TES3 {
	struct WeatherOvercast : Weather {
	};
	static_assert(sizeof(WeatherOvercast) == 0x318, "TES3::WeatherOvercast failed size validation");
}
