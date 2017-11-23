#include "RngUtil.h"

#include <ctime>

namespace mwse
{
	namespace rng
	{
		static std::mt19937 mwse_rng_mt19937(std::time(0));

		mwLong_t getRandomLong(mwLong_t min, mwLong_t max) {
			if (min > max) {
				return 0;
			}
			else if (min == max) {
				return min;
			}

			std::uniform_int_distribution<mwLong_t> dist(min, max);
			return dist(mwse_rng_mt19937);
		}

		mwFloat_t getRandomFloat(mwFloat_t min, mwFloat_t max) {
			if (min > max) {
				return 0.0f;
			}
			else if (min == max) {
				return min;
			}

			std::uniform_real_distribution<mwFloat_t> dist(min, max);
			return dist(mwse_rng_mt19937);
		}
	}
}
