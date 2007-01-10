#include"cDllLoaderUi.h"

HDC cDllLoaderUi::vDc=0;
HDC cDllLoaderUi::vDcMem=0;
HBITMAP cDllLoaderUi::vSplashImage=0;
HBITMAP cDllLoaderUi::vSplashImageRec=0;
BITMAP cDllLoaderUi::sBmInfo;
PAINTSTRUCT cDllLoaderUi::sCanvas;
HWND cDllLoaderUi::vRoot;

HWND cDllLoaderUi::vConsoleRoot;
HWND cDllLoaderUi::vConsoleInputScreen;
HDC cDllLoaderUi::vCDc=0;
HDC cDllLoaderUi::vCDcMem=0;
HBITMAP cDllLoaderUi::vConsoleImage=0;
HBITMAP cDllLoaderUi::vConsoleImageRec=0;
BITMAP cDllLoaderUi::sConsoleBmInfo;
PAINTSTRUCT cDllLoaderUi::sConsoleCanvas;
HBRUSH cDllLoaderUi::vConsoleBackground=0;

LRESULT CALLBACK cDllLoaderUi::mLoaderProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_CREATE:
		vSplashImage=LoadBitmap(GetModuleHandle(0),MAKEINTRESOURCE(ID_SPLASHIMAGE));
		if(vSplashImage==0)
			MessageBox(0,"Error, Could not load splash image","MWSE Loader Error",MB_ICONERROR);
		break;
	case WM_PAINT:
		vDc=BeginPaint(vRoot,&sCanvas);

		vDcMem=CreateCompatibleDC(vDc);
		vSplashImageRec=(HBITMAP)SelectObject(vDcMem,vSplashImage);

		GetObject(vSplashImage,sizeof(sBmInfo),&sBmInfo);
		BitBlt(vDc, 0, 0, sBmInfo.bmWidth, sBmInfo.bmHeight, vDcMem, 0, 0, SRCCOPY);

		SelectObject(vDcMem,vSplashImageRec);
		DeleteDC(vDcMem);

		EndPaint(vRoot,&sCanvas);
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

LRESULT CALLBACK cDllLoaderUi::mConsoleProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_CREATE:
		vConsoleImage=LoadBitmap(GetModuleHandle(0),MAKEINTRESOURCE(ID_CONSOLEIMAGE));
		if(vConsoleImage==0)
			MessageBox(0,"Error, Could not load console image","MWSE Loader Error",MB_ICONERROR);
		break;
	case WM_PAINT:
		vCDc=BeginPaint(vConsoleRoot,&sConsoleCanvas);

		vCDcMem=CreateCompatibleDC(vCDc);
		vConsoleImageRec=(HBITMAP)SelectObject(vCDcMem,vConsoleImage);

		GetObject(vConsoleImage,sizeof(sConsoleBmInfo),&sConsoleBmInfo);
		BitBlt(vCDc, 0, 0, sConsoleBmInfo.bmWidth, sConsoleBmInfo.bmHeight, vCDcMem, 0, 0, SRCCOPY);

		SelectObject(vCDcMem,vConsoleImageRec);
		DeleteDC(vCDcMem);

		EndPaint(vConsoleRoot,&sConsoleCanvas);
		break;
	case WM_CTLCOLORLISTBOX:
		SetTextColor(vCDc,RGB(160,137,0));
		SetBkMode(vCDc,TRANSPARENT);
		return (LONG)vConsoleBackground;
		break;
	case WM_CLOSE:
	case WM_DESTROY:
		EndDialog(hwnd,0);
		break;
	default:
		return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
}

void cDllLoaderUi::mCreateSplash(int IcoResource)
{
	sWinClass.cbClsExtra=0;
	sWinClass.cbWndExtra=0;
	sWinClass.hbrBackground=(HBRUSH)COLOR_APPWORKSPACE+1;
	sWinClass.hCursor=LoadCursor(0,IDC_ARROW);
	sWinClass.hIcon=LoadIcon(vInstance,MAKEINTRESOURCE(IcoResource));
	sWinClass.hInstance=vInstance;
	sWinClass.lpfnWndProc=mLoaderProc;
	sWinClass.lpszClassName="MWSEMainWinClass";
	sWinClass.lpszMenuName=0;
	sWinClass.style=0;

	if(!RegisterClass(&sWinClass))
		MessageBox(0,"Couldn't Register Splash Screen Class With System","MWSE Loader Error",MB_ICONERROR);

	vRoot=CreateWindowEx(0,sWinClass.lpszClassName,"MWSE Loader",
		WS_POPUP|WS_SYSMENU,
		10,10,350,200,
		0,0,vInstance,0);

	ShowWindow(vRoot,SW_SHOW);
	UpdateWindow(vRoot);
}

