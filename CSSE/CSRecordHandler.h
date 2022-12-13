#pragma once

#include "CSDefines.h"

#include "NIIteratedList.h"

namespace se::cs {
	struct RecordHandler {
		int activeModCount; // 0x0
		int unknown_0x4[13];
		NI::IteratedList<Dialogue*>* dialogues; // 0x38
		int unknown_0x3C[10975];
		GameFile* activeGameFiles[256]; // 0xABB8
		// ...
	};
	static_assert(offsetof(RecordHandler, activeGameFiles) == 0xABB8, "TES3::RecordHandler failed offset validation");
}
