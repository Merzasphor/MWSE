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
void* external_malloc = NULL;
void* external_free = NULL;
void* external_realloc = NULL;

static BOOL CALLBACK EnumSymbolsCallback(PSYMBOL_INFO symbol_info,
	ULONG /*symbol_size*/,
	PVOID /*user_context*/);

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
		// Find the addresses of malloc(), realloc(), free() that MW uses,
		// so that we can interact with its heap.
		process = GetCurrentProcess();
		SymInitialize(process,
			NULL,  // No search path.
			TRUE); // Load symbol tables for all modules.
		SymEnumSymbols(process,
			0,                    // No base address.
			"msvcrt!*",           // Only look in msvcrt.dll.
			EnumSymbolsCallback,
			NULL);                // No context.
		SymCleanup(process);

		if (external_malloc == NULL) {
			log::getLog() << "Error: unable to find malloc()" << std::endl;
		}
		else {
			tes3::_malloc = reinterpret_cast<tes3::ExternalMalloc>(external_malloc);
		}

		if (external_free == NULL) {
			log::getLog() << "Error: unable to find free()" << std::endl;
		}
		else {
			tes3::_free = reinterpret_cast<tes3::ExternalFree>(external_free);
		}

		if (external_realloc == NULL) {
			log::getLog() << "Error: unable to find realloc()" << std::endl;
		}
		else {
			tes3::_realloc = reinterpret_cast<tes3::ExternalRealloc>(external_realloc);
		}

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

static BOOL CALLBACK EnumSymbolsCallback(PSYMBOL_INFO symbol_info,
	ULONG /*symbol_size*/,
	PVOID /*user_context*/)
{
	if (strcmp(symbol_info->Name, "malloc") == 0) {
		external_malloc = reinterpret_cast<void*>(symbol_info->Address);
	}
	else if (strcmp(symbol_info->Name, "free") == 0) {
		external_free = reinterpret_cast<void*>(symbol_info->Address);
	}
	else if (strcmp(symbol_info->Name, "realloc") == 0) {
		external_realloc = reinterpret_cast<void*>(symbol_info->Address);
	}
	return TRUE;
}