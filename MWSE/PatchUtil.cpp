#include "PatchUtil.h"

#include "mwOffsets.h"
#include "MemoryUtil.h"
#include "Log.h"

#include "TES3Actor.h"
#include "TES3DataHandler.h"
#include "TES3Game.h"
#include "TES3GameFile.h"
#include "TES3GameSetting.h"
#include "TES3Misc.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3UIElement.h"
#include "TES3UIInventoryTile.h"
#include "TES3WorldController.h"

#include "TES3Util.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include <Windows.h>
#include <Psapi.h>

#include <dbghelp.h>

namespace mwse {
	namespace patch {

		//
		// Patch: Enable
		//

		void PatchScriptOpEnable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0xC &= 0xFE;
			}
		}

		//
		// Patch: Disable
		//

		void PatchScriptOpDisable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0xC |= 0x1;
			}
		}

		//
		// Patch: Unify athletics training.
		//

		void PatchUnifyAthleticsTraining() {
			TES3::WorldController* worldController = TES3::WorldController::get();
			TES3::MobilePlayer* mobilePlayer = worldController->getMobilePlayer();

			TES3::Skill* athletics = &TES3::DataHandler::get()->nonDynamicData->skills[TES3::SkillID::Athletics];

			// If we're running, use the first progress.
			if (mobilePlayer->movementFlags & TES3::ActorMovement::Running) {
				mobilePlayer->exerciseSkill(TES3::SkillID::Athletics, athletics->progressActions[0] * worldController->deltaTime);
			}

			// If we're swimming, use the second progress.
			if (mobilePlayer->movementFlags & TES3::ActorMovement::Swimming) {
				mobilePlayer->exerciseSkill(TES3::SkillID::Athletics, athletics->progressActions[1] * worldController->deltaTime);
			}
		}

		//
		// Patch: Unify sneak training.
		//

		void PatchUnifySneakTraining() {
			TES3::NonDynamicData* nonDynamicData = TES3::DataHandler::get()->nonDynamicData;

			// Decrement sneak use delay counter.
			*reinterpret_cast<float*>(0x7D16E0) = *reinterpret_cast<float*>(0x7D16E0) - nonDynamicData->GMSTs[TES3::GMST::fSneakUseDelay]->value.asFloat;

			// Excercise sneak.
			TES3::WorldController::get()->getMobilePlayer()->exerciseSkill(TES3::SkillID::Sneak, nonDynamicData->skills[TES3::SkillID::Sneak].progressActions[0]);
		}

		//
		// Patch: Clean up cursor behavior when alt-tabbing.
		//

		bool& TES3_WindowInFocus = *reinterpret_cast<bool*>(0x776D08);
		int& TES3_CursorShown = *reinterpret_cast<int*>(0x776D0C);

		WNDPROC TES3_DefaultWindowMessageHandler = nullptr;

		LRESULT __stdcall PatchLessAggressiveCursorCapturingWindowHandle(HWND hWnd, int uMsg, WPARAM wParam, LPARAM lParam) {
			switch (uMsg) {
			case WM_ACTIVATE:
			{
				if (wParam) {
					auto worldController = TES3::WorldController::get();
					if (worldController) {
						worldController->updateTiming();
					}
					TES3_WindowInFocus = true;
					if (TES3_CursorShown) {
						ShowCursor(false);
						TES3_CursorShown = false;
					}
				}
				else {
					TES3_WindowInFocus = false;
					if (!TES3_CursorShown) {
						ShowCursor(true);
						TES3_CursorShown = true;
					}
				}
				return 0;
			}
			break;
			case WM_NCHITTEST:
			{
				auto result = DefWindowProc(hWnd, uMsg, wParam, lParam);
				if (TES3_WindowInFocus && TES3_CursorShown && result == HTCLIENT) {
					ShowCursor(false);
					TES3_CursorShown = false;
				}
				else if (TES3_WindowInFocus && !TES3_CursorShown && result != HTCLIENT) {
					ShowCursor(true);
					TES3_CursorShown = true;
				}
				return result;
			}
			break;
			}

			return TES3_DefaultWindowMessageHandler(hWnd, uMsg, wParam, lParam);
		}

		//
		// Patch: Fix crash with paper doll equipping/unequipping.
		//
		// In this patch, the tile associated with the stack may have been deleted, but the property to the TES3::ItemData 
		// remains. If the memory is reallocated it will fill with garbage, and cause a crash. The tile property, however,
		// is properly deleted. So we look for that instead, and return its associated item data (which is the same value).
		//! TODO: Find out where it's being deleted, and also delete the right property.
		//

		TES3::UI::PropertyValue* __fastcall PatchPaperdollTooltipCrashFix(TES3::UI::Element* self, DWORD _UNUSUED_, TES3::UI::PropertyValue* propValue, TES3::UI::Property prop, TES3::UI::PropertyType propType, const TES3::UI::Element* element = nullptr, bool checkInherited = false) {
			auto tileProp = self->getProperty(TES3::UI::PropertyType::Pointer, *reinterpret_cast<TES3::UI::Property*>(0x7D3A70));
			auto tile = reinterpret_cast<TES3::UI::InventoryTile*>(tileProp.ptrValue);

			if (tile == nullptr) {
				propValue->ptrValue = nullptr;
			}
			else {
				propValue->ptrValue = tile->itemData;
			}

			return propValue;
		}

		//
		// Install all the patches.
		//

		void installPatches() {
			// Patch: Enable/Disable.
			genCallUnprotected(0x508FEB, reinterpret_cast<DWORD>(PatchScriptOpEnable), 0x9);
			genCallUnprotected(0x5090DB, reinterpret_cast<DWORD>(PatchScriptOpDisable), 0x9);

			// Patch: Unify athletics and sneak training.
			genCallUnprotected(0x569EE7, reinterpret_cast<DWORD>(PatchUnifyAthleticsTraining), 0xC6);
			genCallUnprotected(0x5683D0, reinterpret_cast<DWORD>(PatchUnifySneakTraining), 0x65);

			// Patch: Crash fix for help text for paperdolls.
			genCallEnforced(0x5CDFD0, 0x581440, reinterpret_cast<DWORD>(PatchPaperdollTooltipCrashFix));

			// Patch (optional): Change window cursor behavior.
			TES3_DefaultWindowMessageHandler = (WNDPROC)SetClassLongPtr(TES3::WorldController::get()->Win32_hWndParent, GCLP_WNDPROC, (LONG_PTR)PatchLessAggressiveCursorCapturingWindowHandle);
			if (TES3_DefaultWindowMessageHandler == nullptr) {
				log::getLog() << "[MWSE:Patch:Less Aggressive Cursor Capturing] ERROR: Failed to replace window handler using SetClassLongPtr." << std::endl;
			}

			// Patch: Optimize GetDeadCount and associated dialogue filtering/logic.
			auto killCounterIncrement = &TES3::KillCounter::increment;
			genCallEnforced(0x523D73, 0x55D820, *reinterpret_cast<DWORD*>(&killCounterIncrement));
			auto killCounterGetCount = &TES3::KillCounter::getKillCount;
			genCallEnforced(0x4B0B2E, 0x55D900, *reinterpret_cast<DWORD*>(&killCounterGetCount));
			genCallEnforced(0x50AC85, 0x55D900, *reinterpret_cast<DWORD*>(&killCounterGetCount));
			genCallEnforced(0x50ACAB, 0x55D900, *reinterpret_cast<DWORD*>(&killCounterGetCount));
			genCallEnforced(0x745FF0, 0x55D900, *reinterpret_cast<DWORD*>(&killCounterGetCount));
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
			log::getLog() << std::endl;
			log::getLog() << "Morrowind has crashed! To help improve game stability, send MWSE_Minidump.dmp and mwse.log to NullCascade@gmail.com or to NullCascade#1010 on Discord." << std::endl;

			// Display the memory usage in the log.
			PROCESS_MEMORY_COUNTERS_EX memCounter;
			GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&memCounter, sizeof(memCounter));
			log::getLog() << "Memory usage: " << memCounter.PrivateUsage << " bytes." << std::endl;

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
					log::getLog() << "MiniDump creation failed. Error: 0x" << std::hex << GetLastError() << std::endl;
				}
				else {
					log::getLog() << "MiniDump creation successful." << std::endl;
				}

				// Close the file
				CloseHandle(hFile);
			}
			else {
				log::getLog() << "MiniDump creation failed. Could not get file handle. Error: " << GetLastError() << std::endl;
			}

			// Try to print the lua stack trace.
			log::getLog() << "Lua traceback at time of crash:" << std::endl;
			mwse::lua::logStackTrace();
		}

		int __stdcall onWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
			__try {
				return reinterpret_cast<int(__stdcall *)(HINSTANCE, HINSTANCE, LPSTR, int)>(0x416E10)(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
			}
			__except (CreateMiniDump(GetExceptionInformation()), EXCEPTION_EXECUTE_HANDLER) {
				// Try to reset gamma.
				auto game = TES3::Game::get();
				if (game) {
					game->setGamma(1.0f);
				}

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
