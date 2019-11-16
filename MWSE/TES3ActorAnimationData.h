#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

#include "NIPointer.h"
#include "NIProperty.h"

namespace TES3 {
	struct ActorAnimationDataVirtualTable {

	};

	struct ActorAnimationData {
		ActorAnimationDataVirtualTable * vTable; // 0x0
		signed char useAnimationDelta; // 0x04
		char padding_0x5[3];
		char unknown_0x8;
		char padding_0x9[3];
		int unknown_0xC;
		float unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		float unknown_0x34;
		MobileActor * mobileActor; // 0x38
		int unknown_0x3C;
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
	};
	static_assert(sizeof(ActorAnimationData) == 0xD4, "TES3::ActorAnimationData failed size validation");
}
