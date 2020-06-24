#pragma once

#include "NIObject.h"

#include "TES3Defines.h"

namespace NI {
	struct ExtraData : Object {
		int unknown_0x8;
		char* name; // 0xC
		ExtraData* next; // 0x10
	};
	static_assert(sizeof(ExtraData) == 0x14, "NI::TextKey failed size validation");

	struct StringExtraData : ExtraData {
		char* string; // 0x14
	};
	static_assert(sizeof(StringExtraData) == 0x18, "NI::TextKey failed size validation");

	struct Tes3ExtraData : ExtraData {
		TES3::Reference* reference; // 0x14
	};
	static_assert(sizeof(Tes3ExtraData) == 0x18, "NI::Tes3ExtraData failed size validation");

	struct TextKey {
		float time; // 0x0
		char* text; // 0x4
	};
	static_assert(sizeof(TextKey) == 0x8, "NI::TextKey failed size validation");

	struct TextKeyExtraData : ExtraData {
		unsigned int keyCount; // 0x14
		TextKey* key; // 0x18
	};
	static_assert(sizeof(TextKeyExtraData) == 0x1C, "NI::TextKeyExtraData failed size validation");
}
