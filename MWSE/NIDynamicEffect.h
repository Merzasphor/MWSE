#pragma once

#include "NIAVObject.h"

namespace NI {
	struct DynamicEffect : AVObject {
		bool enabled; // 0x90
		int index; // 0x94
		int unknown_0x98;
		unsigned int revisionId; // 0x9C
		NodeLinkedList affectedNodes; // 0xA0
	};
	static_assert(sizeof(DynamicEffect) == 0xA8, "NI::DynamicEffect failed size validation");
}
