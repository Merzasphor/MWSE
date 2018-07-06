#pragma once

#include "TES3UIDefines.h"
#include "NINode.h"
#include "NIPick.h"

namespace TES3 {
	namespace UI {
		struct MenuInputController {
			NI::Pick pick;
			char unknown_0x38[0x50];
			Block* blockTextInputFocus;
			char unknown_0x8C[0x20];

			void acquireTextInput(Block* block);
		};
		static_assert(sizeof(MenuInputController) == 0xAC, "TES3::UI::MenuInputController failed size validation");

		struct MenuController {
			Block* mainRoot;
			Block* helpRoot;
			NI::Node* mainNode;
			NI::Node* helpNode;
			MenuInputController* menuInputController;
			char unknown_[0x290];
		};
		static_assert(sizeof(MenuController) == 0x2A4, "TES3::UI::MenuController failed size validation");

	}
}