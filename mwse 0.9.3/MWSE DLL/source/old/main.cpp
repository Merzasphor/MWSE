#include "LOG.h"
#include "Breakpoint.h"
#include "MWSEmain.h"

static const char WelcomeMessage[]= 
 "Morrowind Script Extender v1.9.0\n"
 "Copyright (C) 2003-2007 FreshFish copyleft GPL\n\n"
 "This program is free software, licensed according to the GNU Public License,\n"
 "and comes with ABSOLUTELY NO WARRANTY.  See the file 'gpl.txt' for details.\n"
 "Contributers: CDCooly, Fliggerty, Tp21, Timeslip and others\n";

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
	}

BOOL _stdcall DllMain(HANDLE hModule, DWORD reason, void* unused)
{
	if(reason!=DLL_PROCESS_ATTACH) return true;

	char* logname = "MWScriptExtender.log"; //logfile path, don't change because i can break some mods...
	LOG::open(logname);	

	LOG::log(WelcomeMessage);
	LOG::log("MWSE dll attach start\n");

	MWSEOnProcessStart();

	LOG::log("MWSE dll attach end\n");

	return true;
}