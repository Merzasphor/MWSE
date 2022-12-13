#pragma once

namespace se::string {

	//
	// Comparison helpers.
	//

	// Returns true if a == b, case insensitive.
	bool ciequal(char a, char b);

	// Returns true if a == b, case sensitive.
	bool equal(std::string_view a, std::string_view b);

	// Returns true if a == b, case insensitive.
	bool iequal(std::string_view a, std::string_view b);

	// Returns true if a == b, case insensitive, only compares maxCount characters.
	bool niequal(std::string_view a, std::string_view b, size_t maxCount);

	bool replace(std::string& str, const std::string_view from, const std::string_view to);

	//
	// Other string utility functions.
	//

	inline void ltrim(std::string& s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) { return !std::isspace(ch); }));
	}

	inline void rtrim(std::string& s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) { return !std::isspace(ch); }).base(), s.end());
	}

	inline void trim(std::string& s) {
		ltrim(s);
		rtrim(s);
	}

	inline std::string ltrim_copy(std::string s) {
		ltrim(s);
		return s;
	}

	inline std::string rtrim_copy(std::string s) {
		rtrim(s);
		return s;
	}

	inline std::string trim_copy(std::string s) {
		trim(s);
		return s;
	}

	inline void to_lower(std::string& s) {
		std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });
	}
}
