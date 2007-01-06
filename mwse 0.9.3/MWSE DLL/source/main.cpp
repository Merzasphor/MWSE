#include "nLogger.h"
#include "MWSEmain.h"

/*
 1/6/07
 AnthonyG:
 I'm working on replacing LOG with nLogger.
 Current class for logging is HTML, Feel free to change it.

 Most of this needs to be cleaned up, Every line is defiled.
 Timeslip: Please abide to the standard introduced in the Loader's cDllLoader .h/.cpp.
*/
//TODO: Check FUNCHASEQUIPEDPART2 works - uses dodgy breakpoint

//AnthonyG: What do you know? Another useless static :)
 char WelcomeMessage[]=
	 "Morrowind Script Extender v0.9.3\n"
     "MWSE Copyright (C) 2003-2007 FreshFish copyleft GPL\n"
     "\nThis program is free software, licensed according to the GNU Public License,\n"
     "and comes with ABSOLUTELY NO WARRANTY.  See the file 'gpl.txt' for details.\n"
     "MWSE contributers: cdcooley, Fliggerty, Tp21, Timeslip and probably others\n";

//Alternate injection method, for automatic loading without using MWSEloader.exe
//use exports.def as the module definitions file, uncomment this function and rename the dll d3d8.dll
//uncomment in exports.def

/*typedef void* (_stdcall *D3DProc)(UINT);
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
	//1/6/07 AnthonyG: Instantiate HTML logger class
	nLogger::cHtml MainFuncLog;

	if(reason!=DLL_PROCESS_ATTACH) return true;

	char* logname = "MWScriptExtender.log"; //logfile path, don't change because i can break some mods...
	MainFuncLog.mOpen(logname);

	MainFuncLog.mAddCustom(WelcomeMessage,"#a9a9a9");
	MainFuncLog.mAddCustom("\n\n\nMWSE dll attach start\n","#a9a9a9");

	MWSEOnProcessStart();

	MainFuncLog.mAddCustom("MWSE dll attach end\n","#a9a9a9");

	MainFuncLog.mClose();

	return true;
}