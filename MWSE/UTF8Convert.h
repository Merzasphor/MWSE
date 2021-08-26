#pragma once

#include <string>

namespace mwse {
	std::string iconv(int codepage, const char* utf8string);
}