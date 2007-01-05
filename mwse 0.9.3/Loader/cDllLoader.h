#ifndef _ERR_CDLLLOADER
#define _ERR_CDLLLOADER
#define _CRT_SECURE_NO_DEPRECATE
/*********************************************\
* AnthonyG:                                   *
* Class that contains members to load the DLL *
* Please add funcs to this class as needed    *
\*********************************************/
//Lean and mean specified in MWSEloader already
#include<Windows.h>
#include<StdIO.h>

class cDllLoader
{
private:
	//Later members may want to use these
	HANDLE vProcess,vThread;
	DWORD vBaseHook,vLoadLibraryAddr;
	DWORD vBytesWritten;
	BYTE vHookCode[5];
	//Process items
	HWND vMorroWin;
	STARTUPINFO sSi; //See constructor definition
	PROCESS_INFORMATION sPi;
	//AnthonyG's MorroLocater vars
	char vMorroLauncherLocation[1000]; //Will contain location of Morrowind Launcher
	char vMorroLauncherFormattedLocation[1000]; //Use this, Has full location.
	HKEY vKeyRes;
	DWORD vSizeOfBuf;
public:
	DWORD vMorroID;

	//Start up Morrowind. Guess what? Tis now directory dependent.(I.E. Place it in your desktop folder if you want!)
	//Fills MorroID with Proc ID for use with InjectDll;
	void mInitMorrowind();
	//Inject DLL 
	void mInjectDll(DWORD ProcID);

	cDllLoader();
	~cDllLoader();
};

#endif //_ERR_CDLLLOADER