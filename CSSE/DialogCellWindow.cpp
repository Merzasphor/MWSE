#include "DialogCellWindow.h"

#include "CSCell.h"

#include "MemoryUtil.h"
#include "LogUtil.h"

namespace se::cs::dialog::cell_window {
	using gActiveEditCell = memory::ExternalGlobal<Cell*, 0x6CDFF4>;

	void __cdecl PatchSpeedUpCellViewDialog(HWND hWnd) {
		SendMessageA(hWnd, WM_SETREDRAW, FALSE, NULL);

		const auto originalFunction = reinterpret_cast<void(__cdecl*)(HWND)>(0x40E250);
		originalFunction(hWnd);

		SendMessageA(hWnd, WM_SETREDRAW, TRUE, NULL);
	}

	void __cdecl PatchSpeedUpCellObjectViewDialog(HWND hWnd, const ReferenceList* references) {
		if (references == &gActiveEditCell::get()->unknown_0x40) {
			SendMessageA(hWnd, WM_SETREDRAW, FALSE, NULL);
		}

		const auto originalFunction = reinterpret_cast<void(__cdecl*)(HWND, const ReferenceList*)>(0x40E5B0);
		originalFunction(hWnd, references);

		if (references == &gActiveEditCell::get()->unknown_0x30) {
			SendMessageA(hWnd, WM_SETREDRAW, TRUE, NULL);
		}
	}

	bool blockNormalExecution = false;

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		blockNormalExecution = false;

		// Handle pre-patches.
		switch (msg) {

		}

		if (blockNormalExecution) {
			return TRUE;
		}

		// Call original function.
		const auto CS_CellViewDialogProc = reinterpret_cast<WNDPROC>(0x40EFA0);
		auto result = CS_CellViewDialogProc(hWnd, msg, wParam, lParam);

		// Handle post-patches.
		switch (msg) {

		}

		return result;
	}

	void installPatches() {
		using memory::genJumpEnforced;

		// Patch: Optimize displaying of cell view window.
		genJumpEnforced(0x4037C4, 0x40E250, reinterpret_cast<DWORD>(PatchSpeedUpCellViewDialog));

		// Patch: Optimize displaying of cell objects view window.
		genJumpEnforced(0x401442, 0x40E5B0, reinterpret_cast<DWORD>(PatchSpeedUpCellObjectViewDialog));

		// Patch: Extend window messages.
		genJumpEnforced(0x401898, 0x40EFA0, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}
