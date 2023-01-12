#include "WinUIUtil.h"

namespace se::cs::winui {

	//
	// ComboBox
	//

	void ComboBox_SetCurSelEx(HWND hWnd, int index) {
		ComboBox_SetCurSel(hWnd, index);
		SendMessageA(GetAncestor(hWnd, GA_PARENT), WM_COMMAND, MAKEWPARAM(GetWindowLongPtr(hWnd, GWLP_ID), CBN_SELCHANGE), (LPARAM)hWnd);
	}

	//
	// ListView
	//

	int ListView_FindItemByParam(HWND hWnd, LPARAM lParam) {
		LVFINDINFOA findInfo = {};
		findInfo.flags = LVFI_PARAM;
		findInfo.lParam = lParam;
		return ListView_FindItem(hWnd, -1, &findInfo);
	}

	LPARAM ListView_GetItemData(HWND hWnd, int item, int subItem) {
		LV_ITEM lv_item = {};
		lv_item.mask = LVIF_PARAM;
		lv_item.iItem = item;
		lv_item.iSubItem = subItem;
		ListView_GetItem(hWnd, &lv_item);

		return lv_item.lParam;
	}

	bool ListView_SelectByParam(HWND hWnd, LPARAM lParam, bool ensureVisible) {
		const int index = ListView_FindItemByParam(hWnd, lParam);
		if (index == -1) {
			return false;
		}

		ListView_SetItemState(hWnd, index, LVIS_SELECTED, LVIS_SELECTED);

		if (ensureVisible) {
			ListView_EnsureVisible(hWnd, index, FALSE);
		}

		return true;
	}

	//
	// TabView
	//

	void TabCtrl_SetCurSelEx(HWND hWnd, int index) {
		auto hParent = GetAncestor(hWnd, GA_PARENT);

		NMHDR nmhdr = {};
		nmhdr.hwndFrom = hWnd;
		nmhdr.idFrom = GetDlgCtrlID(hWnd);

		nmhdr.code = TCN_SELCHANGING;
		if (SendMessageA(hParent, WM_NOTIFY, (WPARAM)hWnd, (LPARAM)&nmhdr) == FALSE) {
			TabCtrl_SetCurSel(hWnd, index);

			const int foo = TCN_SELCHANGE;
			nmhdr.code = TCN_SELCHANGE;
			SendMessageA(hParent, WM_NOTIFY, (WPARAM)hWnd, (LPARAM)&nmhdr);
		}
	}
}
