// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#include <string>

#include "resource.h"

#include "aboutdlg.h"
#include "MainDlg.h"
#include "ModuleVersion.h"

CMainDlg::CMainDlg()
{
}

BOOL CMainDlg::PreTranslateMessage(MSG* pMsg)
{
	return CWindow::IsDialogMessage(pMsg);
}

BOOL CMainDlg::OnIdle()
{
	return FALSE;
}


// WM_CLOSE. The close button on the title bar was clicked.
LRESULT CMainDlg::OnClose(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
    CloseDialog(0);
    return TRUE;
}

// Initialize.
LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// center the dialog on the screen
	CenterWindow();

	// set icons
	HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
	SetIcon(hIcon, TRUE);
	HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	SetIcon(hIconSmall, FALSE);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

    viewButton.Attach(GetDlgItem(IDC_VIEW_LOG));
    launchButton.Attach(GetDlgItem(IDC_LAUNCH));
    exitButton.Attach(GetDlgItem(IDC_EXIT));
    statusMessage.Attach(GetDlgItem(IDC_STATUS));

    UIAddChildWindowContainer(m_hWnd);

    mainThreadId = GetCurrentThreadId();
    DWORD dwThreadID;
    monitorThread = ::CreateThread(NULL, 0, WindowMonitor, this, 0, &dwThreadID);
    char buffer[512];
    int length = GetModuleFileName(NULL, buffer, sizeof buffer);
    std::string version = ModuleVersion::getModuleVersion(buffer).getVersionString();
    std::string message = "MWSE Launcher " + version;
    statusMessage.SetWindowTextA(message.c_str());
	return TRUE;
}

LRESULT CMainDlg::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}

LRESULT CMainDlg::OnLaunch(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    if (loader.LaunchMorrowind()) {
        launchButton.EnableWindow(false);
        statusMessage.SetWindowTextA("Morrowind started.");
    } else {
        MessageBox("Could not start Morrowind", "Error Starting Morrowind", MB_OK|MB_ICONERROR);
    }
	return 0;
}

LRESULT CMainDlg::OnViewLog(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    UINT length = GetSystemDirectory(NULL, 0);
    if (length > 0) {
        char *buffer = reinterpret_cast<char *>(alloca(length + 1));
        GetSystemDirectory(buffer, length+1);   // location of system files, typically C:\\WINDOWS

        std::string notepad = buffer + std::string("\\notepad.exe");
        char currentDir[2048];
        GetCurrentDirectory(sizeof currentDir, currentDir);
        std::string logFile = notepad + " \"" +
            std::string(currentDir) +
            "\\MWSELog.txt\"";

        STARTUPINFO sSi;
        PROCESS_INFORMATION sPi;

        memset(&sSi, 0, sizeof sSi);
        sSi.cb = sizeof(sSi);
        CreateProcess(const_cast<char *>(notepad.c_str()),
                      const_cast<char *>(logFile.c_str()),
                      0,0,false,NORMAL_PRIORITY_CLASS,0,0,&sSi,&sPi);
        CloseHandle(sPi.hProcess);
        CloseHandle(sPi.hThread);
    }
	return 0;
}

LRESULT CMainDlg::OnExit(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    CloseDialog(0);
	return 0;
}

void CMainDlg::CloseDialog(int nVal)
{
    TerminateThread(monitorThread, 0);
	DestroyWindow();
	::PostQuitMessage(nVal);
}

LRESULT CMainDlg::OnNewMorrowindWindow(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
    bool enableLaunch = true;
    if (wParam != 0) {
        if (loader.mInjectDll(reinterpret_cast<HWND>(wParam))) {
            enableLaunch = false;
            std::string message = "MWSE " + loader.getInjectedMWSEVersion() + " loaded in Morrowind " +
                loader.getMorrowindVersion() + ".";
            statusMessage.SetWindowTextA(message.c_str());
        } else {
            MessageBox("Could not inject MWSE into Morrowind", "Error Injecting MWSE", MB_OK|MB_ICONERROR);
        }
    } else {
        statusMessage.SetWindowTextA("Morrowind exited.");
    }
    launchButton.EnableWindow(enableLaunch);
    return TRUE;
}

// This function runs in its own thread. It just spins, looking for
// the Morrowind main window. If it finds it, it posts a message to
// the main dialog window, which does all the work of injecting the
// MWSE DLL.
DWORD CMainDlg::WindowMonitor(void *self)
{
    CMainDlg *me = reinterpret_cast<CMainDlg *>(self);
    HWND oldWindow = 0;
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_IDLE);
    do {
        HWND window = FindWindow("Morrowind", "Morrowind");
        if (window != oldWindow) {
            ::PostMessage(me->m_hWnd, WM_USER+1, reinterpret_cast<WPARAM>(window), 0);
            oldWindow = window;
        }
        Sleep(100); // 100 milliseconds
    } while(true);
}