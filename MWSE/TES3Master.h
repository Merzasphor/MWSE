#pragma once

#include <Windows.h>

#include "ObjectTypes.h"

namespace TES3 {
	namespace input {
		enum InputIndex {
			KeyForward,
			KeyBack,
			KeySlideLeft,
			KeySlideRight,
			KeyUse,
			KeyActivate,
			KeyReadyItem,
			KeyReadyMagic,
			KeyCrouchSneak,
			KeyRun,
			KeyAlwaysRun,
			KeyAutoRun,
			KeyJump,
			KeyNextWeapon,
			KeyPrevWeapon,
			KeyNextSpell,
			KeyPrevSpell,
			KeyTogglePOV,
			KeyMenuMode,
			KeyJournal,
			KeyRest,
			KeyQuickMenu,
			KeyQuick1,
			KeyQuick2,
			KeyQuick3,
			KeyQuick4,
			KeyQuick5,
			KeyQuick6,
			KeyQuick7,
			KeyQuick8,
			KeyQuick9,
			KeyQuick10,
			KeyQuickSave,
			KeyQuickload,
			KeyFirst = KeyForward,
			KeyLast = KeyQuickload
		};

		enum InputDevice {
			DeviceKeyboard,
			DeviceMouse,
			DeviceJoystick,
			DeviceGamepad,
			DeviceFirst = DeviceKeyboard,
			DeviceLast = DeviceGamepad
		};

		struct InputConfig {
			struct Input {
				int keyCode;
				int device;
				int unknown_0x08;
				int unknown_0x0C;
			};
			char unknown_0x00[0x1B3C];
			Input inputMaps[34];
		};
	}

	struct Master_vTable {

	};

