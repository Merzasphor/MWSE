#pragma once

#include "NIObjectNET.h"

namespace NI {
	struct Property_vTable : Object_vTable {
		int(__thiscall * getType)(Property*); // 0x2C
		void(__thiscall * update)(Property*, float); // 0x30
	};
	static_assert(sizeof(Property_vTable) == 0x34, "NI::Property's vtable failed size validation");

	struct Property : ObjectNET {
		unsigned short flags;

		//
		// vTable wrappers.
		//

		__declspec(dllexport) __inline int getType() {
			return vTable.asProperty->getType(this);
		}

	};
	static_assert(sizeof(Property) == 0x18, "NI::Property failed size validation");
}
