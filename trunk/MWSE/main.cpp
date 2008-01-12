#include <windows.h>
#include "mwAdapter.h"

using namespace mwse;

BOOL WINAPI DllMain(
					HINSTANCE hinstDLL,	// handle to DLL module
					DWORD fdwReason,	// reason for calling function
					LPVOID lpReserved )	// reserved
{
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		mwAdapter::Hook(); //for testing purposes only at the moment, this should be replaced by a function more friendly (like a virtual machine init or something)
		//also Log should be initialized ;)
		break;
	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;
	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;
	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
		break;
	}

	return TRUE; // Successful DLL_PROCESS_ATTACH.
}
