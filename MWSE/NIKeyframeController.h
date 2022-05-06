#pragma once

#include "NITimeController.h"
#include "NIQuaternion.h"
#include "TES3Vectors.h"

namespace NI {
	struct AnimationKey {
		enum Type : unsigned int {
			NoInterp,
			Linear,
			Bezier,
			TCB,
			Euler,

			COUNT,
		};

		float timing; // 0x0
	};
	static_assert(sizeof(AnimationKey) == 0x4, "NI::AnimationKey failed size validation");
	static_assert(AnimationKey::Type::COUNT == 5, "NI::AnimationKey::Type failed enum count validation");

	struct FloatKey : AnimationKey {
		float value; // 0x4
	};
	static_assert(sizeof(FloatKey) == 0x8, "NI::FloatKey failed size validation");

	struct BezFloatKey : FloatKey {
		float inTangent; // 0x8
		float outTangent; // 0xC
	};
	static_assert(sizeof(BezFloatKey) == 0x10, "NI::BezFloatKey failed size validation");

	struct TCBFloatKey : FloatKey {
		float tension; // 0x8
		float continuity; // 0xC
		float bias; // 0x10
		float derivedA; // 0x14
		float derivedB; // 0x18
	};
	static_assert(sizeof(TCBFloatKey) == 0x1C, "NI::TCBFloatKey failed size validation");

	union AmbiguousFloatKeyPtr {
		FloatKey* asFloatKey;
		BezFloatKey* asBezFloatKey;
		TCBFloatKey* asTCBFloatKey;
	};
	static_assert(sizeof(AmbiguousFloatKeyPtr) == sizeof(void*), "NI::AmbiguousFloatKeyPtr failed size validation");

	struct RotKey : AnimationKey {
		Quaternion value; // 0x4
	};
	static_assert(sizeof(RotKey) == 0x14, "NI::RotKey failed size validation");

	struct BezRotKey : RotKey {
		Quaternion intermediate; // 0x14 // Intermediate value/angle used for interpolation.
	};
	static_assert(sizeof(BezRotKey) == 0x24, "NI::BezRotKey failed size validation");

	struct TCBRotKey : RotKey {
		float tension; // 0x14
		float continuity; // 0x18
		float bias; // 0x1C
		Quaternion intermediateA; // 0x20 // Intermediate value/angle used for interpolation.
		Quaternion intermediateB; // 0x30 // Intermediate value/angle used for interpolation.
	};
	static_assert(sizeof(TCBRotKey) == 0x40, "NI::TCBRotKey failed size validation");

	struct EulerRotKey : RotKey {
		enum Order : unsigned int {
			ORDER_XYZ,
			ORDER_XZY,
			ORDER_YZX,
			ORDER_YXZ,
			ORDER_ZXY,
			ORDER_ZYX,
			ORDER_XYX,
			ORDER_YZY,
			ORDER_ZXZ,

			ORDER_COUNT,
		};
		unsigned int numKeys[3]; // 0x14
		Type keyTypes[3]; // 0x20
		Order order; // 0x2C;
		AmbiguousFloatKeyPtr keys[3]; // 0x30
		unsigned int lastIndices[3]; // 0x38

		std::reference_wrapper<decltype(numKeys)> getNumKeys_lua();
		std::reference_wrapper<decltype(keyTypes)> getKeyTypes_lua();
		sol::table getKeys_lua(sol::this_state ts);
		std::reference_wrapper<decltype(lastIndices)> getLastIndices_lua();
	};
	static_assert(sizeof(EulerRotKey) == 0x48, "NI::EulerRotKey failed size validation");

	union AmbiguousRotKeyPtr {
		RotKey* asRotKey;
		BezRotKey* asBezRotKey;
		TCBRotKey* asTCBRotKey;
		EulerRotKey* asEulerRotKey;
	};
	static_assert(sizeof(AmbiguousRotKeyPtr) == sizeof(void*), "NI::AmbiguousRotKeyPtr failed size validation");

	struct PosKey : AnimationKey {
		TES3::Vector3 value; // 0x4
	};
	static_assert(sizeof(PosKey) == 0x10, "NI::PosKey failed size validation");

	struct BezPosKey : PosKey {
		TES3::Vector3 inTangent; // 0x10
		TES3::Vector3 outTangent; // 0x1C
		TES3::Vector3 intermediateA; // 0x28 // Intermediate value/angle used for interpolation.
		TES3::Vector3 intermediateB; // 0x34 // Intermediate value/angle used for interpolation.
	};
	static_assert(sizeof(BezPosKey) == 0x40, "NI::BezPosKey failed size validation");

	struct TCBPosKey : PosKey {
		float tension; // 0x10
		float continuity; // 0x14
		float bias; // 0x18
		TES3::Vector3 derivedA; // 0x1C // Intermediate value/angle derived from main parameters.
		TES3::Vector3 derivedB; // 0x28 // Intermediate value/angle derived from main parameters.
		TES3::Vector3 intermediateA; // 0x28 // Intermediate value/angle used for interpolation.
		TES3::Vector3 intermediateB; // 0x28 // Intermediate value/angle used for interpolation.
	};
	static_assert(sizeof(TCBPosKey) == 0x4C, "NI::TCBPosKey failed size validation");

	union AmbiguousPosKeyPtr {
		PosKey* asPosKey;
		BezPosKey* asBezPosKey;
		TCBPosKey* asTCBPosKey;
	};
	static_assert(sizeof(AmbiguousPosKeyPtr) == sizeof(void*), "NI::AmbiguousPosKeyPtr failed size validation");

	struct KeyframeData : Object {
		unsigned int rotationKeyCount; // 0x8
		AmbiguousRotKeyPtr rotationKeys; // 0xC
		AnimationKey::Type rotationType; // 0x10
		unsigned int positionKeyCount; // 0x14
		AmbiguousPosKeyPtr positionKeys; // 0x18
		AnimationKey::Type positionType; // 0x1C
		unsigned int scaleKeyCount; // 0x20
		AmbiguousFloatKeyPtr scaleKeys; // 0x24
		AnimationKey::Type scaleType; // 0x28

		sol::object getRotationKeys_lua(sol::this_state L);
		sol::object getPositionKeys_lua(sol::this_state L);
		sol::object getScaleKeys_lua(sol::this_state L);

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
