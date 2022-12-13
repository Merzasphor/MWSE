#pragma once

namespace se::cs::dialog::object_window {
	constexpr UINT DIALOG_ID = 122;

	// Default IDs.
	constexpr UINT CONTROL_ID_LIST_VIEW = 1041;
	constexpr UINT CONTROL_ID_TABS = 1042;

	// Custom IDs.
	constexpr UINT CONTROL_ID_FILTER_LABEL = 2000;
	constexpr UINT CONTROL_ID_FILTER_EDIT = 2001;

	void installPatches();
}
