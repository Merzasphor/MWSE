#include <cstdint>
#include <unordered_map>
#include <vector>

#include "MemoryUtil.h"
#include "TES3UIElement.h"
#include "TES3UIManager.h"
#include "TES3UIMenuController.h"
#include "TES3Util.h"
#include "TES3WorldController.h"

namespace TES3 {
	namespace UI {
		static std::unordered_map<Element*, std::vector<Element*>> wrappingTextLabels;

		const DWORD TES3_hook_dispatchMousewheelUp = 0x58F19B;
		const DWORD TES3_hook_dispatchMousewheelDown = 0x58F1CA;

		const auto TES3_ui_registerID = reinterpret_cast<UI_ID (__cdecl *)(const char *)>(0x58DF10);
		const auto TES3_ui_createMenu = reinterpret_cast<Element* (__cdecl *)(UI_ID)>(0x595400);
		const auto TES3_ui_findMenu = reinterpret_cast<Element* (__cdecl*)(UI_ID)>(0x595370);
		const auto TES3_ui_onMenuUnfocus = reinterpret_cast<EventCallback>(0x58F790);
		const auto TES3_ui_ScrollbarArrow_onClick = reinterpret_cast<EventCallback>(0x647A60);
		const auto TES3_ui_requestMenuModeOn = reinterpret_cast<Boolean (__cdecl*)(UI_ID)>(0x595230);
		const auto TES3_ui_requestMenuModeOff = reinterpret_cast<Boolean (__cdecl*)(UI_ID)>(0x595270);

		//
		// UI framework functions
		//

		UI_ID registerID(const char *name) {
			return TES3_ui_registerID(name);
		}

		Property registerProperty(const char *name) {
			return static_cast<Property>(TES3_ui_registerID(name));
		}

		Element* createMenu(UI_ID id) {
			return TES3_ui_createMenu(id);
		}

		Element* findMenu(UI_ID id) {
			return TES3_ui_findMenu(id);
		}

		Boolean enterMenuMode(UI_ID id) {
			return TES3_ui_requestMenuModeOn(id);
		}

		Boolean leaveMenuMode() {
			return TES3_ui_requestMenuModeOff(0);
		}

		void acquireTextInput(Element* element) {
			MenuController *menuController = static_cast<MenuController*>(mwse::tes3::getWorldController()->menuController);
			menuController->menuInputController->acquireTextInput(element);
		}

		void preventInventoryMenuToggle(Element* menu) {
			menu->setProperty(Property::event_unfocus, TES3_ui_onMenuUnfocus);
		}

		//
		// Added functionality
		//

		void registerWrappedText(Element* textLabel) {
			static auto propPartDragMenu = registerProperty("PartDragMenu");

			Element *menu = textLabel->getTopLevelParent();
			if (menu->getProperty(PropertyType::Property, Property::is_part).propertyValue == propPartDragMenu) {
				wrappingTextLabels[menu].push_back(textLabel);
			}
		}

		void unregisterTextContainer(Element* menu) {
			wrappingTextLabels.erase(menu);
		}

		Boolean __cdecl onTextContainerResizing(Element* owningWidget, Property eventID, int data0, int data1, Element* source) {
			// Find all text labels that are children of this container
			auto it = wrappingTextLabels.find(source);
			if (it != wrappingTextLabels.end()) {
				for (auto iterTextLabel : it->second) {
					// Cause text label to reflow on next layout during resize
					iterTextLabel->flagContentChanged = true;
				}
			}
			return 1;
		}

		Boolean __cdecl onScrollPaneMousewheel(Element* owningWidget, Property eventID, int data0, int data1, Element* source) {
			static auto propScrollPane = registerProperty("PartScrollPane");
			static auto propScrollPaneHor = registerProperty("PartScrollPaneHor");
			static auto propScrollPaneVert = registerProperty("PartScrollPaneVert");
			static auto propScrollbarHor = registerID("PartScrollPane_hor_scrollbar");
			static auto propScrollbarVert = registerID("PartScrollPane_vert_scrollbar");
			static auto propScrollLeftArrow = registerID("PartScrollBar_left_arrow");
			static auto propScrollRightArrow = registerID("PartScrollBar_right_arrow");

			Element* scrollbar = nullptr;
			Element* pane;
			for (pane = source; pane; pane = pane->parent) {
				Property part = pane->getProperty(PropertyType::Property, Property::is_part).propertyValue;
				if (part == propScrollPaneVert) {
					scrollbar = pane->findChild(propScrollbarVert);
					break;
				}
				else if (part == propScrollPane || part == propScrollPaneHor) {
					scrollbar = pane->findChild(propScrollbarHor);
					break;
				}
			}

			if (scrollbar) {
				// Forward event to left or right arrow depending on scroll direction in data0
				UI_ID arrowID = (data0 < 0) ? propScrollRightArrow : propScrollLeftArrow;
				Element* arrow = scrollbar->findChild(arrowID);
				return TES3_ui_ScrollbarArrow_onClick(scrollbar, eventID, data0, data1, arrow);
			}
			return 1;
		}

		//
		// UI framework improvement hooks
		//

		__declspec(naked) void patchDispatchMousewheelUp() {
			__asm {
				mov eax, [esi + 4]
				mov edx, [esi + 8]
				push ecx
				push edx
				push eax
				push 0xFFFF8036
				jmp $ + 0x37C
			}
		}
		const size_t patchDispatchMousewheelUp_size = 0x14;

		__declspec(naked) void patchDispatchMousewheelDown() {
			__asm {
				mov eax, [esi + 4]
				mov edx, [esi + 8]
				push ecx
				push edx
				push eax
				push 0xFFFF8037
				jmp $ + 0x34D
			}
		}
		const size_t patchDispatchMousewheelDown_size = 0x14;

		void hook() {
			// Patch mousewheel event dispatch to not redirect to the top-level element,
			// allowing mousewheel to apply to more than the first scrollpane in a menu
			mwse::writePatchUnprotected(TES3_hook_dispatchMousewheelUp, (BYTE*)&patchDispatchMousewheelUp, patchDispatchMousewheelUp_size);
			mwse::writePatchUnprotected(TES3_hook_dispatchMousewheelDown, (BYTE*)&patchDispatchMousewheelDown, patchDispatchMousewheelDown_size);
		}

	}
}
