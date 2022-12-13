#pragma once

#include "CSBaseObject.h"

namespace se::cs {
	struct DialogueInfo : BaseObject {
		struct LoadLinkNode {
			const char* name; // 0x0
			const char* previous; // 0x4
			const char* next; // 0x8
		};
		LoadLinkNode* loadLinkNodes; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		unsigned char npcRank; // 0x1C
		unsigned char npcSex; // 0x1D
		unsigned char pcRank; // 0x1E
		unsigned char unknown_0x1F;
		char unknown_0x20[60];
		int unknown_0x5C[18];
	};
	static_assert(sizeof(DialogueInfo) == 0xA4, "TES3::DialogueInfo failed size validation");
}
