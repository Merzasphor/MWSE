#include "WindowMain.h"

#include "LogUtil.h"
#include "MemoryUtil.h"
#include "WinUIUtil.h"

#include "Settings.h"

#include "CSBaseObject.h"
#include "CSDataHandler.h"
#include "CSGameFile.h"
#include "CSGameSetting.h"
#include "CSRecordHandler.h"
#include "CSScript.h"

#include "NICamera.h"
#include "NIVector3.h"

#include "DialogRenderWindow.h"
#include "DialogObjectWindow.h"

namespace se::cs::window::main {

	struct ObjectEditLParam {
		ObjectType::ObjectType objectType; // 0x0
		BaseObject* object; // 0x4
		int unknown_0x8;
		int unknown_0xC;
	};

	HWND showComboBasedEditWindow(const BaseObject* object, HWND hWnd, LPCSTR lpTemplateName, DLGPROC dlgProc, int comboBoxId) {
		// Create new window if needed.
		if (hWnd == NULL) {
			hWnd = CreateDialogParamA(hInstance::get(), lpTemplateName, ghWnd::get(), dlgProc, 0);
			if (hWnd == NULL) {
				return NULL;
			}
		}
		// Show existing window.
		else if (GetActiveWindow() != hWnd) {
			SetActiveWindow(hWnd);
		}

		// Select the searched for object.
		const auto hDlgCombo = GetDlgItem(hWnd, comboBoxId);
		const auto count = ComboBox_GetCount(hDlgCombo);
		for (auto i = 0; i < count; ++i) {
			const auto birthsign = (BaseObject*)ComboBox_GetItemData(hDlgCombo, i);
			if (birthsign == object) {
				winui::ComboBox_SetCurSelEx(hDlgCombo, i);
				break;
			}
		}

		return hWnd;
	}

	HWND showBirthsignEditWindow(BaseObject* object) {
		using ghWndDialogBirthsigns = memory::ExternalGlobal<HWND, 0x6CE9A0>;
		return showComboBasedEditWindow(object, ghWndDialogBirthsigns::get(), (LPCSTR)0xDF, (DLGPROC)0x402EA5, 1028);
	}

	HWND showClassEditWindow(BaseObject* object) {
		using ghWndDialogClasses = memory::ExternalGlobal<HWND, 0x6CE97C>;
		return showComboBasedEditWindow(object, ghWndDialogClasses::get(), (LPCSTR)0xA0, (DLGPROC)0x402036, 1158);
	}

	HWND showFactionEditWindow(BaseObject* object) {
		return showComboBasedEditWindow(object, NULL, (LPCSTR)0x9D, (DLGPROC)0x4034E5, 1168);
	}

	HWND showRaceEditWindow(BaseObject* object) {
		using ghWndDialogRaces = memory::ExternalGlobal<HWND, 0x6CE978>;
		return showComboBasedEditWindow(object, ghWndDialogRaces::get(), (LPCSTR)0x9F, (DLGPROC)0x403BFC, 1083);
	}

	struct ScriptWindowUserData {
		int unknown_0x0;
		int unknown_0x4;
		int unknown_0x8;
		int unknown_0xC;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		Script* script;
		Script* toOpenScript;
		bool unknown_0x28;
		bool unknown_0x29;
		HMENU hMenu; // 0x2C
		HWND hRichTextEdit; // 0x30
		HWND hStatusWindow; // 0x34
		HWND hToolbar; // 0x38
		HWND hCallingDialog; // 0x38
		int lineFromChar;
		int lineCount;
		bool blockProcEvents;
	};
	static_assert(sizeof(ScriptWindowUserData) == 0x4C, "ScriptWindowUserData failed size validation");

