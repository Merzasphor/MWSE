#include "csse.h"

#include "LogUtil.h"

#include "CSDialogueInfo.h"
#include "CSGameFile.h"
#include "CSGameSetting.h"
#include "CSRecordHandler.h"

#include "WindowMain.h"

#include "DialogCellWindow.h"
#include "DialogDialogueWindow.h"
#include "DialogObjectWindow.h"
#include "DialogRenderWindow.h"
#include "DialogSearchAndReplaceWindow.h"

#include "MemoryUtil.h"
#include "StringUtil.h"
#include "WindowsUtil.h"

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
	}

	void installPatches() {
		using memory::genCallEnforced;
		using memory::genJumpEnforced;
		using memory::genJumpUnprotected;

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

		// Install all our sectioned patches.
		window::main::installPatches();
		dialog::cell_window::installPatches();
		dialog::dialogue_window::installPatches();
		dialog::object_window::installPatches();
		dialog::render_window::installPatches();
		dialog::search_and_replace_window::installPatches();
	}

	void attachToProcess(HMODULE hModule) {
		hInstanceCSSE = hModule;

		// Open our log file.
		log::stream.open(windows::getModulePath(hInstanceCSSE).parent_path() / "csse.log");

		// Always force the current path to the root directory.
		std::filesystem::current_path(windows::getModulePath(hModule).parent_path());

		// Load settings.
		settings.load();

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

