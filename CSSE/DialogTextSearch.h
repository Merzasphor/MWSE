#pragma once

namespace se::cs::dialog::text_search_window {

	constexpr UINT DIALOG_ID = 233;

	// Default IDs.
	constexpr UINT CONTROL_ID_INFO_RESULTS_LIST = 1952;
	constexpr UINT CONTROL_ID_OBJECT_RESULTS_LIST = 1018;
	constexpr UINT CONTROL_ID_SEARCH_BUTTON = 1016;
	constexpr UINT CONTROL_ID_SEARCH_EDIT = 1000;
	constexpr UINT CONTROL_ID_SUBTYPE_TITLE_STATIC = 1951;
	constexpr UINT CONTROL_ID_TOPIC_RESULTS_LIST = 1019;
	constexpr UINT CONTROL_ID_TYPE_TABS = 1111;
	constexpr UINT CONTROL_ID_TYPE_TITLE_STATIC = 1950;

	void installPatches();
}