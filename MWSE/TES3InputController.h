#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

namespace TES3 {
	namespace KeyBind {
		enum KeyBind {
			Forward = 0x0,
			Back = 0x1,
			Left = 0x2,
			Right = 0x3,
			Use = 0x4,
			Activate = 0x5,
			ReadyWeapon = 0x6,
			ReadyMagic = 0x7,
			Crouch = 0x8,
			Run = 0x9,
			AlwaysRun = 0xA,
			AutoRun = 0xB,
			Jump = 0xC,
			NextWeapon = 0xD,
			PrevWeapon = 0xE,
			NextSpell = 0xF,
			PrevSpell = 0x10,
			TogglePOV = 0x11,
			MenuMode = 0x12,
			Journal = 0x13,
			Rest = 0x14,
			QuickMenu = 0x15,
			Quick1 = 0x16,
			Quick2 = 0x17,
			Quick3 = 0x18,
			Quick4 = 0x19,
			Quick5 = 0x1A,
			Quick6 = 0x1B,
			Quick7 = 0x1C,
			Quick8 = 0x1D,
			Quick9 = 0x1E,
			Quick10 = 0x1F,
			QuickSave = 0x20,
			QuickLoad = 0x21,
			Esc = 0x22,
			Console = 0x23,
			Screenshot = 0x24,
			ReadyMagicMCP = 0x25, // Used by MCP

			FindBindableKey = Forward,
			LastBindableKey = QuickLoad,

			FirstKey = Forward,
			LastKey = ReadyMagicMCP
		};
	}

	namespace KeyTransition {
		enum KeyTransition {
			Test = 0x0,
			Up = 0x1,
			Down = 0x2,
			Toggled = 0x3,
		};
	}

	namespace InputDevice {
		enum InputDevice {
			Keyboard,
			Mouse,
			Joystick,
			Gamepad,
			FirstDevice = Keyboard,
			LastDevice = Gamepad
		};
	}

	struct InputConfig {
		int keyCode;
		int device;
		int unknown_0x08;
		int unknown_0x0C;
	};
	static_assert(sizeof(InputConfig) == 0x10, "TES3::InputConfig failed size validation");

	struct InputController {
		unsigned int creationFlags; // 0x0
		LPDIRECTINPUT8 directInputInterface; // 0x4
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
		LPDIRECTINPUTDEVICE8 keyboard; // 0x28
		LPDIRECTINPUTDEVICE8 mouse; // 0x2C
		int unknown_0x30[320]; // Confirmed size.
		int unknown_0x530[4];
		int unknown_0x540[4];
		int unknown_0x550[4];
		int unknown_0x560[4];
		int unknown_0x570[4];
		int unknown_0x580[4];
		int unknown_0x590[4];
		int unknown_0x5A0[4];
		int unknown_0x5B0[4];
		int unknown_0x5C0[4];
		int unknown_0x5D0[4];
		int unknown_0x5E0[4];
		int unknown_0x5F0[4];
		int unknown_0x600[64];
		int unknown_0x700[64];
		int unknown_0x800[64];
		int unknown_0x900[64];
		int unknown_0xA00[64];
		int unknown_0xB00[64];
		int unknown_0xC00[64];
		int unknown_0xD00[64];
		int unknown_0xE00[64];
		int unknown_0xF00[64];
		int unknown_0x1000[64];
		int unknown_0x1100[64];
		int unknown_0x1200[64];
		int unknown_0x1300[64];
		int unknown_0x1400[64];
		int unknown_0x1500[64];
		int unknown_0x1600[64];
		int unknown_0x1700[64];
		int unknown_0x1800[4];
		int unknown_0x1810[4];
		int unknown_0x1820[4];
		int unknown_0x1830[4];
		int unknown_0x1840[4];
		int unknown_0x1850[4];
		int unknown_0x1860[4];
		int unknown_0x1870[4];
		int unknown_0x1880[4];
		int unknown_0x1890[4];
		int unknown_0x18A0[4];
		int unknown_0x18B0[4];
		int unknown_0x18C0[4];
		int unknown_0x18D0[4];
		int unknown_0x18E0[4];
		int unknown_0x18F0;
		int unknown_0x18F4[128]; // Confirmed size.
		int unknown_0x1AF4[10]; // Confirmed size.
		int unknown_0x1B1C;
		int unknown_0x1B20[4];
		int unknown_0x1B30;
		int unknown_0x1B34;
		char unknown_0x1B38; // Flag of some kind.
		char unknown_0x1B39; // Flag of some kind.
		char unknown_0x1B3A;
		char unknown_0x1B3B;
		InputConfig inputMaps[34]; // 0x1B3C

		//
		// Other related this-call functions.
		//

		void readKeyState();
		int keybindTest(unsigned int, unsigned int);

	};
	static_assert(sizeof(InputController) == 0x1D5C, "TES3::InputController failed size validation");

}
