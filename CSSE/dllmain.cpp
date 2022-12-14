// dllmain.cpp : Defines the entry point for the DLL application.

#include "MathUtil.h"
#include "MemoryUtil.h"
#include "WindowsUtil.h"

#include "LogUtil.h"
#include "MemoryUtil.h"

#include "NILinkedList.h"
#include "NIProperty.h"

#include "CSGameFile.h"
#include "CSGameSetting.h"
#include "CSRecordHandler.h"

#include "DialogDialogueWindow.h"
#include "DialogObjectWindow.h"
#include "DialogRenderWindow.h"

using namespace se::cs;

static GameFile* master_Morrowind = nullptr;
static GameFile* master_Tribunal = nullptr;
static GameFile* master_Bloodmoon = nullptr;

bool isVanillaMaster(GameFile* master) {
	return (master_Morrowind && master == master_Morrowind)
		|| (master_Tribunal && master == master_Tribunal)
		|| (master_Bloodmoon && master == master_Bloodmoon);
}

const auto TES3_RecordHandler_whoCares = reinterpret_cast<void(__thiscall*)(RecordHandler*)>(0x4041C4);
void __fastcall Patch_FindVanillaMasters(RecordHandler* recordHandler) {
	const auto constHandler = recordHandler;
	for (auto i = 0; i < constHandler->activeModCount; ++i) {
		const auto gameFile = constHandler->activeGameFiles[i];
		if (master_Morrowind == nullptr && _strnicmp(gameFile->fileName, "Morrowind.esm", 260) == 0) {
			master_Morrowind = gameFile;
		}
		else if (master_Tribunal == nullptr && _strnicmp(gameFile->fileName, "Tribunal.esm", 260) == 0) {
			master_Tribunal = gameFile;
		}
		else if (master_Bloodmoon == nullptr && _strnicmp(gameFile->fileName, "Bloodmoon.esm", 260) == 0) {
			master_Bloodmoon = gameFile;
		}
	}

	TES3_RecordHandler_whoCares(recordHandler);
}

const auto TES3_Dialogue_resolveLinks = reinterpret_cast<void(__thiscall*)(Dialogue*, void*)>(0x4F30C0);
void __fastcall Patch_SuppressDialogueInfoResolveIssues(Dialogue* dialogue, DWORD _EDX_, void* recordHandler) {
	const auto cachedValue = se::memory::MemAccess<bool>::Get(0x6D0B6E);
	se::memory::MemAccess<bool>::Set(0x6D0B6E, true);
	TES3_Dialogue_resolveLinks(dialogue, recordHandler);
	se::memory::MemAccess<bool>::Set(0x6D0B6E, cachedValue);
}

const auto ShowDuplicateReferenceWarning = reinterpret_cast<bool(__cdecl*)(const char*, int)>(0x40123A);
bool __cdecl PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters(const char* message, int referenceCount) {
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

static auto last2ndClassUpdateTime = std::chrono::milliseconds::zero();
const auto TES3CS_UpdateStatusMessage = reinterpret_cast<void(__cdecl*)(WPARAM, LPARAM)>(0x46E680);
void __cdecl PatchThrottleMessageUpdate(WPARAM type, LPARAM lParam) {
	if (type == 2) {
		const auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
		const auto msSinceLastUpdate = now - last2ndClassUpdateTime;
		if (msSinceLastUpdate.count() < 20) {
			return;
		}
		last2ndClassUpdateTime = now;
	}
	else {
		last2ndClassUpdateTime = std::chrono::milliseconds::zero();
	}
	TES3CS_UpdateStatusMessage(type, lParam);
}

const auto TES3_GameSetting_SaveGameSetting = reinterpret_cast<bool(__thiscall*)(GameSetting*, GameFile*)>(0x4F9BE0);
bool __fastcall PatchPreventGMSTPollution(GameSetting* gameSetting, DWORD _EDX_, GameFile* file) {
	using namespace se::cs;

	if ((gameSetting->flags & 0x2) == 0) {
		return false;
	}

#if _DEBUG
	auto& initializationData = GameSetting::initializers[gameSetting->index];
	log::stream << "Saving GMST: " << initializationData.name << "; flags: " << gameSetting->flags << "; value: ";
	switch (tolower(initializationData.name[0])) {
	case 'i':
		log::stream << gameSetting->value.asInt;
		break;
	case 'f':
		log::stream << gameSetting->value.asFloat;
		break;
	case 's':
		log::stream << gameSetting->value.asString;
		break;
	default:
		log::stream << "N/A";
	}
	log::stream << std::endl;
#endif

	return TES3_GameSetting_SaveGameSetting(gameSetting, file);
}

void __cdecl PatchSpeedUpCellViewDialog(HWND hWnd) {
	SendMessageA(hWnd, WM_SETREDRAW, FALSE, NULL);

	const auto originalFunction = reinterpret_cast<void(__cdecl*)(HWND)>(0x40E250);
	originalFunction(hWnd);

	SendMessageA(hWnd, WM_SETREDRAW, TRUE, NULL);
}

void installPatches() {
	using namespace se::memory;

	// Get the vanilla masters so we suppress errors from them.
	genCallEnforced(0x50194E, 0x4041C4, reinterpret_cast<DWORD>(Patch_FindVanillaMasters));

	// Patch: Suppress "[Following/Previous] string is different for topic" warning popups for vanilla masters.
	genJumpEnforced(0x4023BA, 0x4F30C0, reinterpret_cast<DWORD>(Patch_SuppressDialogueInfoResolveIssues));

	// Patch: Suppress "1 duplicate references were removed" warning popups for vanilla masters.
	genCallEnforced(0x50A9ED, 0x40123A, reinterpret_cast<DWORD>(PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters));

	// Patch: Don't save default GMSTs that haven't been modified.
	genJumpEnforced(0x4042B4, 0x4F9BE0, reinterpret_cast<DWORD>(PatchPreventGMSTPollution));

	// Patch: Optimize displaying of cell view window.
	genJumpEnforced(0x4037C4, 0x40E250, reinterpret_cast<DWORD>(PatchSpeedUpCellViewDialog));

	// Patch: Throttle UI status updates.
	genJumpEnforced(0x404881, 0x46E680, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));

	// Install sectioned window patches.
	se::cs::dialog::dialogue_window::installPatches();
	se::cs::dialog::object_window::installPatches();
	se::cs::dialog::render_window::installPatches();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
		se::cs::log::stream.open("csse.log");
		installPatches();
		se::cs::log::stream << "CSSE initialization complete." << std::endl;
		break;
    }
    return TRUE;
}

