#include "TES3UIMenuController.h"

namespace TES3 {
	namespace UI {
		const auto TES3_ui_resetBufferedInput = reinterpret_cast<void(__thiscall*)(MenuInputController *)>(0x58E9C0);

		void MenuInputController::acquireTextInput(Block* block) {
			// Set target for buffered text input
			blockTextInputFocus = block;
			// Reset text buffer to avoid previous input appearing immediately
			TES3_ui_resetBufferedInput(this);
		}
	}
}