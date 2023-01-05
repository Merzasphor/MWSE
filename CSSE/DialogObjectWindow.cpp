#include "DialogObjectWindow.h"

#include "LogUtil.h"
#include "MemoryUtil.h"
#include "StringUtil.h"
#include "WindowsUtil.h"

#include "NIIteratedList.h"

#include "CSBook.h"
#include "CSScript.h"

#include "EditBasicExtended.h"

#include "Settings.h"

namespace se::cs::dialog::object_window {
	using memory::ExternalGlobal;

	using ghWndMainWindow = ExternalGlobal<HWND, 0x6CE934>;
	using ghWndTabControl = ExternalGlobal<HWND, 0x6CF08C>;
	using ghWndObjectList = ExternalGlobal<HWND, 0x6CEFD0>;
	static HWND objectWindowSearchControl = NULL;

	struct ObjectWindowTabData {
		ObjectType::ObjectType objectType; // 0x0
		unsigned int columnCount; // 0x4
		unsigned int topIndex; // 0x8
		NI::IteratedList<BaseObject*>* containedObjects; // 0xC
	};

	namespace Tab {
		enum Tab_t {
			Activator,
			Apparatus,
			Armor,
			BodyPart,
			Book,
			Clothing,
			Container,
			Door,
			Ingredient,
			Light,
			Lockpick,
			MiscItem,
			Probe,
			RepairItem,
			Static,
			Weapon,
			NPC,
			Creature,
			LeveledCreature,
			Spellmaking,
			Enchanting,
			Alchemy,
			LeveledItem,

			COUNT,
		};
	}