	HWND showScriptEditWindow(BaseObject* object) {
		auto hWnd = CreateDialogParamA(hInstance::get(), (LPCSTR)0xBC, ghWnd::get(), (DLGPROC)0x4015F5, 0);
		auto userData = (ScriptWindowUserData*)GetWindowLongA(hWnd, GWL_USERDATA);

		// Set the current script.
		auto script = static_cast<Script*>(object);
		userData->script = script;

		// Load the text.
		SetWindowTextA(userData->hRichTextEdit, script->text);

		// Set the window title.
		char buffer[64] = {};
		if (script->getModified()) {
			sprintf_s(buffer, "Script Edit - [%s *]", script->getObjectID());
		}
		else {
			sprintf_s(buffer, "Script Edit - [%s]", script->getObjectID());
		}
		SetWindowTextA(hWnd, buffer);

		if (script->getDeleted()) {
			ShowWindow(userData->hRichTextEdit, 5);
			EnableWindow(userData->hRichTextEdit, FALSE);
		}
		else {
			EnableWindow(userData->hRichTextEdit, TRUE);
		}

		SendMessageA(userData->hRichTextEdit, EM_SETMODIFY, 0, 0);
		userData->unknown_0x29 = false;

		return hWnd;
	}

	HWND showDefaultObjectEditWindow(BaseObject* object) {
		ObjectEditLParam lParam = {};
		lParam.objectType = object->objectType;
		lParam.object = object;

		DLGPROC proc = (DLGPROC)0x402F9A;
		switch (object->objectType) {
		case ObjectType::Alchemy:
			proc = (DLGPROC)0x4035BC;
			break;
		case ObjectType::Creature:
			proc = (DLGPROC)0x40132F;
			break;
		case ObjectType::Enchantment:
			proc = (DLGPROC)0x404912;
			break;
		case ObjectType::LeveledCreature:
			proc = (DLGPROC)0x402C3E;
			break;
		case ObjectType::LeveledItem:
			proc = (DLGPROC)0x401D66;
			break;
		case ObjectType::NPC:
			proc = (DLGPROC)0x40313E;
			break;
		case ObjectType::Spell:
			proc = (DLGPROC)0x401299;
			break;
		}

		auto tab = dialog::object_window::getTabForObjectType(object->objectType);
		if (tab == -1) {
			return NULL;
		}

		const auto objectWinTypeForTab = (LPCSTR*)0x69460C;

		return CreateDialogParamA(hInstance::get(), objectWinTypeForTab[tab], ghWnd::get(), proc, LPARAM(&lParam));
	}

	HWND showObjectEditWindow(BaseObject* object) {
		switch (object->objectType) {
		case ObjectType::Birthsign:
			return showBirthsignEditWindow(object);
		case ObjectType::Class:
			return showClassEditWindow(object);
		case ObjectType::Faction:
			return showFactionEditWindow(object);
		case ObjectType::GameSetting:
			return NULL;
		case ObjectType::Race:
			return showRaceEditWindow(object);
		case ObjectType::Script:
			return showScriptEditWindow(object);
		default:
			return showDefaultObjectEditWindow(object);
		}
	}

	//
	// Patch: Throttle UI status updates.
	//

	static auto last2ndClassUpdateTime = std::chrono::milliseconds::zero();
	const auto TES3CS_UpdateStatusMessage = reinterpret_cast<void(__cdecl*)(WPARAM, LPARAM)>(0x46E680);
	void __cdecl PatchThrottleMessageUpdate(WPARAM type, LPARAM lParam) {
		if (type == 2) {
			const auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
			const auto msSinceLastUpdate = now - last2ndClassUpdateTime;
			if (msSinceLastUpdate.count() < 20) {
				return;
			}
			last2ndClassUpdateTime = now;
		}
		else {
			last2ndClassUpdateTime = std::chrono::milliseconds::zero();
		}
		TES3CS_UpdateStatusMessage(type, lParam);
	}

	//
	// Patch: Enable QuickStart cell loading.
	//

	bool isQuickStarting = false;

