#pragma once

#include "TES3UIDefines.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace UI {
		UI_ID registerID(const char* name);
		Property registerProperty(const char* name);
		Element* createMenu(UI_ID id);
		Element* createHelpLayerMenu(UI_ID id);
		Element* createTooltipMenu(UI_ID id);
		Element* findMenu(UI_ID id);
		Element* findHelpLayerMenu(UI_ID id);
		Boolean enterMenuMode(UI_ID id);
		Boolean leaveMenuMode();
		void acquireTextInput(Element* element);
		void preventInventoryMenuToggle(Element* menu);
		Vector3 getPaletteColour(Property prop);

		Boolean __cdecl onScrollPaneMousewheel(Element*, Property, int, int, Element*);

		MobileActor* getServiceActor();
		void updateDialogDisposition();

		void hook();
	}
}
