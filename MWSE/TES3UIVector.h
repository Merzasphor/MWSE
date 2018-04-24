#pragma once

#include "TES3Object.h"

namespace TES3 {
	namespace UI {
		struct Vector {
			char tag;
			void * head;
			void * tail;
			void * storageEnd;
		};
		static_assert(sizeof(Vector) == 0x10, "TES3::UI::Vector failed size validation");
	}
}
