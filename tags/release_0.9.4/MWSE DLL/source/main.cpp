
#include "cLog.h"
#include "cMWSEmain.h"
#include "ModuleVersion.h"

#include <string>
/*
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
	switch(reason)
	{
	case DLL_PROCESS_ATTACH:
        {
	    //Don't use this anywhere else
	    cLog::mOpenLog();
        char buffer[512];
        HMODULE thisModule = GetModuleHandle("MWSE.DLL");
        int length = GetModuleFileName(thisModule, buffer, sizeof buffer);
        std::string version = ModuleVersion::getModuleVersion(buffer).getVersionString();
		cLog::mLogMessage("MWSE %s loaded\n", version.c_str());
        }
		break;
	case DLL_PROCESS_DETACH:
		cLog::mLogMessage("MWSE Terminated\n");
	    //Don't use this anywhere else
	    cLog::mCloseLog();
		return true;
		break;
	case DLL_THREAD_ATTACH:
		return true;
		break;
	case DLL_THREAD_DETACH:
		return true;
		break;
	default: //in any other case (shouldn't happen)
		cLog::mLogMessage("DLL:Unknown DLL event\n");
		return true;
		break;
	}

	cLog::mLogMessage("DLL:Starting Script Extender\n");
	cMWSEMain::mStartMWSE();

	return true;
}