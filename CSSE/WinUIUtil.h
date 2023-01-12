#pragma once

namespace se::cs::winui {

	//
	// ComboBox
	//

	// Sets the current selection index as ComboBox_SetCurSel, with additional messaging.
	void ComboBox_SetCurSelEx(HWND hWnd, int index);

	//
	// ListView
	//

	// Provides the index of the row that contains the given LPARAM value.
	int ListView_FindItemByParam(HWND hWnd, LPARAM lParam);

	// Gets the LPARAM of a given item/subitem from a list.
	LPARAM ListView_GetItemData(HWND hWnd, int item, int subItem);

	// Selects a row by a given LPARAM, and optionally ensures it is visible.
	bool ListView_SelectByParam(HWND hWnd, LPARAM lParam, bool ensureVisible = true);

	//
	// TabView
	//

	// Sets the current selection index as TabCtrl_SetCurSel, with additional messaging.
	// This can be blocked if the changing notification returns TRUE.
	void TabCtrl_SetCurSelEx(HWND hWnd, int index);

}
