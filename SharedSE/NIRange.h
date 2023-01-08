#pragma once

namespace NI {
	template <typename T>
	struct Range {
		T min;
		T max;
	};
	static_assert(sizeof(Range<int>) == 0x8, "TES3::Range<int> failed size validation");
}
