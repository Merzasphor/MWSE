#pragma once

#include "TES3UIDefines.h"

namespace TES3 {
	namespace UI {
		UI_ID registerID(const char* name);
		Property registerProperty(const char* name);
		Block* createMenu(UI_ID id);
		Block* findMenu(UI_ID id);
		Boolean enterMenuMode(UI_ID id);
		Boolean leaveMenuMode();
		void acquireTextInput(Block* block);
		void preventInventoryMenuToggle(Block* menu);
	}
}
