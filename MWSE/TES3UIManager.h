#pragma once

#include "TES3UIDefines.h"
#include "TES3Vectors.h"

namespace TES3 {
	namespace UI {
		UI_ID registerID(const char* name);
		const char* lookupID(UI_ID id);
		Property registerProperty(const char* name);
		Element* createMenu(UI_ID id);
		Element* createHelpLayerMenu(UI_ID id);
		Element* createTooltipMenu(UI_ID id);
		Element* findMenu(UI_ID id);
		Element* findHelpLayerMenu(UI_ID id);
		Element* getMenuOnTop();
		Boolean enterMenuMode(UI_ID id);
		Boolean leaveMenuMode();
		void acquireTextInput(Element* element);
		void captureMouseDrag(bool capture);
		void preventInventoryMenuToggle(Element* menu);
		Vector3 getPaletteColour(Property prop);

		Boolean __cdecl onScrollPaneMousewheel(Element*, Property, int, int, Element*);

		MobileActor* getServiceActor();
		void updateDialogDisposition();

		const char* getInventorySelectType();
		void stealHelpMenu();
		void suppressHelpMenu();
		bool isSuppressingHelpMenu();
		void setSuppressingHelpMenu(bool);

		void logToConsole(const char* text, bool isCommand = false);

		void showBookMenu(const char* text);
		void showScrollMenu(const char* text);

		void updateFillBar(UI_ID id, float current, float max);
		void updateHealthFillBar(float current, float max);
		void updateMagickaFillBar(float current, float max);
		void updateFatigueFillBar(float current, float max);
		void updateEncumbranceBar();
		void updatePlayerAttribute(float current, int attributeId);
		void updateStatsPane();
		void updateSpellmakingMenu();
		void updateEnchantingMenu();

		void updateInventoryMenuTiles();
		void updateContentsMenuTiles();
		void updateContentsCompanionElements();
		void updateBarterMenuTiles();
		int updateSelectInventoryTiles();

		void hook();
	}
}
