#pragma once

#include "NINode.h"

namespace NI {
	struct SwitchNode : Node {
		int switchIndex; // 0xB0
		int unknown_0xB4;
		int unknown_0xB8;
		int unknown_0xBC;
		int unknown_0xC0;
		int unknown_0xC4;
		int unknown_0xC8;
		int unknown_0xCC;
		int unknown_0xD0;
		int unknown_0xD4;
	};
	static_assert(sizeof(SwitchNode) == 0xD8, "NI::SwitchNode failed size validation");
}
