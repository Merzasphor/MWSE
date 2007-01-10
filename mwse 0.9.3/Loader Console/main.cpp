#define WIN32_LEAN_AND_MEAN
#include "cDllLoader.h"
#include "cMailServer.h"
#include "nLogger.h"

/*
AnthonyG 5-01-07
Added silent and console modes
To do silent define _SILENT
To show a console window don't define anything
Main MUST return an integer to exit properly, changed to int type
*/

//What functions do these macros cover? 
//Look like debug macros, Use printf :). AnthonyG
/*
#define _ERROR
#define _MESSAGE
*/

#ifndef _SILENT
int main(int argc, char* argv[])
#else
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
#endif
{
    #ifndef _SILENT
	/*
	Added by AnthonyG 05-4-07, 
	Preprocessed to save that MicroSec or two of CPU time :).
	Makes the console a bit more appealing to have a title
	*/
	SetConsoleTitle("Morrowind Script Extender");
    #endif

	//Message var, Don't change this
	MSG vMsg;

	//Instantiate cDllLoader
	cDllLoader iStartEmUp;
	//Instantiate server class
	cMailServer iMail;

	#ifndef _SILENT

	//argc and argv don't exists when run in silent mode
	if(argc > 1)
	{
		iStartEmUp.mInitMorrowindCommandline(argv[1]);
	}
	else
	{
		iStartEmUp.mInitMorrowind();
	}
	#else

	iStartEmUp.mInitMorrowind();

	#endif

	iStartEmUp.mInjectDll(iStartEmUp.vMorroID);

	//Create mail server(So we can get log msgs from the DLL)
	iMail.mCreateServer();
	while(GetMessage(&vMsg,0,0,0)>0)
	{
		iMail.mReadMail();
		TranslateMessage(&vMsg);
		DispatchMessage(&vMsg);
	}
	//Shutdown the server
	iMail.mShutdownServer();

	return 0;
}

