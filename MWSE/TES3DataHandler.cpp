#include "TES3DataHandler.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaSaveGameEvent.h"
#include "LuaSavedGameEvent.h"
#include "LuaLoadGameEvent.h"
#include "LuaLoadedGameEvent.h"

#include "TES3Util.h"

#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3Sound.h"
#include "TES3Spell.h"
#include "TES3WorldController.h"

#include "TES3DialogueInfo.h"

#define TES3_NonDynamicData_saveGame 0x4C4250
#define TES3_NonDynamicData_loadGameInGame 0x4C4800
#define TES3_NonDynamicData_loadGameMainMenu 0x4C4EB0
#define TES3_NonDynamicData_resolveObject 0x4B8B60
#define TES3_NonDynamicData_findDialogue 0x4BA8D0
#define TES3_NonDynamicData_findFirstCloneOfActor 0x4B8F50
#define TES3_NonDynamicData_findScriptByName 0x4BA700
#define TES3_NonDynamicData_findGlobalVariable 0x4BA820
#define TES3_NonDynamicData_findSound 0x4BA7A0
#define TES3_NonDynamicData_addNewObject 0x4B8980
#define TES3_NonDynamicData_deleteObject 0x4B8B20

#define TES3_DataHandler_addSound 0x48BD40
#define TES3_DataHandler_addSoundByName 0x48BCB0
#define TES3_DataHandler_getSoundPlaying 0x48BBD0
#define TES3_DataHandler_removeSound 0x48C0D0
#define TES3_Audio_setBufferVolume 0x4029F0

namespace TES3 {

	//
	// NonDynamicData
	//

	bool NonDynamicData::saveGame(const char* fileName, const char* saveName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::SaveGameEvent(saveName, fileName));
		if (eventData.valid() && eventData["block"] == true) {
			return true;
		}

		// Fetch the names back from the event data, in case the event changed them.
		std::string eventFileName = eventData["filename"];
		std::string eventSaveName = eventData["name"];

