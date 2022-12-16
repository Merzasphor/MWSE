#include "DialogSearchAndReplaceWindow.h"

#include "MemoryUtil.h"
#include "LogUtil.h"

namespace se::cs::dialog::search_and_replace_window {
	using namespace memory;

	constexpr auto ENABLE_ALL_OPTIMIZATIONS = true;
	constexpr auto LOG_PERFORMANCE_RESULTS = false;

	auto initializationTimer = std::chrono::high_resolution_clock::now();

	inline void PatchDialogProc_BeforeInitialize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		if constexpr (LOG_PERFORMANCE_RESULTS) {
			initializationTimer = std::chrono::high_resolution_clock::now();
		}

		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_SEARCH_FOR_COMBO), WM_SETREDRAW, FALSE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_REPLACE_WITH_COMBO), WM_SETREDRAW, FALSE, NULL);
		}
	}

	inline void PatchDialogProc_AfterInitialize(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		if constexpr (ENABLE_ALL_OPTIMIZATIONS) {
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_SEARCH_FOR_COMBO), WM_SETREDRAW, TRUE, NULL);
			SendMessageA(GetDlgItem(hWnd, CONTROL_ID_REPLACE_WITH_COMBO), WM_SETREDRAW, TRUE, NULL);
		}

		if constexpr (LOG_PERFORMANCE_RESULTS) {
			auto timeToInitialize = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - initializationTimer);
			log::stream << "Total search & replace window initialization time: " << timeToInitialize.count() << "ms" << std::endl;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		bool blockNormalExecution = false;

		// Handle pre-patches.
		switch (msg) {
		case WM_INITDIALOG:
			PatchDialogProc_BeforeInitialize(hWnd, msg, wParam, lParam);
			break;
		}

		if (blockNormalExecution) {
			return TRUE;
		}

		// Call original function.
		const auto CS_SearchAndReplaceDialogProc = reinterpret_cast<WNDPROC>(0x438CE0);
		auto result = CS_SearchAndReplaceDialogProc(hWnd, msg, wParam, lParam);

		// Handle post-patches.
		switch (msg) {
		case WM_INITDIALOG:
			PatchDialogProc_AfterInitialize(hWnd, msg, wParam, lParam);
			break;
		}

		return result;
	}

	void installPatches() {
		// Patch: Extend Object Window message handling.
		genJumpEnforced(0x4024D7, 0x438CE0, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}
