#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"

namespace TES3 {
	namespace DialogueType {
		enum DialogueType {
			Regular,
			Voice,
			Greeting,
			Persuasion,
			Journal
		};
	}

	struct Dialogue : BaseObject {
		char * name; // 0x10
		unsigned char type; // 0x14
		Iterator<DialogueInfo> info; // 0x18
		int journalIndex; // 0x2C
	};
	static_assert(sizeof(Dialogue) == 0x30, "TES3::Dialogue failed size validation");
}
