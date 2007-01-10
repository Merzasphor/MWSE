#define WIN32_LEAN_AND_MEAN
#include"cDllLoader.h"
//AnthonyG 1/7/07
#include"cDllLoaderUi.h"
#include"cMailServer.h"
#include"Resource.h"

/*
 1/7/07
 AnthonyG
 Let's get this masterpiece user-friendly
 I removed the preprocessors. Eye-candied console
 doesn't use nor need any of these.
*/
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
	//Message var, Don't change this
	MSG vMsg;

	//Instantiate cDllLoader
	cDllLoader iStartEmUp;
	//Instantiate UI class
	cDllLoaderUi iPrepUi;
	//Instantiate server class
	cMailServer Mail;

	//Render up the splash screen
	iPrepUi.mCreateSplash(IDI_ICON1);
	//Render up the console(Yes darksecond, RLY, Theres a console)
	iPrepUi.mCreateConsole(IDI_ICON1);

	//Do the searches
	iStartEmUp.mInitMorrowind();
	//Inject the DLL
	iStartEmUp.mInjectDll(iStartEmUp.vMorroID);

	//Create mail server(So we can get log msgs from the DLL)
	Mail.mCreateServer();
	while(GetMessage(&vMsg,0,0,0)>0)
	{
		Mail.mReadMail();
		TranslateMessage(&vMsg);
		DispatchMessage(&vMsg);
	}
	//Shutdown the server
	Mail.mShutdownServer();

	iPrepUi.mFlushConsole();

	return 0;
}

