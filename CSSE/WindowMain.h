#pragma once

#include "CSDefines.h"

#include "MemoryUtil.h"

namespace se::cs::window::main {

	constexpr UINT CUSTOM_WM_FINISH_INITIALIZATION = 0x414;

	// Global variables.
	using hInstance = memory::ExternalGlobal<HINSTANCE, 0x6CE930>;
	using ghWnd = memory::ExternalGlobal<HWND, 0x6CE934>;

	HWND showObjectEditWindow(BaseObject* object);

	void installPatches();
}