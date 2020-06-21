#include "TES3Lockpick.h"

#include "TES3Util.h"

namespace TES3 {
	void Lockpick::setIconPath(const char* path) {
		if (strlen(path) >= 32) {
			throw std::invalid_argument("Path cannot be 32 or more characters.");
		}
		strncpy_s(icon, path, 32);
	}
}
