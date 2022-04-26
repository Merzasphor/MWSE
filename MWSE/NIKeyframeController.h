#pragma once

#include "NITimeController.h"
#include "TES3Vectors.h"

namespace NI {
	enum AnimationKeyType : unsigned int {
		NoInterp,
		Linear,
		Bezier,
		TCB,
		Euler,

		COUNT,
	};
	static_assert(AnimationKeyType::COUNT == 5, "NI::AnimationKeyType failed enum count validation");

	struct AnimationKey {
		float timing; // 0x0
	};
	static_assert(sizeof(AnimationKey) == 0x4, "NI::AnimationKey failed size validation");

	struct FloatKey : AnimationKey {
		float value; // 0x8
	};
	static_assert(sizeof(FloatKey) == 0x8, "NI::FloatKey failed size validation");

	struct PosKey : AnimationKey {
		TES3::Vector3 value; // 0x4
	};
	static_assert(sizeof(PosKey) == 0x10, "NI::PosKey failed size validation");

	struct BezPosKey : PosKey {
		TES3::Vector3 inTangent; // 0x10
		TES3::Vector3 outTangent; // 0x1C
	};
	static_assert(sizeof(BezPosKey) == 0x28, "NI::BezPosKey failed size validation");

	struct TCBPosKey : PosKey {
		float tcb[3]; // 0x10

		std::reference_wrapper<float[3]> getTCB();
	};
	static_assert(sizeof(TCBPosKey) == 0x1C, "NI::TCBPosKey failed size validation");

	union AmbiguousPosKeyPtr {
		PosKey* asPosKey;
		BezPosKey* asBezPosKey;
		TCBPosKey* asTCBPosKey;
	};
	static_assert(sizeof(AmbiguousPosKeyPtr) == sizeof(void*), "NI::AmbiguousPosKeyPtr failed size validation");

	struct KeyframeData : Object {
		unsigned int rotationKeyCount; // 0x8
		AnimationKey* rotationKeys; // 0xC
		AnimationKeyType rotationType; // 0x10
		unsigned int positionKeyCount; // 0x14
		AmbiguousPosKeyPtr positionKeys; // 0x18
		AnimationKeyType positionType; // 0x1C
		unsigned int scaleKeyCount; // 0x20
		AnimationKey* scaleKeys; // 0x24
		AnimationKeyType scaleType; // 0x28

		sol::object getPositionKeys_lua(sol::this_state L) const;
	};
	static_assert(sizeof(KeyframeData) == 0x2C, "NI::KeyframeData failed size validation");

	struct KeyframeController : TimeController {
		unsigned int lastRotIndex; // 0x34
		unsigned int lastPosIndex; // 0x38
		unsigned int lastScaleIndex; // 0x3C
		Pointer<KeyframeData> keyframeData; // 0x40
	};
	static_assert(sizeof(KeyframeController) == 0x44, "NI::KeyframeController failed size validation");
}