void cDllLoaderUi::mCreateConsole(int IcoResource)
{
	sConsoleWinClass.cbClsExtra=0;
	sConsoleWinClass.cbWndExtra=0;
	sConsoleWinClass.hbrBackground=(HBRUSH)COLOR_APPWORKSPACE+1;
	sConsoleWinClass.hCursor=LoadCursor(0,IDC_ARROW);
	sConsoleWinClass.hIcon=LoadIcon(vInstance,MAKEINTRESOURCE(IcoResource));
	sConsoleWinClass.hInstance=vInstance;
	sConsoleWinClass.lpfnWndProc=mConsoleProc;
	sConsoleWinClass.lpszClassName="MWSELoaderConsoleWindow";
	sConsoleWinClass.lpszMenuName=0;
	sConsoleWinClass.style=0;

	if(!RegisterClass(&sConsoleWinClass))
		MessageBox(0,"Couldn't Register MWSE Console","MWSE Loader Error",MB_ICONERROR);

	vConsoleRoot=CreateWindowEx(WS_EX_TOOLWINDOW,sConsoleWinClass.lpszClassName,"MWSE Loader Console",
		WS_POPUP,
		10,215,288,266,
		vRoot,0,vInstance,0);

	vConsoleInputScreen=CreateWindowEx(WS_EX_STATICEDGE,"LISTBOX",0,
		WS_CHILD|WS_VISIBLE|LBS_NOINTEGRALHEIGHT|LBS_DISABLENOSCROLL|LBS_NOSEL,
		8,29,273,230,
		vConsoleRoot,0,vInstance,0);

	SendMessage(vConsoleInputScreen,WM_SETFONT,(WPARAM)vConsoleFont,(LPARAM)true);

	ShowWindow(vConsoleRoot,SW_SHOW);
	UpdateWindow(vConsoleRoot);
}

void cDllLoaderUi::mConsolePut(char contents[])
{
	SendMessage(vConsoleInputScreen,LB_ADDSTRING,0,(LPARAM)contents);
}

void cDllLoaderUi::mFlushConsole()
{
	char Buffer[1000];

	FILE *FlushEmOutJim; //Lol, What do you expect, I'm out of coffee
	FlushEmOutJim=fopen("MWSE.log.html","w+");

	fprintf(FlushEmOutJim,"%s",
		"<!--MWSE Produced Log File-->\n"
		"<html>\n"
		"<head>\n"
		"<title>MWSE Log</title>\n"
		"</head>\n"
		"<body style='background-color:#000000;color:#a08900;'>\n"
		"-----------------------------------------------------------------\n"
		"<br/>\n"
		"<br/>\n"
		);

	for(int I=0;I<SendMessage(vConsoleInputScreen,LB_GETCOUNT,0,0);I++)
	{
		SendMessage(vConsoleInputScreen,LB_GETTEXT,(WPARAM)I,(LPARAM)Buffer);
		fprintf(FlushEmOutJim,"%s<br/>\n",Buffer);
	}

	fprintf(FlushEmOutJim,"%s",
		"<br/>\n"
		"-----------------------------------------------------------------\n"
		"</body>\n"
		"</html>\n"
		);

	fclose(FlushEmOutJim);
}

cDllLoaderUi::cDllLoaderUi()
{
	vInstance=GetModuleHandle(0);
	vConsoleFont=(HFONT)GetStockObject(DEFAULT_GUI_FONT);
	vConsoleBackground=CreateSolidBrush(RGB(0,0,0));
}

cDllLoaderUi::~cDllLoaderUi()
{
	DeleteObject(vSplashImage);
	DeleteObject(vConsoleImage);
	DeleteObject(vConsoleFont);
	DeleteObject(vConsoleBackground);
	DeleteDC(vCDc);
	DeleteDC(vDc);
}