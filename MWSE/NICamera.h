#pragma once

#include "NIAVObject.h"

namespace NI {
	struct Camera : AVObject {
		float worldToCamera[16]; // 0x90
		float viewDistance; // 0xD0
		float twoDivRmL; // 0xD4
		float twoDivTmB; // 0xD8
		TES3::Vector3 worldDirection; // 0xDC
		TES3::Vector3 worldUp; // 0xE8
		TES3::Vector3 worldRight; // 0xF4
		float viewFrustum[6]; // 0x100
		TES3::Vector4 port; // 0x118
		Object * scene; // 0x128
		TES3::TArray<void> unknown_0x12C; // Screen related?
		Object * renderer; // 0x144
		TES3::TArray<void> unknown_0x148; // Multiple cameras?
		int unknown_0x160;
		TES3::Vector4 cullingPlanes[6]; // 0x164
		float unknown_0x1C4;
		float unknown_0x1C8;
		float unknown_0x1CC;
		float unknown_0x1D0;
		void * unknown_0x1D4;
		int unknown_0x1D8;
		float LODAdjust; // 0x1DC
	};
	static_assert(sizeof(Camera) == 0x1E0, "NI::Camera failed size validation");
}
