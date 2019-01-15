#pragma once

#include "TES3UIDefines.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace UI {
		__declspec(dllexport) UI_ID registerID(const char* name);
		__declspec(dllexport) const char* lookupID(UI_ID id);
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

		__declspec(dllexport) MobileActor* getServiceActor();
		__declspec(dllexport) void updateDialogDisposition();

		__declspec(dllexport) const char* getInventorySelectType();

		__declspec(dllexport) void logToConsole(const char* text, bool isCommand = false);

		__declspec(dllexport) void showBookMenu(const char* text);
		__declspec(dllexport) void showScrollMenu(const char* text);

		__declspec(dllexport) void updateFillBar(UI_ID id, float current, float max);
		__declspec(dllexport) void updateHealthFillBar(float current, float max);
		__declspec(dllexport) void updateMagickaFillBar(float current, float max);
		__declspec(dllexport) void updateFatigueFillBar(float current, float max);
		__declspec(dllexport) void updateEncumbranceBar();
		__declspec(dllexport) void updatePlayerAttribute(float current, int attributeId);
		__declspec(dllexport) void updateStatsPane();

		__declspec(dllexport) void updateInventoryMenuTiles();
		__declspec(dllexport) void updateContentsMenuTiles();
		__declspec(dllexport) void updateContentsCompanionElements();
		__declspec(dllexport) void updateBarterMenuTiles();
		__declspec(dllexport) int updateSelectInventoryTiles();

		void hook();
	}
}
