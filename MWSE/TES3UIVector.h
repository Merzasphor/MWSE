#pragma once

#include "TES3Defines.h"

namespace TES3 {
	namespace UI {
		struct Vector {
			char tag;
			void * begin;
			void * end;
			void * storageEnd;
		};
		static_assert(sizeof(Vector) == 0x10, "TES3::UI::Vector failed size validation");
	}
}
