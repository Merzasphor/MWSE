#pragma once

namespace TES3 {
	struct DialogueFilter {
		void * variables; // 0x0
		unsigned char type; // 0x4
		unsigned char constantType; // 0x5
		short functionOrIndex; // 0x6
		unsigned char compareOperator; // 0x8
		char unknown_0x9;
		char unknown_0xA;
		char unknown_0xB;
		int compareValue; // 0xC
	};
	static_assert(sizeof(DialogueFilter) == 0x10, "TES3::DialogueFilter failed size validation");
}
