#pragma once

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

	struct InputController {
		char unknown_0x00[0x1B3C];
		InputConfig inputMaps[34];
	};
}
