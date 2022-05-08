#pragma once

#include "TES3Defines.h"

namespace TES3 {
	namespace UI {
		template <typename T>
		struct Vector {
			char tag;
			T * begin;
			T * end;
			T * storageEnd;

			Vector() = delete;
			~Vector() = delete;
		};
		static_assert(sizeof(Vector<void>) == 0x10, "TES3::UI::Vector failed size validation");
	}
}
