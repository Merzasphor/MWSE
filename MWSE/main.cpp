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
#include <dbghelp.h>

#include "mwAdapter.h"
#include "Log.h"
#include "MgeTes3Machine.h"

#include "TES3Util.h"
#include "CodePatchUtil.h"
#include "MWSEDefs.h"

using namespace mwse;

TES3MACHINE* mge_virtual_machine = NULL;

BOOL WINAPI DllMain(
					HINSTANCE hinstDLL,	// handle to DLL module
					DWORD fdwReason,	// reason for calling function
					LPVOID lpReserved )	// reserved
{
	HANDLE process = NULL;
	switch(fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		log::OpenLog("MWSELog.txt");
		mwAdapter::Hook(); //for testing purposes only at the moment, this should be replaced by a function more friendly (like a virtual machine init or something)
		log::getLog() << "Morrowind Script Extender v" << MWSE_VERSION_MAJOR << "." << MWSE_VERSION_MINOR << "." << MWSE_VERSION_PATCH << " (built " << __DATE__ << ") initialized." << std::endl;
		mge_virtual_machine = new TES3MACHINE();

		// Parse and load the features installed by the Morrowind Code Patch.
		if (!mwse::mcp::loadFeatureList()) {
			mwse::log::getLog() << "Failed to detect Morrowind Code Patch installed features. MCP may not be installed, or the mcpatch\\installed file may have been deleted. Mods will be unable to detect MCP feature support." << std::endl;
		}

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

// MGE XE exports
extern "C"
{
	__declspec(dllexport) TES3MACHINE* MWSEGetVM();
	__declspec(dllexport) bool MWSEAddInstruction(OPCODE op, INSTRUCTION *ins);
}

TES3MACHINE* MWSEGetVM()
{
	return mge_virtual_machine;
}

bool MWSEAddInstruction(OPCODE op, INSTRUCTION *ins)
{
	return mge_virtual_machine->AddInstruction(op, ins);
}
