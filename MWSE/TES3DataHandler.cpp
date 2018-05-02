#include "TES3DataHandler.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"
#include "LuaUtil.h"

#define TES3_NonDynamicData_saveGame 0x4C4250
#define TES3_NonDynamicData_loadGameInGame 0x4C4800
#define TES3_NonDynamicData_resolveObject 0x4B8B60
#define TES3_NonDynamicData_findTemplate2 0x4BA8D0
#define TES3_NonDynamicData_findFirstCloneOfActor 0x4B8F50
#define TES3_NonDynamicData_findScriptByName 0x4BA700
#define TES3_NonDynamicData_findGlobalVariable 0x4BA820
#define TES3_NonDynamicData_findDialogInfo 0x4BA8D0
#define TES3_NonDynamicData_findSound 0x4BA7A0
#define TES3_NonDynamicData_addNewObject 0x4B8980
#define TES3_NonDynamicData_deleteObject 0x4B8B20

#define TES3_DataHandler_getSoundPlaying 0x48BBD0

namespace TES3 {

	//
	// NonDynamicData
	//

	bool NonDynamicData::saveGame(const char* fileName, const char* saveName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::SaveGameEvent(saveName, fileName));
		if (eventData.valid() && eventData["block"] == true) {
			return true;
		}

		// Fetch the names back from the event data, in case the event changed them.
		std::string eventFileName = eventData["filename"];
		std::string eventSaveName = eventData["name"];

		bool saved = reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, const char*, const char*)>(TES3_NonDynamicData_saveGame)(this, eventFileName.c_str(), eventSaveName.c_str());

		// Pass a follow-up event if we successfully saved.
		if (saved) {
			luaManager.triggerEvent(new mwse::lua::SavedGameEvent(eventSaveName.c_str(), eventFileName.c_str()));
		}

		return saved;
	}

	bool NonDynamicData::loadGame(const char* fileName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::LoadGameEvent(fileName));
		if (eventData.valid() && eventData["block"] == true) {
			return true;
		}

		// Fetch the names back from the event data, in case the event changed them.
		// Also add back in the .ess extension.
		std::string eventFileName = eventData["filename"];
		eventFileName += ".ess";

		bool loaded = reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_loadGameInGame)(this, eventFileName.c_str());

		// Pass a follow-up event if we successfully saved.
		if (loaded) {
			luaManager.triggerEvent(new mwse::lua::LoadedGameEvent(eventFileName.c_str(), fileName == NULL));
		}

		return loaded;
	}

	BaseObject* NonDynamicData::resolveObject(const char* id) {
		return reinterpret_cast<BaseObject*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_resolveObject)(this, id);
	}

	Reference* NonDynamicData::findFirstCloneOfActor(const char* baseId) {
		return reinterpret_cast<Reference*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findFirstCloneOfActor)(this, baseId);
	}

	Script* NonDynamicData::findScriptByName(const char* name) {
		return reinterpret_cast<Script*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findScriptByName)(this, name);
	}

	GlobalVariable* NonDynamicData::findGlobalVariable(const char* name) {
		return reinterpret_cast<GlobalVariable*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findGlobalVariable)(this, name);
	}

	DialogueInfo* NonDynamicData::findDialogInfo(const char* name) {
		return reinterpret_cast<DialogueInfo*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findDialogInfo)(this, name);
	}

	Sound* NonDynamicData::findSound(const char* id) {
		return reinterpret_cast<Sound*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findSound)(this, id);
	}

	bool NonDynamicData::addNewObject(BaseObject* object) {
		return reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_addNewObject)(this, object);
	}

	void NonDynamicData::deleteObject(BaseObject* object) {
		reinterpret_cast<void(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_deleteObject)(this, object);
	}

	//
	// DataHandler
	//

	bool DataHandler::getSoundPlaying(Sound* sound, Reference* reference) {
		return reinterpret_cast<Sound*(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_getSoundPlaying)(this, sound, reference);
	}
}
