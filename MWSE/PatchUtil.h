#pragma once

namespace mwse::patch {
	void installPatches();
	void installPostLuaPatches();

	bool installMiniDumpHook();
}
