#include "csse.h"

#include "LogUtil.h"

#include "CSDialogueInfo.h"
#include "CSGameFile.h"
#include "CSGameSetting.h"
#include "CSPhysicalObject.h"
#include "CSRecordHandler.h"

#include "NIAVObject.h"
#include "NILinesData.h"

#include "WindowMain.h"

#include "DialogCellWindow.h"
#include "DialogDialogueWindow.h"
#include "DialogObjectWindow.h"
#include "DialogRenderWindow.h"
#include "DialogSearchAndReplaceWindow.h"
#include "DialogTextSearchWindow.h"

#include "MemoryUtil.h"
#include "StringUtil.h"
#include "WindowsUtil.h"

#include "BuildDate.h"
#include "Settings.h"

namespace se::cs {
	constexpr auto LOG_SUPPRESSED_WARNINGS = false;
	constexpr auto LOG_NI_MESSAGES = false;

	HMODULE hInstanceCSSE = NULL;

	GameFile* master_Morrowind = nullptr;
	GameFile* master_Tribunal = nullptr;
	GameFile* master_Bloodmoon = nullptr;

	bool isVanillaMaster(GameFile* master) {
		return (master_Morrowind && master == master_Morrowind)
			|| (master_Tribunal && master == master_Tribunal)
			|| (master_Bloodmoon && master == master_Bloodmoon);
	}

	namespace patch {
		const auto TES3_RecordHandler_whoCares = reinterpret_cast<void(__thiscall*)(RecordHandler*)>(0x4041C4);
		void __fastcall findVanillaMasters(RecordHandler* recordHandler) {
			for (auto i = 0; i < recordHandler->activeModCount; ++i) {
				const auto gameFile = recordHandler->activeGameFiles[i];
				if (master_Morrowind == nullptr && string::iequal(gameFile->fileName, "Morrowind.esm")) {
					master_Morrowind = gameFile;
				}
				else if (master_Tribunal == nullptr && string::iequal(gameFile->fileName, "Tribunal.esm")) {
					master_Tribunal = gameFile;
				}
				else if (master_Bloodmoon == nullptr && string::iequal(gameFile->fileName, "Bloodmoon.esm")) {
					master_Bloodmoon = gameFile;
				}
			}

			TES3_RecordHandler_whoCares(recordHandler);
		}

		const auto TES3_GameSetting_SaveGameSetting = reinterpret_cast<bool(__thiscall*)(GameSetting*, GameFile*)>(0x4F9BE0);
		bool __fastcall preventGMSTPollution(GameSetting* gameSetting, DWORD _EDX_, GameFile* file) {
			if (!gameSetting->getModified()) {
				return false;
			}

			return TES3_GameSetting_SaveGameSetting(gameSetting, file);
		}

		void __cdecl suppressDialogueInfoResolveIssues(const char* format, const char* topicId, const char* infoId, const char* text) {
			if constexpr (LOG_SUPPRESSED_WARNINGS) {
				char buffer[1024];
				sprintf_s(buffer, format, topicId, infoId, text);
				log::stream << "Suppressing warning: " << buffer << std::endl;
			}
		}

		const auto ShowDuplicateReferenceWarning = reinterpret_cast<bool(__cdecl*)(const char*, int)>(0x40123A);
		bool __cdecl suppressDuplicateReferenceRemovedWarningForVanillaMasters(const char* message, int referenceCount) {
			if (referenceCount == 1 && master_Tribunal && master_Bloodmoon) {
				const auto cachedValue = se::memory::MemAccess<bool>::Get(0x6D0B6E);
				se::memory::MemAccess<bool>::Set(0x6D0B6E, true);
				auto result = ShowDuplicateReferenceWarning(message, referenceCount);
				se::memory::MemAccess<bool>::Set(0x6D0B6E, cachedValue);
				return result;
			}
			else {
				return ShowDuplicateReferenceWarning(message, referenceCount);
			}
		}

		void __cdecl restoreNiLogMessage(const char* fmt, ...) {
			// Get the calling address.
			byte** asmEBP;
			__asm { mov asmEBP, ebp };
			DWORD callingAddress = DWORD(asmEBP[1] - 0x5);

			va_list args;
			va_start(args, fmt);

			char buffer[2048] = {};
			vsprintf_s(buffer, fmt, args);

			va_end(args);

			log::stream << "[NiLog:0x" << std::hex << callingAddress << std::dec << "] " << buffer;
		}