	struct Master {
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		input::InputConfig * inputConfig; // 0x4C
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
		int unknown_0x84;
		int helpDelay; // 0x88
		BYTE HUDStyle; // 0x8C
		BYTE unknown_0x8D;
		BYTE unknown_0x8E;
		BYTE unknown_0x8F;
		mwLong HUDAlpha;
		BYTE cursorOff;
		BYTE unknown_0x95;
		BYTE unknown_0x96;
		BYTE unknown_0x97;
		mwLong AIDistance; // 0x98
		mwLong difficulty; // 0x9C
		mwLong werewolfFOV; // 0xA0
		int unknown_0xA4;
		int unknown_0xA8;
		int unknown_0xAC;
		int unknown_0xB0;
		int unknown_0xB4;
		int unknown_0xB8;
		int unknown_0xBC;
		int unknown_0xC0;
		int unknown_0xC4;
		HWND windowHandle1; // 0xC8
		HWND windowHandle2; // 0xCC
		HINSTANCE moduleInstance; // 0xD0
		BYTE unknown_0xD4;
		BYTE unknown_0xD5;
		BYTE unknown_0xD6;
		BYTE unknown_0xD7;
		BYTE unknown_0xD8;
		BYTE unknown_0xD9;
		BYTE unknown_0xDA;
		BYTE shouldQuit; // 0xDB
		BYTE unknown_0xDC;
		BYTE unknown_0xDD;
		BYTE unknown_0xDE;
		BYTE unknown_0xDF;
		BYTE teleportationDisabled; // 0xE0
		BYTE levitationDisabled; // 0xE1
		BYTE useBestAttack; // 0xE2
		BYTE quickSaveOnRest; // 0xE3
		BYTE unknown_0xE4;
		BYTE unknown_0xE5;
		BYTE unknown_0xE6;
		BYTE waterReflectTerrain; // 0xE7
		mwLong controlVerticalSensitivity; // 0xE8
		mwLong controlHorizontalSensitivity; // 0xEC
		int unknown_0xF0;
		int unknown_0xF4;
		int unknown_0xF8;
		int unknown_0xFC;
		int unknown_0x100;
		int unknown_0x104;
		int unknown_0x108;
		int unknown_0x10C;
		int unknown_0x110;
		int unknown_0x114;
		int unknown_0x118;
		int unknown_0x11C;
		int unknown_0x120;
		int unknown_0x124;
		int unknown_0x128;
		int unknown_0x12C;
		int unknown_0x130;
		int unknown_0x134;
		int unknown_0x138;
		int unknown_0x13C;
		int unknown_0x140;
		int unknown_0x144;
		int unknown_0x148;
		int unknown_0x14C;
		int unknown_0x150;
		int unknown_0x154;
		int unknown_0x158;
		int unknown_0x15C;
		int unknown_0x160;
		int unknown_0x164;
		int unknown_0x168;
		int unknown_0x16C;
		int unknown_0x170;
		int unknown_0x174;
		int unknown_0x178;
		int unknown_0x17C;
		int unknown_0x180;
		int unknown_0x184;
		int unknown_0x188;
		int unknown_0x18C;
		int unknown_0x190;
		int unknown_0x194;
		int unknown_0x198;
		int unknown_0x19C;
		int unknown_0x1A0;
		int unknown_0x1A4;
		int unknown_0x1A8;
		int unknown_0x1AC;
		int unknown_0x1B0;
		int unknown_0x1B4;
		int unknown_0x1B8;
		int unknown_0x1BC;
		int unknown_0x1C0;
		int unknown_0x1C4;
		int unknown_0x1C8;
		int unknown_0x1CC;
		int unknown_0x1D0;
		int unknown_0x1D4;
		int unknown_0x1D8;
		int unknown_0x1DC;
		int unknown_0x1E0;
		int unknown_0x1E4;
		int unknown_0x1E8;
		int unknown_0x1EC;
		int unknown_0x1F0;
		int unknown_0x1F4;
		int unknown_0x1F8;
		int unknown_0x1FC;
		int unknown_0x200;
		int unknown_0x204;
		int unknown_0x208;
		int unknown_0x20C;
		int unknown_0x210;
		int unknown_0x214;
		int unknown_0x218;
		int unknown_0x21C;
		int unknown_0x220;
		int unknown_0x224;
		int unknown_0x228;
		int unknown_0x22C;
		int unknown_0x230;
		int unknown_0x234;
		int unknown_0x238;
		int unknown_0x23C;
		int unknown_0x240;
		int unknown_0x244;
		int unknown_0x248;
		int unknown_0x24C;
		int unknown_0x250;
		int unknown_0x254;
		int unknown_0x258;
		int unknown_0x25C;
		int unknown_0x260;
		int unknown_0x264;
		int unknown_0x268;
		int unknown_0x26C;
		int unknown_0x270;
		int unknown_0x274;
		int unknown_0x278;
		int unknown_0x27C;
		int unknown_0x280;
		int unknown_0x284;
		int unknown_0x288;
		int unknown_0x28C;
		int unknown_0x290;
		int unknown_0x294;
		int unknown_0x298;
		int unknown_0x29C;
		int unknown_0x2A0;
		int unknown_0x2A4;
		int unknown_0x2A8;
		int unknown_0x2AC;
		int unknown_0x2B0;
		int unknown_0x2B4;
		int unknown_0x2B8;
		int unknown_0x2BC;
		int unknown_0x2C0;
		int unknown_0x2C4;
		int unknown_0x2C8;
		int unknown_0x2CC;
		int unknown_0x2D0;
		int unknown_0x2D4;
		int unknown_0x2D8;
		int unknown_0x2DC;
		int unknown_0x2E0;
		int unknown_0x2E4;
		int unknown_0x2E8;
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
		int unknown_0x330;
		int unknown_0x334;
		int unknown_0x338;
		int unknown_0x33C;
		int unknown_0x340;
		int unknown_0x344;
		int unknown_0x348;
		int unknown_0x34C;
		int unknown_0x350;
		int unknown_0x354;
		int unknown_0x358;
		int unknown_0x35C;
		int unknown_0x360;
		int unknown_0x364;
		int unknown_0x368;
		int unknown_0x36C;
		int unknown_0x370;
	};
	static_assert(sizeof(Master) == 0x374, "TES3::Master failed size validation");
}