	bool __cdecl PatchEnableQuickStartCellLoading(bool a1) {
		const auto existingFunction = reinterpret_cast<bool(__cdecl*)(bool)>(0x4033FF);
		auto result = existingFunction(a1);

		if (!isQuickStarting) {
			return result;
		}

		auto dataHandler = DataHandler::get();
		auto renderController = dialog::render_window::RenderController::get();

		// Check to see if we're loading a cell.
		if (settings.quickstart.load_cell) {
			// Load position from settings. We need to shift down by 16,384 units because of the weird offset in the function.
			const auto& qsPos = settings.quickstart.position;
			NI::Vector3 position(qsPos[0], qsPos[1], qsPos[2]);
			position.z -= 16384.0f;

			// Setup a specific interior cell if needed.
			const auto& cellID = settings.quickstart.cell;
			if (!cellID.empty()) {
				auto cell = dataHandler->recordHandler->getCellByID(cellID.c_str());
				if (cell == nullptr) {
					return result;
				}

				const auto setToLoadCell = reinterpret_cast<bool(__thiscall*)(DataHandler*, Cell*, NI::Vector3*)>(0x4A1370);
				setToLoadCell(dataHandler, cell, &position);
			}

			// Actually do our load.
			const auto loadCell = reinterpret_cast<bool(__cdecl*)(NI::Vector3*, Reference*)>(0x469B40);
			loadCell(&position, nullptr);

			// Setup camera.
			const auto& qsRot = settings.quickstart.orientation;
			NI::Matrix33 rotationMatrix;
			rotationMatrix.fromEulerXYZ(qsRot[0], qsRot[1], qsRot[2]);
			renderController->node->setLocalRotationMatrix(&rotationMatrix);
			renderController->node->update();
		}

		isQuickStarting = false;

		return result;
	}

	//
	// Patch: Extend window messages.
	//

	bool blockNormalExecution = false;

	void onFinishInitialization(LPARAM& lParam) {
		// Skip any QuickStart usage if we were given a file to load.
		char* commandLineFile = (char*)0x6CE6CC;
		if (*commandLineFile != '\0') {
			return;
		}

		// We can also skip if the enabled 
		if (!settings.quickstart.enabled || settings.quickstart.data_files.empty()) {
			return;
		}

		auto dataHandler = DataHandler::get();
		auto recordHandler = dataHandler->recordHandler;

		std::unordered_set<std::string> toLoadSet;
		for (const auto& master : settings.quickstart.data_files) {
			toLoadSet.insert(master);
		}

		// Flag any game files as marked to load.
		for (auto itt = recordHandler->availableDataFiles->head; itt; itt = itt->next) {
			auto gameFile = itt->data;
			if (toLoadSet.find(gameFile->fileName) != toLoadSet.end()) {
				gameFile->setToLoadFlag(true);
			}
		}

		std::string mainFileToLoad = settings.quickstart.active_file;
		if (mainFileToLoad.empty()) {
			mainFileToLoad = settings.quickstart.data_files.back();
		}
		strncpy_s(commandLineFile, 0x224, mainFileToLoad.c_str(), mainFileToLoad.length());

		isQuickStarting = true;
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		blockNormalExecution = false;

		// Handle pre-patches.
		switch (msg) {
		case CUSTOM_WM_FINISH_INITIALIZATION:
			onFinishInitialization(lParam);
			break;
		}

		if (blockNormalExecution) {
			return TRUE;
		}

		// Call original function.
		const auto CS_MainWindowDialogProc = reinterpret_cast<WNDPROC>(0x444590);
		auto result = CS_MainWindowDialogProc(hWnd, msg, wParam, lParam);

		return result;
	}

	void installPatches() {
		using memory::genJumpEnforced;
		using memory::genCallEnforced;

		// Patch: Throttle UI status updates.
		genJumpEnforced(0x404881, 0x46E680, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));

		// Patch: Enable QuickStart cell loading.
		genCallEnforced(0x447B78, 0x4033FF, reinterpret_cast<DWORD>(PatchEnableQuickStartCellLoading));

		// Patch: Extend window messages.
		genJumpEnforced(0x401EF1, 0x444590, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}