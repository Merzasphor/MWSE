#pragma once

#include "NITimeController.h"
#include "NIKeyframeController.h"
#include "NIExtraData.h"

#include "TES3Collections.h"
#include "TES3HashMap.h"
#include "TES3Vectors.h"

namespace NI {
	struct Sequence {
		char* name; // 0x0
		char* unknown_0x4;
		int unknown_0x8;
		TES3::TArray<char> boneNames; // 0xC
		TES3::TArray<KeyframeController> controllers; // 0x24
		Pointer<TextKeyExtraData> textKeys;
		unsigned int currentBoneControllerIndex; // 0x40
		KeyframeManager* manager; // 0x44
		int unknown_0x48;
		int unknown_0x4C;
		Sequence* unknown_0x50;
		int unknown_0x54;
		char unknown_0x58;
		char unknown_0x59;
		int unknown_0x5C;
		TES3::Matrix33 unknown_0x60;
		TES3::Vector3 unknown_0x84;
		TES3::Matrix33 unknown_0x90;
		TES3::Vector3 unknown_0xB4;
	};
	static_assert(sizeof(Sequence) == 0xC0, "NI::Sequence failed size validation");

	struct KeyframeManager : TimeController {
		TES3::HashMap<int, Sequence*> sequences; // 0x34
		bool cumulative; // 0x44
		TES3::Matrix33 globalScaleRotation; // 0x48
		TES3::Vector3 globalTranslation; // 0x6C
	};
	static_assert(sizeof(KeyframeManager) == 0x78, "NI::KeyframeManager failed size validation");
}
