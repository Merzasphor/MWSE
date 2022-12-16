#pragma once

#include "CSDefines.h"

#include "NIIteratedList.h"
#include "LinkedObjectsList.h"

namespace se::cs {
	struct RecordHandler {
		int activeModCount; // 0x0
		int unknown_0x4;
		LinkedObjectList<Object>* allObjects; // 0x8
		int unknown_0xC;
		ModelLoader* modelLoader; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		NI::IteratedList<Script*>* scripts; // 0x28
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		NI::IteratedList<Dialogue*>* dialogues; // 0x38
		int unknown_0x3C[10975];
		GameFile* activeGameFiles[256]; // 0xABB8
		// ...

		size_t getCellCount() const;
		Cell* getCellByIndex(size_t index) const;
	};
	static_assert(offsetof(RecordHandler, activeGameFiles) == 0xABB8, "TES3::RecordHandler failed offset validation");
}
