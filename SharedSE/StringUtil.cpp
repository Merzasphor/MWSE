#include "StringUtil.h"

namespace se::string {
	bool ciequal(char a, char b) {
		return std::tolower(a) == std::tolower(b);
	}

	bool equal(std::string_view a, std::string_view b) {
		if (a.length() != b.length()) {
			return false;
		}
		return std::equal(a.begin(), a.end(), b.begin(), b.end());
	}

	bool iequal(std::string_view a, std::string_view b) {
		if (a.length() != b.length()) {
			return false;
		}
		return std::equal(a.begin(), a.end(), b.begin(), b.end(), ciequal);
	}

	bool niequal(std::string_view a, std::string_view b, size_t maxCount) {
		if (a.size() < maxCount || b.size() < maxCount) return false;
		return std::equal(a.begin(), a.begin() + maxCount, b.begin(), b.begin() + maxCount, ciequal);
	}

	bool cicontains(const std::string_view& haystack, const std::string_view& needle) {
		if (needle.empty()) {
			return true;
		}

		if (haystack.size() < needle.size()) {
			return false;
		}

		return std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end(), ciequal) != haystack.end();
	}

	bool contains(const std::string_view& haystack, const std::string_view& needle) {
		if (needle.empty()) {
			return true;
		}

		if (haystack.size() < needle.size()) {
			return false;
		}

		return std::search(haystack.begin(), haystack.end(), needle.begin(), needle.end()) != haystack.end();
	}

	bool replace(std::string& str, const std::string_view from, const std::string_view to) {
		size_t start_pos = str.find(from);
		if (start_pos == std::string::npos)
			return false;
		str.replace(start_pos, from.length(), to);
		return true;
	}
}
