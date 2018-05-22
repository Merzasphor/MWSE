#pragma once

#include "NIAVObject.h"

namespace NI {
	struct Camera : AVObject {
		float worldToCamera[16];
		float viewDistance;
		float twoDivRmL;
		float twoDivTmB;
		TES3::Vector3 worldDirection;
		TES3::Vector3 worldUp;
		TES3::Vector3 worldRight;
		float viewFrustum[6];
		TES3::Vector4 port;
		Object * scene;
		TES3::TArray<void> unknown_0x12C; // Screen related?
		Object * renderer;
		TES3::TArray<void> unknown_0x148; // Multiple cameras?
		int unknown_0x160;
		TES3::Vector4 cullingPlanes[6];
		float unknown_0x1C4;
		float unknown_0x1C8;
		float unknown_0x1CC;
		float unknown_0x1D0;
		void * unknown_0x1D4;
		int unknown_0x1D8;
		float LODAdjust;
	};
	static_assert(sizeof(Camera) == 0x1E0, "NI::Camera failed size validation");
}
