#pragma once

#include "NINode.h"

namespace NI {
	struct SwitchNode : Node {
		int switchIndex; // 0xB0
		float fSavedTime;
		int updateIndex;
		TArray<unsigned int*> childRevisionIDs;
		bool bUpdateControllers;
	};
	static_assert(sizeof(SwitchNode) == 0xD8, "NI::SwitchNode failed size validation");
}
