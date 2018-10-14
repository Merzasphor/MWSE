#pragma once

#include "TES3UIDefines.h"
#include "NINode.h"
#include "NIPick.h"

namespace TES3 {
	namespace UI {
		struct MenuInputController {
			NI::Pick pick;
			char unknown_0x38[0x50];
			Element* textInputFocus;
			char unknown_0x8C[0x20];

			void acquireTextInput(Element* element);
		};
		static_assert(sizeof(MenuInputController) == 0xAC, "TES3::UI::MenuInputController failed size validation");

		struct MenuController {
			Element* mainRoot; // 0x0
			Element* helpRoot; // 0x4
			NI::Node* mainNode; // 0x8
			NI::Node* helpNode; // 0xC
			MenuInputController* menuInputController; // 0x10
			int unknown_0x14;
			int unknown_0x18;
			int unknown_0x1C;
			ScriptCompiler * scriptCompiler; // 0x20
			int unknown_0x24;
			char unknown_0x28[0x27C];
		};
		static_assert(sizeof(MenuController) == 0x2A4, "TES3::UI::MenuController failed size validation");

	}
}