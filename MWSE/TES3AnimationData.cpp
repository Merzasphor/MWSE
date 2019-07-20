#include "TES3AnimationData.h"

namespace TES3 {
	const auto TES3_MeshData_playAnimationGroupForIndex = reinterpret_cast<void(__thiscall*)(AnimationData*, int, int, int, int)>(0x470AE0);
	void AnimationData::playAnimationGroupForIndex(int animationGroup, int triIndex, int startFlag, int loopCount) {
		TES3_MeshData_playAnimationGroupForIndex(this, animationGroup, triIndex, startFlag, loopCount);
	}

	void AnimationData::playAnimationGroup(int animationGroup, int startFlag, int loopCount) {
		playAnimationGroupForIndex(animationGroup, 0, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 1, startFlag, loopCount);
		playAnimationGroupForIndex(animationGroup, 2, startFlag, loopCount);
	}
}