		void __cdecl restoreNiLogMessageWithNewline(const char* fmt, ...) {
			// Get the calling address.
			byte** asmEBP;
			__asm { mov asmEBP, ebp };
			DWORD callingAddress = DWORD(asmEBP[1] - 0x5);

			va_list args;
			va_start(args, fmt);

			char buffer[2048] = {};
			vsprintf_s(buffer, fmt, args);

			va_end(args);

			log::stream << "[NiLog:0x" << std::hex << callingAddress << std::dec << "] " << buffer << std::endl;
		}

		void __fastcall forceLoadFlagsOnActiveMods(RecordHandler* recordHandler) {
			for (auto i = 0; i < recordHandler->activeModCount; ++i) {
				auto file = recordHandler->activeGameFiles[i];
				if (file->masters == nullptr) {
					const auto cs_GameFile_CreateMasterArray = reinterpret_cast<bool(__thiscall*)(GameFile*, BasicLinkedList<GameFile*>*, bool)>(0x401D7F);
					cs_GameFile_CreateMasterArray(file, recordHandler->availableDataFiles, true);
				}
			}

			const auto overwrittenFunction = reinterpret_cast<void(__thiscall*)(RecordHandler*)>(0x4016F4);
			overwrittenFunction(recordHandler);
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
			_wsplitpath_s(pModuleName, NULL, NULL, NULL, NULL, szFileName, _MAX_FNAME, NULL, NULL);

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
			log::stream << std::endl;
			log::stream << "The Construction Set has crashed! To help improve game stability, post the CSSE_Minidump.dmp and csse.log files to the Morrowind Modding Community #mwse channel on Discord." << std::endl;
			log::stream << "The Morrowind Modding Community Discord can be found at https://discord.me/mwmods" << std::endl;

#ifdef APPVEYOR_BUILD_NUMBER
			log::stream << "Appveyor build: " << APPVEYOR_BUILD_NUMBER << std::endl;
#endif
			log::stream << "Build date: " << CSSE_BUILD_DATE << std::endl;

			// Display the memory usage in the log.
			PROCESS_MEMORY_COUNTERS_EX memCounter = {};
			GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memCounter, sizeof(memCounter));
			log::stream << "Memory usage: " << std::dec << memCounter.PrivateUsage << " bytes." << std::endl;
			if (memCounter.PrivateUsage > 3650722201) {
				log::stream << "  Memory usage is high. Crash is likely due to running out of memory." << std::endl;
			}

			// Open the file.
			auto hFile = CreateFile("CSSE_MiniDump.dmp", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			if ((hFile != NULL) && (hFile != INVALID_HANDLE_VALUE)) {
				// Create the minidump.
				MINIDUMP_EXCEPTION_INFORMATION mdei = {};

				mdei.ThreadId = GetCurrentThreadId();
				mdei.ExceptionPointers = pep;
				mdei.ClientPointers = FALSE;

				MINIDUMP_CALLBACK_INFORMATION mci = {};

				mci.CallbackRoutine = (MINIDUMP_CALLBACK_ROUTINE)miniDumpCallback;
				mci.CallbackParam = 0;

				auto mdt = (MINIDUMP_TYPE)(MiniDumpWithDataSegs |
					MiniDumpWithHandleData |
					MiniDumpWithFullMemoryInfo |
					MiniDumpWithThreadInfo |
					MiniDumpWithUnloadedModules);

				auto rv = MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, mdt, (pep != 0) ? &mdei : 0, 0, &mci);

				if (!rv) {
					log::stream << "MiniDump creation failed. Error: 0x" << std::hex << GetLastError() << std::endl;
				}
				else {
					log::stream << "MiniDump creation successful." << std::endl;
				}

				// Close the file
				CloseHandle(hFile);
			}
			else {
				log::stream << "MiniDump creation failed. Could not get file handle. Error: " << GetLastError() << std::endl;
			}
		}

		int __stdcall onWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
			__try {
				return reinterpret_cast<int(__stdcall*)(HINSTANCE, HINSTANCE, LPSTR, int)>(0x4049B7)(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
			}
			__except (CreateMiniDump(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
				return 0;
			}
		}
	}

