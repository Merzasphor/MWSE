/************************************************************************
               main.cpp - Copyright (c) 2008 The MWSE Project
                http://www.sourceforge.net/projects/mwse

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include <windows.h>
#include "mwAdapter.h"
#include "Log.h"

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
		log::OpenLog("MWSEHook.txt");
		mwAdapter::Hook(); //for testing purposes only at the moment, this should be replaced by a function more friendly (like a virtual machine init or something)
		log::getLog() << "Morrowind Script Extender initialized" << std::endl;
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
