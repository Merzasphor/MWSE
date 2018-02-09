#include "RngUtil.h"

#include <ctime>

namespace mwse
{
	namespace rng
	{
		static std::mt19937 mwse_rng_mt19937(std::time(0));

		mwLong getRandomLong(mwLong min, mwLong max) {
			if (min > max) {
				return 0;
			}
			else if (min == max) {
				return min;
			}

			std::uniform_int_distribution<mwLong> dist(min, max);
			return dist(mwse_rng_mt19937);
		}

		mwFloat getRandomFloat(mwFloat min, mwFloat max) {
			if (min > max) {
				return 0.0f;
			}
			else if (min == max) {
				return min;
			}

			std::uniform_real_distribution<mwFloat> dist(min, max);
			return dist(mwse_rng_mt19937);
		}
	}
}
