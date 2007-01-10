#include"cMailClient.h"
#include "MWSEmain.h"

/*
 1/9/07
 AnthonyG:

 Logger soon to be nonexistant, mailslots will be used
 to send messages to the loader console.

 Most of this needs to be cleaned up, Every line is defiled.
 Timeslip: Please abide to the standard introduced in the Loader's cDllLoader .h/.cpp.
*/
//TODO: Check FUNCHASEQUIPEDPART2 works - uses dodgy breakpoint

//Alternate injection method, for automatic loading without using MWSEloader.exe
//use exports.def as the module definitions file, uncomment this function and rename the dll d3d8.dll
//uncomment in exports.def

/*
typedef void* (_stdcall *D3DProc)(UINT);
void* _stdcall FakeDirect3DCreate(UINT version) {
	//Local handle variables
	HMODULE d3ddll=NULL;
	D3DProc func=NULL;
	//Load the real d3d8 dll
	char Path[MAX_PATH];
	GetSystemDirectoryA(Path,MAX_PATH);
	strcat_s(Path,MAX_PATH,"\\d3d8.dll");
	d3ddll=LoadLibraryA(Path);
	func=(D3DProc)GetProcAddress(d3ddll,"Direct3DCreate8");

	return func(version);
}*/

BOOL _stdcall DllMain(HANDLE hModule, DWORD reason, void* unused)
{
	cMailClient Mail;

	//Don't use this anywhere else
	Mail.mOpenMailConnection();

	if(reason!=DLL_PROCESS_ATTACH)
	{
		Mail.mWriteMail("Wrong Reason, DLL exiting");
		return true;
	}

	Mail.mWriteMail("Starting Script Extender");
	MWSEOnProcessStart();

	//Don't use this anywhere else
	Mail.mCloseMailConnection();

	return true;
}