#include "DialogDialogueWindow.h"

#include "MemoryUtil.h"

#include "CSDataHandler.h"
#include "CSDialogue.h"
#include "CSDialogueInfo.h"
#include "CSObject.h"
#include "CSRecordHandler.h"
#include "CSScript.h"

#include "LogUtil.h"
#include "StringUtil.h"

namespace se::cs::dialog::dialogue_window {
	using namespace se::memory;

	constexpr auto ENABLE_ALL_OPTIMIZATIONS = true;
	constexpr auto LOG_PERFORMANCE_RESULTS = false;

	void addDialogStyle(HWND hWnd, DWORD style) {
		SetWindowLongA(hWnd, GWL_STYLE, GetWindowLongA(hWnd, GWL_STYLE) | style);
	}

	void removeDialogStyle(HWND hWnd, DWORD style) {
		SetWindowLongA(hWnd, GWL_STYLE, GetWindowLongA(hWnd, GWL_STYLE) & ~style);
	}

	void resumeRenderingAndRepaint(HWND parent, DWORD childId) {
		auto child = GetDlgItem(parent, childId);
		SendMessageA(child, WM_SETREDRAW, TRUE, NULL);
		RedrawWindow(child, NULL, NULL, RDW_ERASE | RDW_FRAME | RDW_INVALIDATE | RDW_ALLCHILDREN);
	}

	//
	// Patch: Optimize cell string find/insertion.
	//

	std::unordered_set<std::string> insertedCells;

	LRESULT CALLBACK PatchOptimizeCellInsertion(HWND hWnd, UINT msg, WPARAM wParam, BaseObject* object) {
		std::string lowercased = object->getObjectID();
		string::to_lower(lowercased);

		if (insertedCells.find(lowercased) == insertedCells.end()) {
			auto r = SendMessageA(hWnd, CB_ADDSTRING, NULL, (LPARAM)object->getObjectID());
			SendMessageA(hWnd, CB_SETITEMDATA, r, (LPARAM)object);
			insertedCells.insert(std::move(lowercased));
			return -1;
		}
		return 1;
	}

	//
	// Patch: Optimize displaying of INFO info.
	//

	static std::unordered_set<std::string> allRelevantLocals;

	void populateCollectionsForInfo(const DialogueInfo* info) {
		// Clear existing data.
		allRelevantLocals.clear();

		for (auto script : *DataHandler::get()->recordHandler->scripts) {
			for (auto i = 0; i < script->header.numShorts; ++i) {
				auto name = script->getShortVarName(i);
				if (name) {
					allRelevantLocals.insert(name);
				}
			}
			for (auto i = 0; i < script->header.numLongs; ++i) {
				auto name = script->getLongVarName(i);
				if (name) {
					allRelevantLocals.insert(name);
				}
			}
			for (auto i = 0; i < script->header.numFloats; ++i) {
				auto name = script->getFloatVarName(i);
				if (name) {
					allRelevantLocals.insert(name);
				}
			}
		}
	}

	int __fastcall PatchOptimizePopulatingLocalVariableNames(HWND hWnd, int nIDDlgItem) {
		for (const auto& local : allRelevantLocals) {
			auto index = SendDlgItemMessageA(hWnd, nIDDlgItem, CB_ADDSTRING, 0, (LPARAM)local.c_str());
			SendDlgItemMessageA(hWnd, nIDDlgItem, CB_SETITEMDATA, index, 108);
		}

		// TODO: Handle GetTextExtentPoint32A

		return 0;
	}

	__declspec(naked) void PatchOptimizePopulatingLocalVariableNames_Setup() {
		__asm {
			mov ecx, ebp					// Size: 0x2
			mov edx, ebx					// Size: 0x2
			nop								// Size: 0x5
			nop
			nop
			nop
			nop
			cmp eax, [esp + 0x24 - 0x14]	// Size: 0x4
			jle $+0xA						// Size: 0x6
			mov [esp + 0x24 - 0x14], eax	// Size: 0x4
		}
	}
	constexpr auto PatchOptimizePopulatingLocalVariableNames_Setup_Size = 0x17u;

	static DialogueInfo* lastShownDialogueInfo = nullptr;