	void installPatches() {
		using memory::genCallEnforced;
		using memory::genNOPUnprotected;
		using memory::genJumpEnforced;
		using memory::genJumpUnprotected;
		using memory::writeDoubleWordUnprotected;
		using memory::overrideVirtualTableEnforced;

		// Patch: Collect crash dumps.
#ifndef _DEBUG
		genCallEnforced(0x620DF9, 0x4049B7, reinterpret_cast<DWORD>(patch::onWinMain));
#endif

		// Get the vanilla masters so we suppress errors from them.
		genCallEnforced(0x50194E, 0x4041C4, reinterpret_cast<DWORD>(patch::findVanillaMasters));

		// Patch: Prevent GMST pollution.
		genJumpEnforced(0x4042B4, 0x4F9BE0, reinterpret_cast<DWORD>(patch::preventGMSTPollution));

		// Patch: Suppress "[Following/Previous] string is different for topic" warnings. They're pointless.
		genCallEnforced(0x4F3186, 0x40123A, reinterpret_cast<DWORD>(patch::suppressDialogueInfoResolveIssues));
		genCallEnforced(0x4F31AA, 0x40123A, reinterpret_cast<DWORD>(patch::suppressDialogueInfoResolveIssues));
		genCallEnforced(0x4F3236, 0x40123A, reinterpret_cast<DWORD>(patch::suppressDialogueInfoResolveIssues));
		genCallEnforced(0x4F325A, 0x40123A, reinterpret_cast<DWORD>(patch::suppressDialogueInfoResolveIssues));

		// Patch: Suppress "1 duplicate references were removed" warning popups for vanilla masters.
		genCallEnforced(0x50A9ED, 0x40123A, reinterpret_cast<DWORD>(patch::suppressDuplicateReferenceRemovedWarningForVanillaMasters));

		// Restore debug logs.
		if constexpr (LOG_NI_MESSAGES) {
			genJumpUnprotected(0x593110, reinterpret_cast<DWORD>(patch::restoreNiLogMessage));
			genJumpUnprotected(0x593120, reinterpret_cast<DWORD>(patch::restoreNiLogMessage));
			genJumpUnprotected(0x593130, reinterpret_cast<DWORD>(patch::restoreNiLogMessageWithNewline));
		}

		// Patch: Prevent directory changing when passing a file to the CS.
		genNOPUnprotected(0x443E25, 0x443E30 - 0x443E25);

		// Patch: Speed up MO2 load times.
		writeDoubleWordUnprotected(0x6D9C20, reinterpret_cast<DWORD>(&_stat32));

		// Patch: Ensure master array is initialized for loading plugins.
		genCallEnforced(0x501884, 0x4016F4, reinterpret_cast<DWORD>(patch::forceLoadFlagsOnActiveMods));

		// Patch: Fix bound calculation.
		genJumpEnforced(0x404467, 0x548280, reinterpret_cast<DWORD>(NI::CalculateBounds));

		// Patch: Fix NiLinesData binary loading.
		auto NiLinesData_loadBinary = &NI::LinesData::loadBinary;
		overrideVirtualTableEnforced(0x67A220, 0xC, 0x5CAEF0, *reinterpret_cast<DWORD*>(&NiLinesData_loadBinary));

		// Install all our sectioned patches.
		window::main::installPatches();
		dialog::cell_window::installPatches();
		dialog::dialogue_window::installPatches();
		dialog::object_window::installPatches();
		dialog::render_window::installPatches();
		dialog::search_and_replace_window::installPatches();
		dialog::text_search_window::installPatches();
	}

	void updateCurrentDirectory() {
		using namespace std::filesystem;
		using namespace windows;

		// Get the path of CSSE.dll.
		auto csseDllPath = getModulePath(hInstanceCSSE);
		if (csseDllPath.empty()) {
			log::stream << "WARNING: Could not resolve CSSE DLL directory." << std::endl;
			return;
		}

		// See if we even need to change paths.
		auto oldPath = current_path();
		auto installPath = csseDllPath.parent_path();
		if (oldPath == installPath) {
			return;
		}

		// Update and log path change.
		current_path(installPath);
		log::stream << "Changed working directory from " << oldPath << " to " << installPath << std::endl;
	}

	void attachToProcess(HMODULE hModule) {
		hInstanceCSSE = hModule;

		// Open our log file.
		log::stream.open(windows::getModulePath(hInstanceCSSE).parent_path() / "csse.log");
#ifdef APPVEYOR_BUILD_NUMBER
		log::stream << "Construction Set Extender build " << APPVEYOR_BUILD_NUMBER << " (built " << __DATE__ << ") hooked." << std::endl;
#else
		log::stream << "Construction Set Extender (built " << __DATE__ << ") hooked." << std::endl;
#endif

		// Always force the current path to the root directory.
		updateCurrentDirectory();

		// Load settings. Immediately save after so we can see new options if needed.
		settings.load();
		settings.save();

		// Install TES Construction Set executable patches.
		installPatches();

		// Report successful initialization.
		log::stream << "CSSE initialization complete." << std::endl;
	}

	void detachFromProcess() {
		settings.save();
		log::stream << "CSSE detached from CS process." << std::endl;
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		se::cs::attachToProcess(hModule);
		break;
	case DLL_PROCESS_DETACH:
		se::cs::detachFromProcess();
		break;
	}
	return TRUE;
}

