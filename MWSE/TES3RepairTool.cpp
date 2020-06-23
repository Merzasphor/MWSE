#include "TES3RepairTool.h"

namespace TES3 {
	void RepairTool::setIconPath(const char* path) {
		if (strlen(path) >= 32) {
			throw std::invalid_argument("Path cannot be 32 or more characters.");
		}
		strncpy_s(icon, path, 32);
	}
}
