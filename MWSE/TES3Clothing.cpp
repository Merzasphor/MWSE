#include "TES3Clothing.h"

#include "TES3Util.h"

namespace TES3 {
	void Clothing::setIconPath(const char* path) {
		if (strnlen_s(path, 32) >= 32) {
			throw std::invalid_argument("Path must not be 32 or more characters.");
		}
		mwse::tes3::setDataString(&icon, path);
	}

	std::reference_wrapper<WearablePart[7]> Clothing::getParts() {
		return std::ref(parts);
	}
}
