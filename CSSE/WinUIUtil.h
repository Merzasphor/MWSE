#pragma once

namespace se::cs::winui {

	//
	// Generic extensions
	//

	bool GetIsValidID(int iDlgId);

	HWND GetControlByText(HWND hParent, const std::string_view& text, bool ignoreResultsWithIDs);
	bool SetWindowIdByValue(HWND hParent, const std::string_view text, int newID);

	inline LONG GetRectWidth(const RECT* rect) {
		return rect->right - rect->left;
	}

	inline LONG GetRectHeight(const RECT* rect) {
		return rect->bottom - rect->top;
	}

	void CenterWindow(HWND hWnd);
	void ResizeAndCenterWindow(HWND hWnd, int width, int height);

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

	// Returns the window coordinates that are contained by the tab control.
	void TabCtrl_GetInteriorRect(HWND hWnd, RECT* out_rect);

	// Sets the current selection index as TabCtrl_SetCurSel, with additional messaging.
	// This can be blocked if the changing notification returns TRUE.
	void TabCtrl_SetCurSelEx(HWND hWnd, int index);

}
