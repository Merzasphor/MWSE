#include "TES3DataHandler.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "LuaLoadGameEvent.h"
#include "LuaLoadedGameEvent.h"
#include "LuaMeshLoadedEvent.h"
#include "LuaSaveGameEvent.h"
#include "LuaSavedGameEvent.h"

#include "TES3Util.h"

#include "TES3DialogueInfo.h"
#include "TES3MagicEffectController.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3Sound.h"
#include "TES3Spell.h"
#include "TES3WorldController.h"
#include "TES3UIManager.h"

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

	Cell* DataHandler::previousVisitedCell = nullptr;

	//
	// MeshData
	//

	const auto TES3_MeshData_loadMesh = reinterpret_cast<NI::AVObject *(__thiscall*)(MeshData*, const char *)>(0x4EE0A0);
	NI::AVObject * MeshData::loadMesh(const char* path) {
		auto countBefore = NIFs->count;
		auto mesh = TES3_MeshData_loadMesh(this, path);
		if (mesh && NIFs->count > countBefore && mwse::lua::event::MeshLoadedEvent::getEventEnabled()) {
			mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::MeshLoadedEvent(path, mesh));
		}
		return mesh;
	}

	const auto TES3_MeshData_loadKeyFrame = reinterpret_cast<KeyframeDefinition * (__thiscall*)(MeshData*, const char*, const char*)>(0x4EE200);
	KeyframeDefinition* MeshData::loadKeyFrame(const char* path, const char* animation) {
		return TES3_MeshData_loadKeyFrame(this, path, animation);
	}

	//
	// NonDynamicData
	//

	bool NonDynamicData::saveGame(const char* fileName, const char* saveName) {
		std::string eventFileName = fileName ? fileName : "";
		std::string eventSaveName = saveName;

		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		if (mwse::lua::event::SaveGameEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::SaveGameEvent(saveName, fileName));
			if (eventData.valid() && eventData["block"] == true) {
				return true;
			}

			// Fetch the names back from the event data, in case the event changed them.
			eventFileName = eventData["filename"];
			eventSaveName = eventData["name"];
		}

		bool saved = reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, const char*, const char*)>(TES3_NonDynamicData_saveGame)(this, eventFileName.c_str(), eventSaveName.c_str());

		// Pass a follow-up event if we successfully saved.
		if (saved && mwse::lua::event::SavedGameEvent::getEventEnabled()) {
			luaManager.getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::SavedGameEvent(eventSaveName.c_str(), eventFileName.c_str()));
		}

		return saved;
	}

	LoadGameResult NonDynamicData::loadGame(const char* fileName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		std::string eventFileName = fileName ? fileName : "";

		if (mwse::lua::event::LoadGameEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::LoadGameEvent(fileName));
			if (eventData.valid() && eventData["block"] == true) {
				return LoadGameResult::Block;
			}

			// Fetch the names back from the event data, in case the event changed them.
			// Also add back in the .ess extension.
			eventFileName = eventData["filename"];
			eventFileName += ".ess";
		}

		bool loaded = reinterpret_cast<bool(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_loadGameInGame)(this, eventFileName.c_str());

		// Pass a follow-up event if we successfully loaded and clear timers.
		if (loaded) {
			DataHandler::previousVisitedCell = nullptr;
			luaManager.clearTimers();

			if (mwse::lua::event::LoadedGameEvent::getEventEnabled()) {
				luaManager.getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::LoadedGameEvent(eventFileName.c_str(), fileName == NULL));
			}

			// Extra things we want to do if we're successfully loading.
			TES3::UI::setSuppressingHelpMenu(false);
		}

		return loaded ? LoadGameResult::Success : LoadGameResult::Failure;
	}

	LoadGameResult NonDynamicData::loadGameMainMenu(const char* fileName) {
		// Execute event. If the event blocked the call, bail.
		mwse::lua::LuaManager& luaManager = mwse::lua::LuaManager::getInstance();
		std::string eventFileName = fileName ? fileName : "";

		if (mwse::lua::event::LoadGameEvent::getEventEnabled()) {
			auto stateHandle = luaManager.getThreadSafeStateHandle();
			sol::table eventData = stateHandle.triggerEvent(new mwse::lua::event::LoadGameEvent(fileName));
			if (eventData.valid() && eventData["block"] == true) {
				return LoadGameResult::Block;
			}

			// Fetch the names back from the event data, in case the event changed them.
			// Also add back in the .ess extension.
			eventFileName = eventData["filename"];
			eventFileName += ".ess";
		}

		bool loaded = reinterpret_cast<bool(__thiscall *)(NonDynamicData*, const char*)>(TES3_NonDynamicData_loadGameMainMenu)(this, eventFileName.c_str());

		// Pass a follow-up event if we successfully loaded and clear timers.
		if (loaded) {
			DataHandler::previousVisitedCell = nullptr;
			luaManager.clearTimers();

			if (mwse::lua::event::LoadedGameEvent::getEventEnabled()) {
				luaManager.getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::LoadedGameEvent(eventFileName.c_str()));
			}

			// Extra things we want to do if we're successfully loading.
			TES3::UI::setSuppressingHelpMenu(false);
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

	const auto TES3_NonDynamicData_findClosestExteriorReferenceOfObject = reinterpret_cast<Reference * (__thiscall*)(NonDynamicData*, PhysicalObject*, Vector3*, bool, int)>(0x4B96F0);
	Reference* NonDynamicData::findClosestExteriorReferenceOfObject(PhysicalObject* object, Vector3* position, bool isRecursiveCall, int ignored)
	{
		return TES3_NonDynamicData_findClosestExteriorReferenceOfObject(this, object, position, isRecursiveCall, ignored);
	}

	bool NonDynamicData::addNewObject(BaseObject* object) {
		return reinterpret_cast<signed char(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_addNewObject)(this, object);
	}

	void NonDynamicData::deleteObject(BaseObject* object) {
		reinterpret_cast<void(__thiscall *)(NonDynamicData*, BaseObject*)>(TES3_NonDynamicData_deleteObject)(this, object);
	}

	const auto TES3_NonDynamicData_respawnContainers = reinterpret_cast<void(__thiscall*)(NonDynamicData*)>(0x4C3B00);
	void NonDynamicData::respawnContainers() {
		TES3_NonDynamicData_respawnContainers(this);
	}

	const auto TES3_NonDynamicData_getCellByGrid = reinterpret_cast<Cell *(__thiscall*)(NonDynamicData*, int, int)>(0x4BAA10);
	Cell * NonDynamicData::getCellByGrid(int x, int y) {
		return TES3_NonDynamicData_getCellByGrid(this, x, y);
	}

	const auto TES3_NonDynamicData_getCellByName = reinterpret_cast<Cell *(__thiscall*)(NonDynamicData*, const char*)>(0x4BA9B0);
	Cell * NonDynamicData::getCellByName(const char* name) {
		return TES3_NonDynamicData_getCellByName(this, name);
	}

	const auto TES3_NonDynamicData_getRegionById = reinterpret_cast<Region * (__thiscall*)(NonDynamicData*, const char*)>(0x4BA610);
	Region* NonDynamicData::getRegion(const char* id) {
		return TES3_NonDynamicData_getRegionById(this, id);
	}

	MagicEffect * NonDynamicData::getMagicEffect(int id) {
		return magicEffects->getEffectObject(id);
	}

	const auto TES3_NonDynamicData_createReference = reinterpret_cast<float(__thiscall*)(NonDynamicData*, PhysicalObject*, Vector3*, Vector3*, bool&, Reference*, Cell*)>(0x4C0E80);
	float NonDynamicData::createReference(PhysicalObject * object, Vector3 * position, Vector3 * orientation, bool& cellWasCreated, Reference * existingReference, Cell * cell) {
		return TES3_NonDynamicData_createReference(this, object, position, orientation, cellWasCreated, existingReference, cell);
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

	const auto TES3_DataHandler_addTemporySound = reinterpret_cast<void(__thiscall*)(DataHandler*, const char*, Reference*, int, int, float, bool, Sound*)>(0x48C2B0);
	void DataHandler::addTemporySound(const char* path, Reference * reference, int playbackFlags, int volume, float pitch, bool isVoiceover, Sound * sound) {
		TES3_DataHandler_addTemporySound(this, path, reference, playbackFlags, volume, pitch, isVoiceover, sound);
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

	const auto TES3_DataHandler_loadSourceTexture = reinterpret_cast<NI::SourceTexture*(__thiscall*)(TES3::DataHandler*, const char*)>(0x48DB60);
	NI::Pointer<NI::SourceTexture> DataHandler::loadSourceTexture(const char* path) {
		return TES3_DataHandler_loadSourceTexture(this, path);
	}

	const auto TES3_DataHandler_updateLightingForReference = reinterpret_cast<void(__thiscall*)(TES3::DataHandler *, TES3::Reference *)>(0x485E40);
	void DataHandler::updateLightingForReference(Reference * reference) {
		TES3_DataHandler_updateLightingForReference(this, reference);
	}

	const auto TES3_DataHandler_setDynamicLightingForReference = reinterpret_cast<void(__thiscall*)(DataHandler*, Reference*)>(0x485B00);
	void DataHandler::setDynamicLightingForReference(Reference* reference) {
		TES3_DataHandler_setDynamicLightingForReference(this, reference);
	}

	const auto TES3_DataHandler_updateCollisionGroupsForActiveCells = reinterpret_cast<void(__thiscall*)(DataHandler*, bool)>(0x488950);
	void DataHandler::updateCollisionGroupsForActiveCells(bool unknown) {
		TES3_DataHandler_updateCollisionGroupsForActiveCells(this, unknown);
	}

}
