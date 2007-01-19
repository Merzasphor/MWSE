//#include"cMailClient.h"
#include "cLog.h"
#include "cMWSEmain.h"

/*
 1/9/07
 AnthonyG:

 Logger soon to be nonexistant, mailslots will be used
 to send messages to the loader console.

 Most of this needs to be cleaned up, Every line is defiled.
 Timeslip: Please abide to the standard introduced in the Loader's cDllLoader .h/.cpp.
*/

//TODO: Check FUNCHASEQUIPEDPART2 works - uses dodgy breakpoint
//TODO: FUNCEXTENDER.cpp: needs upgrade using latest knowledge on subject.

//Do we need this? i don't think we will use this method, because it will give problems with MGE.
//and we have a new way of loading, and else we can't use the Console

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

	//Don't use this anywhere else
	cLog::mOpenLog();

	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
		cLog::mLogMessage("DLL:Attaching to process\n");
		break;
	case DLL_PROCESS_DETACH:
		cLog::mLogMessage("DLL:Unloading from process\n");
		return true;
		break;
	case DLL_THREAD_ATTACH:
		cLog::mLogMessage("DLL:Attaching to thread\n");
//		return true;
		break;
	case DLL_THREAD_DETACH:
		cLog::mLogMessage("DLL:Unloading from thread\n");
		return true;
		break;
	default: //in any other case (shouldn't happen)
		cLog::mLogMessage("DLL:This should not happen\n");
		return true;
		break;
	}

	cLog::mLogMessage("DLL:Starting Script Extender\n");
	cMWSEMain::mStartMWSE();

	//Don't use this anywhere else
	cLog::mCloseLog();

	return true;
}