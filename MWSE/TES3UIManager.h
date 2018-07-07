#pragma once

#include "TES3UIDefines.h"

namespace TES3 {
	namespace UI {
		UI_ID registerID(const char* name);
		Property registerProperty(const char* name);
		Element* createMenu(UI_ID id);
		Element* findMenu(UI_ID id);
		Boolean enterMenuMode(UI_ID id);
		Boolean leaveMenuMode();
		void acquireTextInput(Element* element);
		void preventInventoryMenuToggle(Element* menu);
	}
}
