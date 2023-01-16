#include "DialogTextSearchWindow.h"

#include "CSDialogue.h"
#include "CSDialogueInfo.h"

#include "MemoryUtil.h"
#include "WinUIUtil.h"

#include "WindowMain.h"

#include "DialogDialogueWindow.h"

namespace se::cs::dialog::text_search_window {
	struct DialogueResult {
		Dialogue* dialogue; // 0x0
		NI::IteratedList<DialogueInfo*> info; // 0x4
	};

	bool PatchDialogProc_preventMainHandler = false;

	void PatchDialogProc_OnNotify_DoubleClick_ObjectResult(HWND hWnd, UINT msg, WPARAM wParam, LPNMITEMACTIVATE lParam) {
		using namespace se::cs::winui;

		const auto object = (BaseObject*)ListView_GetItemData(lParam->hdr.hwndFrom, lParam->iItem, lParam->iSubItem);

		window::main::showObjectEditWindow(object);
	}

	void PatchDialogProc_OnNotify_DoubleClick_DialogueResult(HWND hWnd, UINT msg, WPARAM wParam, LPNMITEMACTIVATE lParam) {
		using namespace se::cs::winui;

		const auto result = (DialogueResult*)ListView_GetItemData(lParam->hdr.hwndFrom, lParam->iItem, lParam->iSubItem);
		auto object = result->dialogue;

		dialog::dialogue_window::createOrFocus();
		dialog::dialogue_window::focusDialogue(object);
	}

	void PatchDialogProc_OnNotify_DoubleClick_DialogueInfoResult(HWND hWnd, UINT msg, WPARAM wParam, LPNMITEMACTIVATE lParam) {
		using namespace se::cs::winui;

		const auto object = (DialogueInfo*)ListView_GetItemData(lParam->hdr.hwndFrom, lParam->iItem, lParam->iSubItem);

		dialog::dialogue_window::createOrFocus();
		dialog::dialogue_window::focusDialogue(object->getDialogue(), object);
	}

	void PatchDialogProc_OnNotify_DoubleClick(HWND hWnd, UINT msg, WPARAM wParam, LPNMHDR lParam) {
		auto itemActivate = (LPNMITEMACTIVATE)lParam;
		switch (lParam->idFrom) {
		case CONTROL_ID_OBJECT_RESULTS_LIST:
			PatchDialogProc_OnNotify_DoubleClick_ObjectResult(hWnd, msg, wParam, itemActivate);
			break;
		case CONTROL_ID_TOPIC_RESULTS_LIST:
			PatchDialogProc_OnNotify_DoubleClick_DialogueResult(hWnd, msg, wParam, itemActivate);
			break;
		case CONTROL_ID_INFO_RESULTS_LIST:
			PatchDialogProc_OnNotify_DoubleClick_DialogueInfoResult(hWnd, msg, wParam, itemActivate);
			break;
		}
	}

	void PatchDialogProc_OnNotify(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		const auto hdr = (LPNMHDR)lParam;

		switch (hdr->code) {
		case NM_DBLCLK:
			PatchDialogProc_OnNotify_DoubleClick(hWnd, msg, wParam, hdr);
			break;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		PatchDialogProc_preventMainHandler = false;

		switch (msg) {
		case WM_NOTIFY:
			PatchDialogProc_OnNotify(hWnd, msg, wParam, lParam);
			break;
		}

		if (PatchDialogProc_preventMainHandler) {
			return TRUE;
		}

		// Call original function.
		const auto CS_RenderWindowDialogProc = reinterpret_cast<WNDPROC>(0x438610);
		auto result = CS_RenderWindowDialogProc(hWnd, msg, wParam, lParam);

		return result;
	}

	void installPatches() {
		using namespace se::memory;

		// Patch: Extend Render Window message handling.
		genJumpEnforced(0x4046C9, 0x438610, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}