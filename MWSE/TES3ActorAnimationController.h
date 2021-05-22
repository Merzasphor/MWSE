#pragma once

#include "TES3Defines.h"

#include "TES3AnimationData.h"
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

	struct ActorAnimationController_VirtualTable {
		void(__thiscall* destructor)(ActorAnimationController*, int); // 0x0
		void(__thiscall* unknown_0x4)(ActorAnimationController*, float); // 0x4
		void(__thiscall* unknown_0x8)(ActorAnimationController*, int); // 0x8
		void(__thiscall* syncReferenceRotation)(ActorAnimationController*); // 0xC
		void(__thiscall* setProperties)(ActorAnimationController*, NI::Node*); // 0x10
		Matrix33* (__thiscall* getRotation)(ActorAnimationController*, Matrix33*); // 0x14
		void(__thiscall* unknown_0x18)(ActorAnimationController*, Vector3*); // 0x18
		void(__thiscall* unknown_0x1C)(ActorAnimationController*); // 0x1C
	};
	static_assert(sizeof(ActorAnimationController_VirtualTable) == 0x20, "TES3::ActorAnimationController_VirtualTable failed size validation");

	struct ActorAnimationController {
		ActorAnimationController_VirtualTable* vTable; // 0x0
		signed char useAnimationDelta; // 0x04
		char padding_0x5[3];
		char unknown_0x8;
		char padding_0x9[3];
		int unknown_0xC;
		float unknown_0x10;
		int unknown_0x14;
		float unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		float unknown_0x2C;
		int unknown_0x30;
		float unknown_0x34;
		MobileActor * mobileActor; // 0x38
		AnimationData * animationData; // 0x3C
		NI::Pointer<NI::AlphaProperty> alphaProperty; // 0x40
		NI::Pointer<NI::MaterialProperty> materialProperty; // 0x44
		NI::Pointer<NI::VertexColorProperty> vertexColorProperty; // 0x48
		Matrix33 unknown_0x4C;
		Matrix33 unknown_0x70;
		int unknown_0x94;
		char unknown_0x98;
		char unknown_0x99;
		char unknown_0x9A;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		int unknown_0xB4;
		int unknown_0xB8;
		int unknown_0xBC;
		int unknown_0xC0;
		int unknown_0xC4;
		int unknown_0xC8;
		int unknown_0xCC;
		int unknown_0xD0;

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

		float getWeaponAnimSpeed() const;
		void setWeaponAnimSpeed(float speed);
	};
	static_assert(sizeof(ActorAnimationController) == 0xD4, "TES3::ActorAnimationController failed size validation");
}
