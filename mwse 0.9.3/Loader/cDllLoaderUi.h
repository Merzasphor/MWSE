#ifndef _ERR_CDLLLOADERUI
#define _ERR_CDLLLOADERUI
#define _CRT_SECURE_NO_DEPRECATE
/*************************************\
* Started: 1/7/07                     *
* AnthonyG                            *
* All UI stuff goes here              *
* If you want to modify               *
* Things the end-user will see        *
* I.E. The splash screen, Put it here *
\*************************************/
#include<windows.h>
#include<stdio.h>
#include"Resource.h"

class cDllLoaderUi
{
private:
	//AnthonyG: Splash screen variables, If you want to avoid MemLeaks, Don't play with them :)
    //These actually need to be static :)
	static HDC vDc,vDcMem;
	static HBITMAP vSplashImage,vSplashImageRec;
	static BITMAP sBmInfo;
	static PAINTSTRUCT sCanvas;
	//Splash screen windowing variables
	static HWND vRoot;
	WNDCLASS sWinClass;
	/*
	---------------------------
	*/
	//Console variables
    WNDCLASS sConsoleWinClass;
	static HWND vConsoleRoot,vConsoleInputScreen;

	//AnthonyG: Console screen variables, If you want to avoid MemLeaks, Don't play with them :)
    //These actually need to be static :)
	static HDC vCDc,vCDcMem;
	static HBITMAP vConsoleImage,vConsoleImageRec;
	static BITMAP sConsoleBmInfo;
	static PAINTSTRUCT sConsoleCanvas;
	HFONT vConsoleFont;
	static HBRUSH vConsoleBackground;
	/*
	---------------------------
	*/
	//Use this for functions that require a prog instance.
	//WinMain's HINSTANCE isn't very OO, and it's annoying having to use it only in that scope.
	HINSTANCE vInstance;
	//Callback function to handle messages, Must be static.
	static LRESULT CALLBACK mLoaderProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
	//THIS is the callback for the console
	static LRESULT CALLBACK mConsoleProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
public:
	//Fill sWinClass, Render splash
	void mCreateSplash(int IcoResource);

	//Render the console window
	void mCreateConsole(int IcoResource);

	//Write to the console's screen
	void mConsolePut(char contents[]);

	//Flush Console Contents to a file
	void mFlushConsole();

	cDllLoaderUi();
	~cDllLoaderUi();
};

#endif
	