#pragma once

#include "TES3CriticalSection.h"

#include <d3d.h>

namespace TES3 {
	struct BinkVideo {
		int width; // 0x0
		int height; // 0x4
		// ...
	};

	struct CutscenePlayer {
		struct VirtualTable {
			int dtor; // 0x0
			int decodeFrame; // 0x4
			int setupAudio; // 0x8
			int open; // 0xC
			int pause; // 0x10
			int close; // 0x14
			int unknown_0x18; // Always returns 0?
			int unknown_0x1C; // Sets field at 0x88;
			int unknown_0x20; // Sets field at 0x55;
		};
		struct MovieTextures {
			struct VideoBuffer {

			};
			int unknown_0x0;
			HANDLE unknown_0x4; // 2048x1024 texture handle.
			HANDLE unknown_0x8; // 512x128 texture handle.
			HANDLE unknown_0xC; // 512x64 texture handle.
			HANDLE unknown_0x10; // 512x32 texture handle.
			HANDLE unknown_0x14; // 128x256 texture handle.
			HANDLE unknown_0x18; // 128x128 texture handle.
			HANDLE unknown_0x1C; // 128x64 texture handle.
			HANDLE unknown_0x20; // 128x32 texture handle.
			void* d3dDevice; // 0x24
			VideoBuffer* videoBuffer; // 0x28
		};
		VirtualTable* vTable; // 0x0
		CriticalSection unknown_0x4;
		CriticalSection unknown_0x28;
		int state; // 0x4C
		BinkVideo* binkHandle; // 0x50
		char unknown_0x54;
		char unknown_0x55;
		char unknown_0x56;
		char unknown_0x57;
		char unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		char unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		float width; // 0x94
		float height; // 0x98
		int unknown_0x9C;
		int unknown_0xA0;
	};
	static_assert(sizeof(CutscenePlayer) == 0xA4, "TES3::CutscenePlayer failed size validation");
	static_assert(sizeof(CutscenePlayer::VirtualTable) == 0x24, "TES3::CutscenePlayer::VirtualTable failed size validation");
	static_assert(sizeof(CutscenePlayer::MovieTextures) == 0x2C, "TES3::CutscenePlayer::MovieTextures failed size validation");
}
