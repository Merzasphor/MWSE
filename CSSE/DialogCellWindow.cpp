#include "DialogCellWindow.h"

#include "MemoryUtil.h"

namespace se::cs::dialog::cell_window {
	using namespace se::memory;

	void __cdecl PatchSpeedUpCellViewDialog(HWND hWnd) {
		SendMessageA(hWnd, WM_SETREDRAW, FALSE, NULL);

		const auto originalFunction = reinterpret_cast<void(__cdecl*)(HWND)>(0x40E250);
		originalFunction(hWnd);

		SendMessageA(hWnd, WM_SETREDRAW, TRUE, NULL);
	}

	void installPatches() {
		// Patch: Optimize displaying of cell view window.
		genJumpEnforced(0x4037C4, 0x40E250, reinterpret_cast<DWORD>(PatchSpeedUpCellViewDialog));
	}
}
