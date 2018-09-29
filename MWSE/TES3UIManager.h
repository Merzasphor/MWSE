#pragma once

#include "TES3UIDefines.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace UI {
		__declspec(dllexport) UI_ID registerID(const char* name);
		__declspec(dllexport) Property registerProperty(const char* name);
		__declspec(dllexport) Element* createMenu(UI_ID id);
		__declspec(dllexport) Element* createHelpLayerMenu(UI_ID id);
		__declspec(dllexport) Element* createTooltipMenu(UI_ID id);
		__declspec(dllexport) Element* findMenu(UI_ID id);
		__declspec(dllexport) Element* findHelpLayerMenu(UI_ID id);
		__declspec(dllexport) Boolean enterMenuMode(UI_ID id);
		__declspec(dllexport) Boolean leaveMenuMode();
		__declspec(dllexport) void acquireTextInput(Element* element);
		__declspec(dllexport) void preventInventoryMenuToggle(Element* menu);
		__declspec(dllexport) Vector3 getPaletteColour(Property prop);

		Boolean __cdecl onScrollPaneMousewheel(Element*, Property, int, int, Element*);

		MobileActor* getServiceActor();
		void updateDialogDisposition();

		__declspec(dllexport) const char* getInventorySelectType();

		void hook();
	}
}
