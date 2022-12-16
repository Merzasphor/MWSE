#pragma once

namespace se::cs::dialog::search_and_replace_window {
	constexpr UINT DIALOG_ID = 198;

	// Default IDs.
	constexpr UINT CONTROL_ID_SEARCH_FOR_COMBO = 1439;
	constexpr UINT CONTROL_ID_REPLACE_WITH_COMBO = 1440;

	void installPatches();
}