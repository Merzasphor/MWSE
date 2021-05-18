#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

#include "NIExtraData.h"
#include "NIProperty.h"

namespace TES3 {
	struct KeyframeDefinition {
		const char* name; // 0x0
		NI::Sequence* sequences[3];
		AnimationGroup* animationGroup; // 0x10
		unsigned short groupCount; // 0x14
		unsigned short refCount; // 0x16
	};
	static_assert(sizeof(KeyframeDefinition) == 0x18, "TES3::KeyframeDefinition failed size validation");

	struct ActorAnimationData_VirtualTable {
		void(__thiscall* destructor)(ActorAnimationData*, int); // 0x0
		void(__thiscall* unknown_0x4)(ActorAnimationData*, float); // 0x4
		void(__thiscall* unknown_0x8)(ActorAnimationData*, int); // 0x8
		void(__thiscall* syncReferenceRotation)(ActorAnimationData*); // 0xC
		void(__thiscall* setProperties)(ActorAnimationData*, NI::Node*); // 0x10
		Matrix33* (__thiscall* getRotation)(ActorAnimationData*, Matrix33*); // 0x14
		void(__thiscall* unknown_0x18)(ActorAnimationData*, Vector3*); // 0x18
		void(__thiscall* unknown_0x1C)(ActorAnimationData*); // 0x1C
	};
	static_assert(sizeof(ActorAnimationData_VirtualTable) == 0x20, "TES3::ActorAnimationData_VirtualTable failed size validation");

	struct ActorAnimationData {
		struct Layer {
			unsigned char animGroupID;
			int playbackFlags;
			float time_0x8;
			int loopCount;
		};
		static_assert(sizeof(ActorAnimationData::Layer) == 0x10, "TES3::ActorAnimationData::Layer failed size validation");

		ActorAnimationData_VirtualTable* vTable; // 0x0
		unsigned char useAnimationDelta; // 0x04
		char padding_0x5[3];
		char animGroup_unknown; // 0x08
		char padding_0x9[3];
		int casting_related_state; // 0x0C
		float unknown_0x10;
		float remainingBlockAnimTime; // 0x14
		float beginTime; // 0x18
		int unknown_0x1C;
		float endTime; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		float attackSwing; // 0x2C
		int unknown_0x30;
		float speedMultiplier; // 0x34
		MobileActor * mobileActor; // 0x38
		AnimationData * animationAttachment; // 0x3C
		NI::Pointer<NI::AlphaProperty> alphaProperty; // 0x40
		NI::Pointer<NI::MaterialProperty> materialProperty; // 0x44
		NI::Pointer<NI::VertexColorProperty> vertexColorProperty; // 0x48
		Matrix33 localRotation;
		Matrix33 unknown_0x70;
		int unknown_0x94;
		unsigned char animGroupMovement; // 0x98
		unsigned char animGroupIdle; // 0x99
		unsigned char animGroupIdle2; // 0x9A
		unsigned char patchedOverrideState; // 0x9B
		int shouldJump; // 0x9C
		int unknown_0xA0;
		Layer layerBase; // 0xA4
		Layer layerUpperBody; // 0xB4
		Layer layerLeftArm; // 0xC4

		//
		// Other related this-call functions.
		//

		float calculateMovementSpeed();

		float getOpacity();
		void setOpacity(float value);

		//
		// Custom functions.
		//

		// Fixes any transparency values.
		void updateOpacity();

	};
	static_assert(sizeof(ActorAnimationData) == 0xD4, "TES3::ActorAnimationData failed size validation");
}
