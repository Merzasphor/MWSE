#pragma once

#include "NIAVObject.h"
#include "TES3Collections.h"

namespace NI {
	struct Node : AVObject {
		TES3::TArray<AVObject> children; // 0x90
		void * effectList; // 0xA8 // Maybe?
		void * bound; // 0xAC // Maybe?
	};
	static_assert(sizeof(Node) == 0xB0, "NI::Node failed size validation");

	struct Node_vTable : AVObject_vTable {
		void * attachChild; // 0x94
		void * detachChild; // 0x98
		void * detachChildAt; // 0x9C
		void * setChildAt; // 0xA0
		void * updateBoundUpwards; // 0xA4
	};
	static_assert(sizeof(Node_vTable) == 0xA8, "NI::Node's vtable failed size validation");
}
