#pragma once

#include "CSAnimatedObject.h"

namespace se::cs {
	struct Light : AnimatedObject {
		struct Substruct5C {
			int unknown_0x0;
			int unknown_0x4;
			int unknown_0x8;
			int unknown_0xC;
			int unknown_0x10;
			int unknown_0x14;
		};
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		Substruct5C unknown_0x5C;
		int unknown_0x74;

		void updateLightingData(NI::Light* light, Cell* cell, bool flag = false);
	};
	static_assert(sizeof(Light) == 0x78, "Light failed size validation");
}