	void __fastcall PatchOptimizeDialogueInfoDisplaying(DialogueInfo* info, DWORD _edx_, HWND hWnd) {
		std::chrono::high_resolution_clock::time_point initializationTimer;
		if constexpr (LOG_PERFORMANCE_RESULTS) {
			initializationTimer = std::chrono::high_resolution_clock::now();
		}

		if (info == lastShownDialogueInfo) {
			if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
				return;
			}
		}

		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION1_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION1_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION1_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION1_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION2_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION2_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION2_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION2_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION3_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION3_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION3_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION3_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION4_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION4_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION4_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION4_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION5_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION5_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION5_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION5_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION6_TYPE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION6_VARIABLE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION6_CONDITION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FUNCTION6_VALUE_EDIT), WM_SETREDRAW, FALSE, NULL);

			// Gather what data we need to populate lists.
			populateCollectionsForInfo(info);
		}

		const auto CS_DialogueInfo_displayToEditor = reinterpret_cast<void(__thiscall*)(DialogueInfo*, HWND)>(0x4F1070);
		CS_DialogueInfo_displayToEditor(info, hWnd);
		lastShownDialogueInfo = info;

		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION1_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION1_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION1_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION1_VALUE_EDIT);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION2_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION2_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION2_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION2_VALUE_EDIT);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION3_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION3_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION3_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION3_VALUE_EDIT);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION4_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION4_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION4_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION4_VALUE_EDIT);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION5_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION5_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION5_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION5_VALUE_EDIT);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION6_TYPE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION6_VARIABLE_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION6_CONDITION_COMBO);
			resumeRenderingAndRepaint(hWnd, CONTROL_ID_CONDITION_FUNCTION6_VALUE_EDIT);
		}

		if constexpr (LOG_PERFORMANCE_RESULTS) {
			auto windowData = (DialogueWindowData*)GetWindowLongA(hWnd, GWL_USERDATA);
			auto timeToInitialize = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - initializationTimer);
			log::stream << "Displaying INFO " << windowData->currentDialogue->id << "/" << info->loadLinkNodes->name << " took " << timeToInitialize.count() << "ms" << std::endl;
		}
	}

	//
	// Patch: Extend Render Window message handling.
	//

	auto initializationTimer = std::chrono::high_resolution_clock::now();

	inline void PatchDialogProc_BeforeInitialize(HWND hWnd) {
		if constexpr (LOG_PERFORMANCE_RESULTS) {
			initializationTimer = std::chrono::high_resolution_clock::now();
		}

		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_UPDATE_FILTER_FOR_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_TOPIC_LIST), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_INFO_LIST), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_ID_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_RACE_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_CLASS_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FACTION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_RANK_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_CELL_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_PCFACTION_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_PCRANK_COMBO), WM_SETREDRAW, FALSE, NULL);
		}
	}

	inline void PatchDialogProc_AfterInitialize(HWND hWnd) {
		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_UPDATE_FILTER_FOR_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_TOPIC_LIST), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_INFO_LIST), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_ID_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_RACE_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_CLASS_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_FACTION_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_RANK_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_CELL_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_PCFACTION_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_CONDITION_PCRANK_COMBO), WM_SETREDRAW, TRUE, NULL);

			insertedCells.clear();
		}

		if constexpr (LOG_PERFORMANCE_RESULTS) {
			auto timeToInitialize = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - initializationTimer);
			log::stream << "Total dialogue window initialization time: " << timeToInitialize.count() << "ms" << std::endl;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_INITDIALOG:
			PatchDialogProc_BeforeInitialize(hWnd);
			break;
		}

		// Call original function.
		const auto CS_RenderWindowDialogProc = reinterpret_cast<WNDPROC>(0x4EAEA0);
		auto result = CS_RenderWindowDialogProc(hWnd, msg, wParam, lParam);

		switch (msg) {
		case WM_INITDIALOG:
			PatchDialogProc_AfterInitialize(hWnd);
			break;
		}

		return result;
	}

	void installPatches() {
		// Patch: Optimize insertion of cell names.
		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			genNOPUnprotected(0x4EC686, 0x4EC68D - 0x4EC686);
			genCallUnprotected(0x4EC69A, reinterpret_cast<DWORD>(PatchOptimizeCellInsertion), 0x4EC6C5 - 0x4EC69A);
		}
		
		// Patch: Optimize displaying of INFO info.
		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			genNOPUnprotected(0x4E7D5A, 0x4E7F59 - 0x4E7D5A);
			writePatchCodeUnprotected(0x4E7D5A, (BYTE*)PatchOptimizePopulatingLocalVariableNames_Setup, PatchOptimizePopulatingLocalVariableNames_Setup_Size);
			genCallUnprotected(0x4E7D5A + 0x4, reinterpret_cast<DWORD>(PatchOptimizePopulatingLocalVariableNames));
		}
		genJumpEnforced(0x4040BB, 0x4F1070, reinterpret_cast<DWORD>(PatchOptimizeDialogueInfoDisplaying));

		// Patch: Extend Render Window message handling.
		genJumpEnforced(0x401334, 0x4EAEA0, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}
