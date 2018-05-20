#include "PatchUtil.h"

#include "mwOffsets.h"
#include "TES3Script.h"

#include "MemoryUtil.h"

#include "Log.h"

#include <dbghelp.h>

namespace mwse {
	namespace patch {

		//
		// Patch: Enable
		//

		void PatchScriptOpEnable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0x68 &= 0xFE;
			}
		}

		//
		// Patch: Disable
		//

		void PatchScriptOpDisable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0x68 |= 0x1;
			}
		}

		// Install all the patches.
		void installPatches() {
			// Patch: Enable/Disable
			genCallUnprotected(0x508FEB, reinterpret_cast<DWORD>(PatchScriptOpEnable), 0x9);
			genCallUnprotected(0x5090DB, reinterpret_cast<DWORD>(PatchScriptOpDisable), 0x9);
		}

		//
		// Create minidumps.
		//

		bool isDataSectionNeeded(const WCHAR* pModuleName) {
			// Check parameters.
			if (pModuleName == 0) {
				return false;
			}

			// Extract the module name.
			WCHAR szFileName[_MAX_FNAME] = L"";
			_wsplitpath(pModuleName, NULL, NULL, szFileName, NULL);

			// Compare the name with the list of known names and decide.
			if (_wcsicmp(szFileName, L"Morrowind") == 0) {
				return true;
			}
			else if (_wcsicmp(szFileName, L"ntdll") == 0)
			{
				return true;
			}
			else if (_wcsicmp(szFileName, L"MWSE") == 0)
			{
				return true;
			}

			// Complete.
			return false;
		}

		BOOL CALLBACK miniDumpCallback(PVOID pParam, const PMINIDUMP_CALLBACK_INPUT pInput, PMINIDUMP_CALLBACK_OUTPUT pOutput) {
			BOOL bRet = FALSE;

			// Check parameters 
			if (pInput == 0) {
				return FALSE;
			}
			if (pOutput == 0) {
				return FALSE;
			}

			// Process the callbacks 
			switch (pInput->CallbackType) {
			case IncludeModuleCallback:
			case IncludeThreadCallback:
			case ThreadCallback:
			case ThreadExCallback:
			{
				// Include the thread into the dump 
				bRet = TRUE;
			}
			break;

			case MemoryCallback:
			{
				// We do not include any information here -> return FALSE 
				bRet = FALSE;
			}
			break;

			case ModuleCallback:
			{
				// Does the module have ModuleReferencedByMemory flag set? 
				if (pOutput->ModuleWriteFlags & ModuleWriteDataSeg) {
					if (!isDataSectionNeeded(pInput->Module.FullPath)) {
						log::getLog() << "[MiniDump] Excluding module data sections: 0x" << pInput->Module.FullPath << std::endl;
						pOutput->ModuleWriteFlags &= (~ModuleWriteDataSeg);
					}
				}

				bRet = TRUE;
			}
			break;
			}

			return bRet;
		}

		void CreateMiniDump(EXCEPTION_POINTERS* pep) {
			// Open the file.
			HANDLE hFile = CreateFile("MWSE_MiniDump.dmp", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			if ((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE)) {
				// Create the minidump.
				MINIDUMP_EXCEPTION_INFORMATION mdei;

				mdei.ThreadId = GetCurrentThreadId();
				mdei.ExceptionPointers = pep;
				mdei.ClientPointers = FALSE;

				MINIDUMP_CALLBACK_INFORMATION mci;

				mci.CallbackRoutine = (MINIDUMP_CALLBACK_ROUTINE)miniDumpCallback;
				mci.CallbackParam = 0;

				MINIDUMP_TYPE mdt = (MINIDUMP_TYPE)(MiniDumpWithDataSegs |
					MiniDumpWithHandleData |
					MiniDumpWithFullMemoryInfo |
					MiniDumpWithThreadInfo |
					MiniDumpWithUnloadedModules);

				BOOL rv = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, mdt, (pep != 0) ? &mdei : 0, 0, &mci);

				if (!rv) {
					log::getLog() << "[MiniDump] Creation failed. Error: 0x" << std::hex << GetLastError() << std::endl;
				}
				else {
					log::getLog() << "[MiniDump] Creation successful." << std::endl;
				}

				// Close the file
				CloseHandle(hFile);
			}
			else {
				log::getLog() << "[MiniDump] Creation failed. Could not get file handle. Error: " << GetLastError() << std::endl;
			}
		}

		int __stdcall onWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
			__try {
				return reinterpret_cast<int(__stdcall *)(HINSTANCE, HINSTANCE, LPSTR, int)>(0x416E10)(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
			}
			__except (CreateMiniDump(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
				return 0;
			}

		}

		bool installMiniDumpHook() {
#ifndef _DEBUG
			// Create our hook.
			return genCallEnforced(0x7279AD, 0x416E10, reinterpret_cast<DWORD>(onWinMain));
#else
			return true;
#endif
		}
	}
}