		bool saved = reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, const char*, const char*)>(TES3_NonDynamicData_saveGame)(this, eventFileName.c_str(), eventSaveName.c_str());

		// Pass a follow-up event if we successfully saved.
		if (saved) {
			luaManager.triggerEvent(new mwse::lua::event::SavedGameEvent(eventSaveName.c_str(), eventFileName.c_str()));
		}

		return saved;
	}

	LoadGameResult NonDynamicData::loadGame(const char* fileName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::LoadGameEvent(fileName));
		if (eventData.valid() && eventData["block"] == true) {
			return LoadGameResult::Block;
		}

		// Fetch the names back from the event data, in case the event changed them.
		// Also add back in the .ess extension.
		std::string eventFileName = eventData["filename"];
		eventFileName += ".ess";

		bool loaded = reinterpret_cast<bool(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_loadGameInGame)(this, eventFileName.c_str());

		// Pass a follow-up event if we successfully loaded and clear timers.
		if (loaded) {
			luaManager.clearTimers();
			luaManager.triggerEvent(new mwse::lua::event::LoadedGameEvent(eventFileName.c_str(), fileName == NULL));
		}

		return loaded ? LoadGameResult::Success : LoadGameResult::Failure;
	}

	LoadGameResult NonDynamicData::loadGameMainMenu(const char* fileName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		sol::table eventData = luaManager.triggerEvent(new mwse::lua::event::LoadGameEvent(fileName));
		if (eventData.valid() && eventData["block"] == true) {
			return LoadGameResult::Block;
		}

		// Fetch the names back from the event data, in case the event changed them.
		// Also add back in the .ess extension.
		std::string eventFileName = eventData["filename"];
		eventFileName += ".ess";

		bool loaded = reinterpret_cast<bool(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_loadGameMainMenu)(this, eventFileName.c_str());

		// Pass a follow-up event if we successfully loaded and clear timers.
		if (loaded) {
			luaManager.clearTimers();
			luaManager.triggerEvent(new mwse::lua::event::LoadedGameEvent(eventFileName.c_str()));
		}

		return loaded ? LoadGameResult::Success : LoadGameResult::Failure;
	}

	BaseObject* NonDynamicData::resolveObject(const char* id) {
		return reinterpret_cast<BaseObject*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_resolveObject)(this, id);
	}

	Reference* NonDynamicData::findFirstCloneOfActor(const char* baseId) {
		return reinterpret_cast<Reference*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findFirstCloneOfActor)(this, baseId);
	}

	Spell* NonDynamicData::getSpellById(const char* id) {
		TES3::Spell * spell = spellsList->head;
		while (spell != NULL && _stricmp(id, spell->objectID) != 0) {
			spell = reinterpret_cast<TES3::Spell*>(spell->nextInCollection);
		}
		return spell;
	}

	Script* NonDynamicData::findScriptByName(const char* name) {
		return reinterpret_cast<Script*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findScriptByName)(this, name);
	}

	GlobalVariable* NonDynamicData::findGlobalVariable(const char* name) {
		return reinterpret_cast<GlobalVariable*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findGlobalVariable)(this, name);
	}

	Dialogue* NonDynamicData::findDialogue(const char* name) {
		return reinterpret_cast<Dialogue*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findDialogue)(this, name);
	}

	Sound* NonDynamicData::findSound(const char* id) {
		return reinterpret_cast<Sound*(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_findSound)(this, id);
	}

	const auto TES3_NonDynamicData_findFaction = reinterpret_cast<Faction *(__thiscall*)(NonDynamicData*, const char*)>(0x4BA750);
	Faction* NonDynamicData::findFaction(const char* id) {
		return TES3_NonDynamicData_findFaction(this, id);
	}

	bool NonDynamicData::addNewObject(BaseObject* object) {
		return reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_addNewObject)(this, object);
	}

	void NonDynamicData::deleteObject(BaseObject* object) {
		reinterpret_cast<void(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_deleteObject)(this, object);
	}

	const auto TES3_NonDynamicData_getCellByGrid = reinterpret_cast<Cell *(__thiscall*)(NonDynamicData*, int, int)>(0x4BAA10);
	Cell * NonDynamicData::getCellByGrid(int x, int y) {
		return TES3_NonDynamicData_getCellByGrid(this, x, y);
	}

	const auto TES3_NonDynamicData_getCellByName = reinterpret_cast<Cell *(__thiscall*)(NonDynamicData*, const char*)>(0x4BA9B0);
	Cell * NonDynamicData::getCellByName(const char* name) {
		return TES3_NonDynamicData_getCellByName(this, name);
	}

	const auto TES3_NonDynamicData_meshes_loadMesh = reinterpret_cast<NI::AVObject *(__thiscall*)(HashMap*, const char *)>(0x4EE0A0);

	NI::Pointer<NI::Object> NonDynamicData::loadMesh(const char* path) {
		return TES3_NonDynamicData_meshes_loadMesh(meshes, path);
	}

	//
	// DataHandler
	//

	DataHandler * DataHandler::get() {
		return *reinterpret_cast<TES3::DataHandler**>(0x7C67E0);
	}

	void DataHandler::addSound(Sound* sound, Reference* reference, int playbackFlags, unsigned char volume, float pitch, bool isVoiceover, int unknown) {
		reinterpret_cast<void(__thiscall *)(DataHandler*, Sound*, Reference*, int, unsigned char, float, int, int)>(TES3_DataHandler_addSound)(this, sound, reference, playbackFlags, volume, pitch, isVoiceover, unknown);
	}

	Sound* DataHandler::addSound(const char* soundId, Reference* reference, int playbackFlags, unsigned char volume, float pitch, int unknown) {
		return reinterpret_cast<Sound*(__thiscall *)(DataHandler*, const char*, Reference*, int, unsigned char, float, int)>(TES3_DataHandler_addSoundByName)(this, soundId, reference, playbackFlags, volume, pitch, unknown);
	}

	SoundEvent* DataHandler::getSoundPlaying(Sound* sound, Reference* reference) {
		return reinterpret_cast<SoundEvent*(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_getSoundPlaying)(this, sound, reference);
	}

	void DataHandler::adjustSoundVolume(Sound* sound, Reference* reference, unsigned char volume) {
		SoundEvent* e = getSoundPlaying(sound, reference);
		if (e) {
			// Active buffer differs between sounds and temp sounds
			SoundBuffer* buffer = e->soundBuffer ? e->soundBuffer : e->sound->soundBuffer;
			reinterpret_cast<void(__stdcall*)(SoundBuffer*, unsigned char)>(TES3_Audio_setBufferVolume)(buffer, volume);
		}
	}

	void DataHandler::removeSound(Sound* sound, Reference* reference) {
		reinterpret_cast<void(__thiscall *)(DataHandler*, Sound*, Reference*)>(TES3_DataHandler_removeSound)(this, sound, reference);
	}

}
