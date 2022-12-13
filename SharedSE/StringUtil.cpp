#include "StringUtil.h"

namespace se::string {
	bool ciequal(char a, char b) {
		return tolower(a) == tolower(b);
	}

	bool equal(std::string_view a, std::string_view b) {
		return std::equal(a.begin(), a.end(), b.begin(), b.end());
	}

	bool iequal(std::string_view a, std::string_view b) {
		return std::equal(a.begin(), a.end(), b.begin(), b.end(), ciequal);
	}

	bool niequal(std::string_view a, std::string_view b, size_t maxCount) {
		if (a.size() < maxCount || b.size() < maxCount) return false;
		return std::equal(a.begin(), a.begin() + maxCount, b.begin(), b.begin() + maxCount, ciequal);
	}

	bool replace(std::string& str, const std::string_view from, const std::string_view to) {
		size_t start_pos = str.find(from);
		if (start_pos == std::string::npos)
			return false;
		str.replace(start_pos, from.length(), to);
		return true;
	}
}
