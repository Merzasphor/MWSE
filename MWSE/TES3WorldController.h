#pragma once

#include "TES3Object.h"

namespace TES3 {
	struct WorldControllerRenderCamera {
		void * vTable;
		NI::Object * renderer;
		NI::Object * root;
		NI::Node * cameraRoot;
		NI::Camera * camera;
		float unknown_0x14;
		float unknown_0x18;
		float unknown_0x1C;
		float unknown_0x20;
		float unknown_0x24;
		float unknown_0x28;
	};
	static_assert(sizeof(WorldControllerRenderCamera) == 0x2C, "TES3::WorldControllerRenderCamera failed size validation");

	struct WorldControllerRenderTarget : WorldControllerRenderCamera {
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
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
	};
	static_assert(sizeof(WorldControllerRenderTarget) == 0x84, "TES3::WorldControllerRenderTarget failed size validation");

	struct WorldController {
		int unknown_0x0;
		int unknown_0x4;
		float unknown_0x8;
		float unknown_0xC;
		float maxFPS; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int systemTimeMillis; // 0x20
		int lastFrameTimeMillis; // 0x4
		int unknown_0x28;
		float deltaTime; // 0xC
		int unknown_0x30;
		void * audio; // 0x34
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		InputController * inputController; // 0x4C
		int unknown_0x50;
		Script * scriptGlobals; // 0x54
		WeatherController * weatherController; // 0x58
		int mobController; // 0x5C
		void * stats_60;
		void * field_64;
		void * splashController; // 0x68
		void * journalController; // 0x6C
		void * spllistActiveSpells; // 0x70
		int unknown_0x74;
		int viewWidth; // 0x78
		int viewHeight; // 0x7C
		int unknown_0x80;
		int bShadows; // 0x84
		int helpDelay; // 0x88
		unsigned char hudStyle; // 0x8C
		float menuAlpha; // 0x90
		bool cursorOff; // 0x94
		float aiDistance; // 0x98
		float difficulty; // 0x9C
		int werewolfFOV; // 0xA0
		float projectionDistance; // 0xA4
		GlobalVariable * gvarGameHour; // 0xA8
		GlobalVariable * gvarYear; // 0xAC
		GlobalVariable * gvarMonth; // 0xB0
		GlobalVariable * gvarDay; // 0xB4
		GlobalVariable * gvarDaysPassed; // 0xB8
		GlobalVariable * gvarTimescale; // 0xBC
		GlobalVariable * gvarCharGenState; // 0xC0
		GlobalVariable * gvarMonthsToRespawn; // 0xC4
		int Win32_hWndParent; // 0xC8
		int Win32_hWnd; // 0xCC
		int Win32_hInstance; // 0xD0
		bool flagEventMenuModeOn; // 0xD4
		bool flagEventMenuModeOff; // 0xD5
		bool flagMenuMode; // 0xD6
		char unknown_0xD7;
		char unknown_0xD8;
		char unknown_0xD9;
		char unknown_0xDA;
		bool stopGameLoop; // 0xDB
		char unknown_0xDC;
		char unknown_0xDD;
		char unknown_0xDE;
		char unknown_0xDF;
		bool flagTeleportingDisabled; // 0xE0
		bool flagLevitationDisabled; // 0xE1
		bool useBestAttack; // 0xE2
		bool canUseQuickSaveAndRest; // 0xE3
		char unknown_0xE4;
		char unknown_0xE5;
		char unknown_0xE6;
		bool shaderWaterReflectsTerrain; // 0xE7
		int mouseSensitivity; // 0xE8
		int horzSensitivity; // 0xEC
		int shaderWaterReflectUpdate; // 0xF0
		NI::Object * nodeCursor; // 0xF4
		WorldControllerRenderCamera splashscreenCamera; // 0xF8
		WorldControllerRenderCamera worldCamera; // 0x124
		WorldControllerRenderCamera unknown_0x150;
		WorldControllerRenderCamera unknown_0x17C;
		WorldControllerRenderTarget characterRenderTarget; // 0x1A8
		WorldControllerRenderTarget unknown_0x22C;
		WorldControllerRenderCamera unknown_0x2B0;
		int unknown_0x2DC;
		void * fogOfWarController; // 0x2E0
		void * menuController; // 0x2E4
		void * uiInventoryData; // 0x2E8
		int unknown_0x2EC;
		int unknown_0x2F0;
		int unknown_0x2F4;
		int unknown_0x2F8;
		int unknown_0x2FC;
		int unknown_0x300;
		int unknown_0x304;
		int unknown_0x308;
		int unknown_0x30C;
		int unknown_0x310;
		int unknown_0x314;
		int unknown_0x318;
		int unknown_0x31C;
		int unknown_0x320;
		int unknown_0x324;
		int unknown_0x328;
		int unknown_0x32C;
		float deadFloatScale; // 0x330
		int unknown_0x334;
		void * lstGlobalScripts; // 0x338
		void * listAllActors; // 0x33C
		void * listChargableItems; // 0x340
		bool showSubtitles; // 0x344
		int countMusicTracksBattle; // 0x348
		int countMusicTracksExplore; // 0x34C
		unsigned int musicState; // 0x350
		int unknown_0x354;
		int unknown_0x358;
		int unknown_0x35C;
		int unknown_0x360;
		int unknown_0x364;
		int unknown_0x368;
		int unknown_0x36C;
		int unknown_0x370;

		//
		// Other related this-call functions.
		//

		void mainLoopBeforeInput();
		MobilePlayer* getMobilePlayer();
		void playItemUpDownSound(BaseObject*, bool, Reference*);

	};
	static_assert(sizeof(WorldController) == 0x374, "TES3::WorldController failed size validation");
}
