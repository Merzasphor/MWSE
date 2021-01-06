#pragma once

#include "TES3Defines.h"
#include "TES3Vectors.h"

#include "NIDefines.h"

namespace TES3 {
	struct AnimationData {
		NI::Node * actorNode; // 0x0
		NI::Node * MRT; // 0x4
		TES3::Vector3 unknown_0x8;
		NI::Node * childNodeBip01Spine1; // 0x14
		NI::Node * childNodeBip01Spine2; // 0x18
		int unknown_0x1C;
		NI::Node * childNodeBip01Head; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		unsigned char currentAnimGroup[3]; // 0x38
		int unknown_0x3C[3];
		int unknown_0x48[3];
		unsigned int unknown_0x54; // Flags?
		float timing[3]; // 0x58
		int unknown_0x64;
		AnimationGroup * animationGroups[149]; // 0x68
		int unknown_0x2BC;
		NI::TimeController * timeController; // 0x2C0 // NiKeyframeController
		int unknown_0x2C4[9];
		int unknown_0x2E8;
		float lipsyncLevel; // 0x2EC
		int unknown_0x2F0;
		int unknown_0x2F4;
		int unknown_0x2F8;
		int unknown_0x2FC;
		int unknown_0x300;
		int unknown_0x304;
		int unknown_0x308;
		int unknown_0x30C;
		int unknown_0x310;
		signed char animGroupStates[148]; // 0x314
		short unknown_0x3A8;
		short unknown_0x3AA;
		int unknown_0x3AC;
		int unknown_0x3B0;
		int unknown_0x3B4;
		int unknown_0x3B8;
		int unknown_0x3BC;
		int unknown_0x3C0;
		int unknown_0x3C4;
		int unknown_0x3C8;
		int unknown_0x3CC;
		int unknown_0x3D0;
		int unknown_0x3D4;
		int unknown_0x3D8;
		int unknown_0x3DC;
		int unknown_0x3E0;
		int unknown_0x3E4;
		int unknown_0x3E8;
		int unknown_0x3EC;
		int unknown_0x3F0;
		int unknown_0x3F4;
		int unknown_0x3F8;
		int unknown_0x3FC;
		int unknown_0x400;
		int unknown_0x404;
		int unknown_0x408;
		int unknown_0x40C;
		int unknown_0x410;
		int unknown_0x414;
		int unknown_0x418;
		int unknown_0x41C;
		int unknown_0x420;
		int unknown_0x424;
		int unknown_0x428;
		int unknown_0x42C;
		int unknown_0x430;
		int unknown_0x434;
		int unknown_0x438;
		int unknown_0x43C;
		int unknown_0x440;
		int unknown_0x444;
		int unknown_0x448;
		int unknown_0x44C;
		int unknown_0x450;
		int unknown_0x454;
		int unknown_0x458;
		int unknown_0x45C;
		int unknown_0x460;
		int unknown_0x464;
		int unknown_0x468;
		int unknown_0x46C;
		int unknown_0x470;
		int unknown_0x474;
		int unknown_0x478;
		int unknown_0x47C;
		int unknown_0x480;
		int unknown_0x484;
		int unknown_0x488;
		int unknown_0x48C;
		int unknown_0x490;
		int unknown_0x494;
		int unknown_0x498;
		int unknown_0x49C;
		int unknown_0x4A0;
		int unknown_0x4A4;
		int unknown_0x4A8;
		int unknown_0x4AC;
		int unknown_0x4B0;
		int unknown_0x4B4;
		int unknown_0x4B8;
		int unknown_0x4BC;
		int unknown_0x4C0;
		int unknown_0x4C4;
		int unknown_0x4C8;
		int unknown_0x4CC;
		int unknown_0x4D0;
		int unknown_0x4D4;
		float playbackSpeed; // 0x4D8
		float weaponSpeed; // 0x4DC
		int unknown_0x4E0;
		int unknown_0x4E4;
		int unknown_0x4E8;
		int unknown_0x4EC;
		int unknown_0x4F0;
		int unknown_0x4F4;
		int unknown_0x4F8;
		int unknown_0x4FC;
		int unknown_0x500;
		int unknown_0x504;
		int unknown_0x508;
		int unknown_0x50C;
		int unknown_0x510;
		int unknown_0x514;
		int unknown_0x518;
		int unknown_0x51C;
		int unknown_0x520;
		int unknown_0x524;
		int unknown_0x528;
		int unknown_0x52C;
		int unknown_0x530;
		int unknown_0x534;
		int unknown_0x538;
		int unknown_0x53C;
		int unknown_0x540;
		int unknown_0x544;
		int unknown_0x548;
		int unknown_0x54C;
		int unknown_0x550;
		int unknown_0x554;
		int unknown_0x558;
		int unknown_0x55C;
		int unknown_0x560;
		int unknown_0x564;
		int unknown_0x568;
		int unknown_0x56C;
		int unknown_0x570;
		int unknown_0x574;
		int unknown_0x578;
		int unknown_0x57C;
		int unknown_0x580;
		void * unknown_0x584[149];
		int unknown_0x7D8;
		bool unknown_0x7DC;
		int unknown_0x7E0;

		//
		// Other related this-call functions.
		//

		void playAnimationGroupForIndex(int animationGroup, int triIndex, int startFlag = 0, int loopCount = -1);
		void setHeadNode(NI::Node* head);

		//
		// Custom functions.
		//

		Reference* getReference() const;

		void playAnimationGroup(int animationGroup, int startFlag = 0, int loopCount = -1);

	};
	static_assert(sizeof(AnimationData) == 0x7E4, "TES3::AnimationAttachment failed size validation");
}
