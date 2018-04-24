#pragma once

#include "TES3Object.h"

namespace TES3 {
	namespace UI {
		struct String {
			char tag;
			char * cString;
			size_t length;
			size_t storageSize;
		};
		static_assert(sizeof(String) == 0x10, "TES3::UI::String failed size validation");
	}
}
