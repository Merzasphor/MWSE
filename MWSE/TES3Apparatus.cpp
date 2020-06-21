#include "TES3Apparatus.h"

namespace TES3 {
	void Apparatus::setIconPath(const char* path) {
		if (strlen(path) >= 32) {
			throw std::invalid_argument("Path cannot be 32 or more characters.");
		}
		strncpy_s(texture, path, 32);
	}
}
