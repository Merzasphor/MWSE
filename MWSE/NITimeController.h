#pragma once

#include "NIDefines.h"

#include "NIObject.h"
#include "NIPointer.h"

#include "Bitset.h"

namespace NI {
	struct TimeController : Object {
		mwse::bitset16 deprecatedFlags; // 0x8
		float frequency; // 0xC
		float phase; // 0x10
		float lowKeyFrame; // 0x14
		float highKeyFrame; // 0x18
		float startTime; // 0x1C
		float lastTime; // 0x20
		int unknown_0x24;
		ObjectNET * target; // 0x28
		Pointer<TimeController> nextController; // 0x2C
		bool unknown_0x30; // Force update? Compute scaled time?
	};
	static_assert(sizeof(TimeController) == 0x34, "NI::TimeController failed size validation");
}