	namespace ListColumns {
		namespace Activator {
			enum Column_t {
				ID, Count, Name, Script, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Apparatus {
			enum Column_t {
				ID, Count, Type, Name, Script, Weight, Value, Quality, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Armor {
			enum Column_t {
				ID, Count, Type, Name, Script, Weight, WeightClass, Value, Health, Enchanting, Enchantment, Rating, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace BodyPart {
			enum Column_t {
				ID, Count, Type, Race, Part, Female, Playable, Model, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Book {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Scroll, Teaches, Enchanting, Enchantment, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Clothing {
			enum Column_t {
				ID, Count, Type, Name, Script, Weight, Value, Enchanting, Enchantment, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Container {
			enum Column_t {
				ID, Count, Name, Script, Weight, Organic, Respawns, ItemList, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Door {
			enum Column_t {
				ID, Count, Name, Script, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Ingredient {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Effect1, Effect2, Effect3, Effect4, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Light {
			enum Column_t {
				ID, Count, Name, Script, Sound, Weight, Value, Time, Radius, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Lockpick {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Uses, Quality, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace MiscItem {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Probe {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Uses, Quality, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace RepairItem {
			enum Column_t {
				ID, Count, Name, Script, Weight, Value, Uses, Quality, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Static {
			enum Column_t {
				ID, Count, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Weapon {
			enum Column_t {
				ID, Count, Type, Name, Script, Weight, Health, Value, Enchanting, Enchantment, Speed, Reach, ChopMin, ChopMax, SlashMin, SlashMax, ThrustMin, ThrustMax, Inventory, IgnoreResist, Silver, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace NPC {
			enum Column_t {
				ID, Count, Name, Script, Level, Race, Female, Class, Faction, Rank, AutoCalc, Essential, REspawns, Animation, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Creature {
			enum Column_t {
				ID, Count, Name, Type, Script, Sound, Level, Essential, Respawns, MovementType, Weapon, Biped, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace LeveledCreature {
			enum Column_t {
				ID, Count, AllLTEPC, CreatureList, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Spellmaking {
			enum Column_t {
				ID, Count, Name, Type, Cost, AutoCalc, PCStart, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Enchanting {
			enum Column_t {
				ID, Count, Charge, Type, Cost, AutoCalc, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace Alchemy {
			enum Column_t {
				ID, Count, Name, Script, Weight, Cost, AutoCalc, Inventory, Model, Persistent, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
		namespace LeveledItem {
			enum Column_t {
				ID, Count, AllLTEPC, ItemList, Blocked,
				Modified,

				COUNT,
				COUNT_VANILLA = Modified,
			};
		}
	}

	namespace ColumnNames {
		enum ColumnNames_t : BYTE {
			ID,
			COUNT,
			MODEL,
			NAME,
			RACE,
			CLASS,
			FACTION,
			SCRIPT,
			CELL,
			RANK,
			TYPE,
			WEIGHT,
			VALUE,
			HEALTH,
			QUALITY,
			INVENTORY,
			ENCHANTMENT,
			RATING,
			SPEED,
			BLOCK,
			REACH,
			CHOPMIN,
			CHOPMAX,
			SLASHMIN,
			SLASHMAX,
			THRUSTMIN,
			THRUSTMAX,
			IGNORESRESIST,
			PART,
			FEMALE,
			SCROLL,
			TEACHES,
			LEVEL,
			KEY,
			TRAP,
			EFFECT1,
			EFFECT2,
			EFFECT3,
			EFFECT4,
			TIME,
			RADIUS,
			USES,
			COST,
			ITEMNAME,
			ANIMATION,
			CREATURELIST,
			ITEMLIST,
			ENCHANTING,
			PLAYABLE,
			CHARGE,
			WEIGHTCLASS,
			AUTOCALC,
			ORGANIC,
			ESSENTIAL,
			RESPAWNS,
			MOVEMENTTYPE,
			WEAPONSHIELD,
			BIPEDANIM,
			ALLPC,
			PERSISTS,
			PCSTARTSPELL,
			BLOCKED,
			SOUND,
			SILVERWEAPON,
			MODIFIED,

			COLUMN_COUNT,
			COLUMN_COUNT_VANILLA = SILVERWEAPON + 1,
		};
	}
	static_assert(sizeof(ColumnNames::COLUMN_COUNT) == sizeof(BYTE), "Unsupported column count. Requires further replacement of cmp operators.");

	const char* columnNames[ColumnNames::COLUMN_COUNT] = {};

	WORD columnWidths[ColumnNames::COLUMN_COUNT] = {};

	//
	// Patch: Optimize displaying of objects dialog tabs.
	//

	const auto NI_IteratedList_Begin = reinterpret_cast<NI::IteratedList<BaseObject*>::Node * (__thiscall*)(NI::IteratedList<BaseObject*>*)>(0x401E29);
	NI::IteratedList<BaseObject*>::Node* __fastcall PatchSpeedUpObjectWindow_PauseRedraws(NI::IteratedList<BaseObject*>* list) {
		auto result = NI_IteratedList_Begin(list);

		if (result) {
			const auto listView = ghWndObjectList::get();
			SendMessageA(listView, WM_SETREDRAW, FALSE, NULL);
		}

		return result;
	}

	const auto NI_IteratedList_Next = reinterpret_cast<NI::IteratedList<BaseObject*>::Node * (__thiscall*)(NI::IteratedList<BaseObject*>*)>(0x403D8C);
	NI::IteratedList<BaseObject*>::Node* __fastcall PatchSpeedUpObjectWindow_ResumeRedraws(NI::IteratedList<BaseObject*>* list) {
		auto result = NI_IteratedList_Next(list);

		if (result == nullptr) {
			const auto listView = ghWndObjectList::get();
			SendMessageA(listView, WM_SETREDRAW, TRUE, NULL);
		}

		return result;
	}

	//
	// Patch: Add modified column.
	//

	void __fastcall PatchAddModifiedColumn(ObjectWindowTabData* controller, DWORD _EDX_, HWND hWnd, LPSTR text, int cx, int fmt, UINT mask) {
		const auto AddColumn = reinterpret_cast<void(__thiscall*)(ObjectWindowTabData*, HWND, LPSTR, int, int, UINT)>(0x442700);
		AddColumn(controller, hWnd, text, cx, fmt, mask);

		constexpr auto modified = "Modified";
		AddColumn(controller, hWnd, (LPSTR)modified, cx, fmt, mask);
	}

	int __stdcall PatchAddModifiedColumn_Sorter(BaseObject* lParam1, BaseObject* lParam2, int lParamSort) {
		auto sortColumn = static_cast<ColumnNames::ColumnNames_t>(lParamSort >> 1);
		if (sortColumn < ColumnNames::COLUMN_COUNT_VANILLA) {
			const auto DefaultSorter = reinterpret_cast<int(__stdcall*)(BaseObject*, BaseObject*, int)>(0x43ED10);
			return DefaultSorter(lParam1, lParam2, lParamSort);
		}

		bool sortOrderAsc = lParamSort & 1;

		switch (sortColumn) {
		case ColumnNames::MODIFIED:
			if (lParam1->getModified() != lParam2->getModified()) {
				if (sortOrderAsc) {
					return lParam1->getModified() ? 1 : -1;
				}
				else {
					return lParam1->getModified() ? -1 : 1;
				}
			}
		}

		return 0;
	}

	int getModifiedColumn(ObjectWindowTabData* tabData) {
		switch (tabData->objectType) {
		case ObjectType::Activator: return ListColumns::Activator::Modified;
		case ObjectType::Alchemy: return ListColumns::Alchemy::Modified;
		case ObjectType::Apparatus: return ListColumns::Apparatus::Modified;
		case ObjectType::Armor: return ListColumns::Armor::Modified;
		case ObjectType::Bodypart: return ListColumns::BodyPart::Modified;
		case ObjectType::Book: return ListColumns::Book::Modified;
		case ObjectType::Clothing: return ListColumns::Clothing::Modified;
		case ObjectType::Container: return ListColumns::Container::Modified;
		case ObjectType::Creature: return ListColumns::Creature::Modified;
		case ObjectType::Door: return ListColumns::Door::Modified;
		case ObjectType::Enchantment: return ListColumns::Enchanting::Modified;
		case ObjectType::Ingredient: return ListColumns::Ingredient::Modified;
		case ObjectType::LeveledCreature: return ListColumns::LeveledCreature::Modified;
		case ObjectType::LeveledItem: return ListColumns::LeveledItem::Modified;
		case ObjectType::Light: return ListColumns::Light::Modified;
		case ObjectType::Lockpick: return ListColumns::Lockpick::Modified;
		case ObjectType::Misc: return ListColumns::MiscItem::Modified;
		case ObjectType::NPC: return ListColumns::NPC::Modified;
		case ObjectType::Probe: return ListColumns::Probe::Modified;
		case ObjectType::Repair: return ListColumns::RepairItem::Modified;
		case ObjectType::Spell: return ListColumns::Spellmaking::Modified;
		case ObjectType::Static: return ListColumns::Static::Modified;
		case ObjectType::Weapon: return ListColumns::Weapon::Modified;
		}
		return -1;
	}

	const auto DefaultDisplayHandler = reinterpret_cast<void(__thiscall*)(ObjectWindowTabData*, LPNMLVDISPINFOA)>(0x43C330);
	void __fastcall PatchAddModifiedColumn_GetDisplayInfo(ObjectWindowTabData* tabData, DWORD _EDX_, LPNMLVDISPINFOA displayInfo) {
		if ((displayInfo->item.mask & LVIF_TEXT) == 0) {
			DefaultDisplayHandler(tabData, displayInfo);
			return;
		}

		if (displayInfo->item.iSubItem == getModifiedColumn(tabData)) {
			auto object = reinterpret_cast<BaseObject*>(displayInfo->item.lParam);
			sprintf_s(displayInfo->item.pszText, displayInfo->item.cchTextMax, "%s", object->getModified() ? "yes" : "no");
			return;
		}

		DefaultDisplayHandler(tabData, displayInfo);
	}

	//
	// Patch: Allow filtering of object window.
	//

	static std::string currentSearchText;
	static std::optional<std::regex> currentSearchRegex;

	bool matchDispatcher(const std::string_view& haystack) {
		if (currentSearchRegex) {
			return std::regex_search(haystack.data(), currentSearchRegex.value());
		}
		else if (settings.object_window.case_sensitive) {
			return string::contains(haystack, currentSearchText);
		}
		else {
			return string::cicontains(haystack, currentSearchText);
		}
	}

	bool PatchFilterObjectWindow_ObjectMatchesSearchText(const Object* object) {
		// If we have no search text, always allow.
		if (currentSearchText.empty()) {
			return true;
		}

		// Allow filtering by object ID.
		if (settings.object_window.filter_by_id) {
			if (matchDispatcher(object->getObjectID())) {
				return true;
			}
		}

		// Allow filtering by object name.
		if (settings.object_window.filter_by_name) {
			if (matchDispatcher(object->getName())) {
				return true;
			}
		}

		// Allow filtering by model path.
		if (settings.object_window.filter_by_model_path) {
			if (matchDispatcher(object->getModel())) {
				return true;
			}
		}

		// Allow filtering by icon path.
		if (settings.object_window.filter_by_icon_path) {
			if (matchDispatcher(object->getIcon())) {
				return true;
			}
		}

		// Allow filtering by enchantment id.
		if (settings.object_window.filter_by_enchantment_id) {
			auto enchantment = object->getEnchantment();
			if (enchantment && matchDispatcher(enchantment->getObjectID())) {
				return true;
			}
		}

		// Allow filtering by script id.
		if (settings.object_window.filter_by_script_id) {
			auto script = object->getScript();
			if (script && matchDispatcher(script->getObjectID())) {
				return true;
			}
		}

		// Allow filtering by book text.
		if (settings.object_window.filter_by_book_text && object->objectType == ObjectType::Book) {
			auto asBook = static_cast<const Book*>(object);
			if (asBook->text && matchDispatcher(asBook->text)) {
				return true;
			}
		}

		return false;
	}

	void CALLBACK PatchFilterObjectWindow(LPARAM index, const Object* object) {
		if (PatchFilterObjectWindow_ObjectMatchesSearchText(object)) {
			const auto CS_AddObjectToWindow = reinterpret_cast<void(__stdcall*)(LPARAM, const BaseObject*)>(0x43C260);
			CS_AddObjectToWindow(index, object);
		}
	}

	//
	// Patch: Extend Object Window message handling.
	//

	std::optional<LRESULT> forcedReturnType = {};

	void CALLBACK PatchDialogProc_BeforeSize(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
		// Update view menu.
		auto mainWindow = GetMenu(ghWndMainWindow::get());
		if (wParam) {
			if (wParam == SIZE_MINIMIZED) {
				CheckMenuItem(mainWindow, 40199u, MF_BYCOMMAND);
			}
		}
		else {
			CheckMenuItem(mainWindow, 40199u, MF_CHECKED);
		}

		auto tabControl = GetDlgItem(hDlg, CONTROL_ID_TABS);
		auto objectListView = GetDlgItem(hDlg, CONTROL_ID_LIST_VIEW);
		auto searchLabel = GetDlgItem(hDlg, CONTROL_ID_FILTER_LABEL);
		auto searchEdit = GetDlgItem(hDlg, CONTROL_ID_FILTER_EDIT);

		// Update globals.
		ghWndTabControl::set(tabControl);
		ghWndObjectList::set(objectListView);
		objectWindowSearchControl = searchEdit;

		const auto mainWidth = LOWORD(lParam);
		const auto mainHeight = HIWORD(lParam);

		// Make room for our new search bar.
		MoveWindow(tabControl, 0, 0, mainWidth, mainHeight, TRUE);

		// Update list view area.
		RECT tabContentRect = {};
		SetRect(&tabContentRect, 0, 0, mainWidth, mainHeight - 30);
		SendMessageA(tabControl, TCM_ADJUSTRECT, 0, (LPARAM)&tabContentRect);
		MoveWindow(objectListView, tabContentRect.left, tabContentRect.top, tabContentRect.right - tabContentRect.left, tabContentRect.bottom - tabContentRect.top, TRUE);

		// Update the search bar placement.
		auto width = std::min<int>(tabContentRect.right - tabContentRect.left, 500);
		SetWindowPos(searchLabel, NULL, tabContentRect.right - width - 58, tabContentRect.bottom + 7, 54, 22, 0);
		SetWindowPos(objectWindowSearchControl, NULL, tabContentRect.right - width, tabContentRect.bottom + 4, width, 24, SWP_DRAWFRAME);
		RedrawWindow(objectWindowSearchControl, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
	}

	void CALLBACK PatchDialogProc_AfterCreate(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		auto hInstance = (HINSTANCE)GetWindowLongA(hWnd, GWLP_HINSTANCE);

		// Ensure our custom filter box is added.
		auto objectWindowSearchControl = GetDlgItem(hWnd, CONTROL_ID_FILTER_EDIT);
		if (objectWindowSearchControl == NULL) {
			CreateWindowExA(WS_EX_RIGHT, "STATIC", "Filter:", WS_CHILD | WS_VISIBLE | SS_RIGHT | SS_NOPREFIX, 0, 0, 0, 0, hWnd, (HMENU)CONTROL_ID_FILTER_LABEL, hInstance, NULL);
			objectWindowSearchControl = CreateWindowExA(WS_EX_CLIENTEDGE, "EDIT", "", WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hWnd, (HMENU)CONTROL_ID_FILTER_EDIT, hInstance, NULL);
			if (objectWindowSearchControl) {
				SetWindowSubclass(objectWindowSearchControl, ui_subclass::edit::BasicExtendedProc, NULL, NULL);
				Edit_LimitText(objectWindowSearchControl, 31);
			}
			else {
				log::stream << "ERROR: Could not create search control!" << std::endl;
			}
		}
	}

	inline void OnNotifyFromMainListView(HWND hWnd, UINT msg, WPARAM id, LPARAM lParam) {
		using windows::isKeyDown;

		const auto hdr = (NMHDR*)lParam;

		if (hdr->code == LVN_KEYDOWN) {
			const auto keydownHDR = (LV_KEYDOWN*)hdr;
			if (keydownHDR->wVKey == 'F' && isKeyDown(VK_CONTROL)) {
				SetFocus(objectWindowSearchControl);
			}
		}
		else if (hdr->code == LVN_MARQUEEBEGIN) {
			// I've tried DWLP_MSGRESULT, subclassing, blocking this notification, changing styles, and so much else.
			// Somehow, this is the only thing that has worked...
			Sleep(20);
			forcedReturnType = TRUE;
		}
		else if (hdr->code == NM_CUSTOMDRAW && settings.object_window.highlight_modified_items) {
			LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)lParam;
			if (lplvcd->nmcd.dwDrawStage == CDDS_PREPAINT) {
				SetWindowLongA(hWnd, DWLP_MSGRESULT, CDRF_NOTIFYITEMDRAW);
			}
			else if (lplvcd->nmcd.dwDrawStage == CDDS_ITEMPREPAINT) {
				auto object = (BaseObject*)lplvcd->nmcd.lItemlParam;
				if (object) {
					if (object->flags & 0x20) {
						lplvcd->clrTextBk = RGB(255, 235, 235);
						SetWindowLongA(hWnd, DWLP_MSGRESULT, CDRF_NEWFONT);
					}
					else if (object->getModified()) {
						lplvcd->clrTextBk = RGB(235, 255, 235);
						SetWindowLongA(hWnd, DWLP_MSGRESULT, CDRF_NEWFONT);
					}
				}
			}
			forcedReturnType = TRUE;
		}
	}

	inline void OnNotifyFromMainTabControl(HWND hWnd, UINT msg, WPARAM id, LPARAM lParam) {
		const auto hdr = (NMHDR*)lParam;

		if (hdr->code == TCN_SELCHANGING && settings.object_window.clear_filter_on_tab_switch) {
			SetWindowTextA(objectWindowSearchControl, "");
		}
	}

	inline void PatchDialogProc_BeforeNotify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (wParam) {
		case CONTROL_ID_LIST_VIEW:
			OnNotifyFromMainListView(hWnd, msg, wParam, lParam);
			break;
		case CONTROL_ID_TABS:
			OnNotifyFromMainTabControl(hWnd, msg, wParam, lParam);
			break;
		}
	}

	inline void OnFilterEditChanged(HWND hWnd) {
		// Get current search text. The buffer is fine as 32 because we set a character limit of 31.
		char buffer[32] = {};
		auto length = GetWindowTextA(objectWindowSearchControl, buffer, 32);

		// Transform the search text to lowercase and clear stray characters.
		std::string newText(buffer, length);
		string::to_lower(newText);

		if (!string::equal(currentSearchText, newText)) {
			currentSearchText = std::move(newText);

			// Regex crunching can be slow, so only do it once.
			if (settings.object_window.use_regex) {
				auto flags = std::regex_constants::extended | std::regex_constants::optimize | std::regex_constants::nosubs;
				if (!settings.object_window.case_sensitive) {
					flags |= std::regex_constants::icase;
				}

				try {
					currentSearchRegex = std::regex(currentSearchText, flags);
				}
				catch (const std::regex_error& e) {
					log::stream << "Regex error when searching object window: " << e.what() << std::endl;
					currentSearchRegex = {};

					// TODO: Paint the background of the search input red or something.
				}
			}
			else {
				currentSearchRegex = {};
			}

			// Fire a refresh function. But disable drawing throughout so we don't get ugly flashes.
			const auto listView = ghWndObjectList::get();
			SendMessageA(listView, WM_SETREDRAW, FALSE, NULL);
			SendMessageA(hWnd, 1043, 0, 0);
			SendMessageA(listView, WM_SETREDRAW, TRUE, NULL);
			RedrawWindow(listView, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
		}
	}

	inline void PatchDialogProc_BeforeCommand(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		const auto command = HIWORD(wParam);
		const auto id = LOWORD(wParam);
		switch (command) {
		case EN_CHANGE:
			switch (id) {
			case CONTROL_ID_FILTER_EDIT:
				OnFilterEditChanged(hWnd);
				break;
			}
			break;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		forcedReturnType = {};

		// Handle pre-patches.
		switch (msg) {
		case WM_DESTROY:
			objectWindowSearchControl = NULL;
			break;
		case WM_SIZE:
			PatchDialogProc_BeforeSize(hWnd, msg, wParam, lParam);
			return FALSE;
		case WM_NOTIFY:
			PatchDialogProc_BeforeNotify(hWnd, msg, wParam, lParam);
			break;
		case WM_COMMAND:
			PatchDialogProc_BeforeCommand(hWnd, msg, wParam, lParam);
			break;
		}

		if (forcedReturnType) {
			return forcedReturnType.value();
		}

		// Call original function.
		const auto CS_ObjectWindowDialogProc = reinterpret_cast<WNDPROC>(0x451320);
		auto result = CS_ObjectWindowDialogProc(hWnd, msg, wParam, lParam);

		// Handle post-patches.
		switch (msg) {
		case WM_INITDIALOG:
			PatchDialogProc_AfterCreate(hWnd, msg, wParam, lParam);
			break;
		}

		return result;
	}
	
	//
	// Main patching function.
	//

	void installPatches() {
		using memory::genCallEnforced;
		using memory::genJumpEnforced;
		using memory::writeDoubleWordEnforced;
		using memory::writeValueEnforced;

		// Patch: Optimize displaying of objects dialog tabs.
		genCallEnforced(0x43C1B4, 0x401E29, reinterpret_cast<DWORD>(PatchSpeedUpObjectWindow_PauseRedraws));
		genCallEnforced(0x43C1CC, 0x403D8C, reinterpret_cast<DWORD>(PatchSpeedUpObjectWindow_ResumeRedraws));

		// Patch: Add modified column.
		{
			constexpr DWORD existingNamesAddress = 0x6944B0;
			constexpr DWORD existingWidthsAddress = 0x694430;

			// Copy over vanilla column values.
			memcpy_s(columnNames, sizeof(columnNames), (void*)existingNamesAddress, sizeof(const char*) * ColumnNames::COLUMN_COUNT_VANILLA);
			memcpy_s(columnWidths, sizeof(columnWidths), (void*)existingWidthsAddress, sizeof(WORD) * ColumnNames::COLUMN_COUNT_VANILLA);

			// Add new column data values.
			columnNames[ColumnNames::MODIFIED] = "Modified";
			columnWidths[ColumnNames::MODIFIED] = 45;

			// Replace references to the vanilla column name list with references to our new one.
			writeDoubleWordEnforced(0x4427CD + 0x1, existingNamesAddress, DWORD(&columnNames));
			writeDoubleWordEnforced(0x451AFD + 0x1, existingNamesAddress, DWORD(&columnNames));

			// Fixup after-data checks.
			const DWORD addressAfterList = DWORD(&columnNames) + sizeof(columnNames);
			writeDoubleWordEnforced(0x442809 + 0x2, 0x6945B0, addressAfterList);
			writeDoubleWordEnforced(0x451B3C + 0x2, 0x6945B0, addressAfterList);

			// Fixup writing of column widths.
			writeDoubleWordEnforced(0x442818 + 0x4, existingWidthsAddress, DWORD(&columnWidths));

			// Fixup looping based on vanilla column count.
			writeValueEnforced(0x451B46 + 0x2, ColumnNames::COLUMN_COUNT_VANILLA, ColumnNames::COLUMN_COUNT);

			// Add the column when building the list.
			genCallEnforced(0x4411E1, 0x403D4B, reinterpret_cast<DWORD>(PatchAddModifiedColumn));

			// Add a custom sort handler.
			genJumpEnforced(0x403AF8, 0x43ED10, reinterpret_cast<DWORD>(PatchAddModifiedColumn_Sorter));

			// Extend the info display for the list.
			genCallEnforced(0x451A83, 0x402B3A, reinterpret_cast<DWORD>(PatchAddModifiedColumn_GetDisplayInfo));
		}

		// Patch: Extend Object Window message handling.
		genJumpEnforced(0x402FD1, 0x451320, reinterpret_cast<DWORD>(PatchDialogProc));

		// Patch: Allow filtering of object window.
		genJumpEnforced(0x401F0F, 0x43C260, reinterpret_cast<DWORD>(PatchFilterObjectWindow));
	}
}
