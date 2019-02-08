#pragma once

#include <stddef.h>
#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3MagicEffect.h"
#include "TES3Skill.h"

#include "NIAVObject.h"
#include "NIPointer.h"

namespace TES3 {
	enum class LoadGameResult {
		Failure = 0x0,
		Success = 0x1,
		Block = 0x2
	};

	struct NonDynamicData {
		long unknown_0x00;
		long unknown_0x04; // always 0?
		void * unknown_0x08; // Points to info about the last loaded save?
		LinkedList<Object> * list; // 0x0C
		LinkedList<Spell> * spellsList; // 0x10
		HashMap * meshes; // 0x14
		GameSetting ** GMSTs; // 0x18 // Pointer to array of GMST pointers.
		Iterator<Race> * races; // 0x1C
		Iterator<LandTexture> * landTextures; // 0x20
		Iterator<Class> * classes; // 0x24
		Iterator<Faction> * factions; // 0x28
		Iterator<Script> * scripts; // 0x2C
		Iterator<Sound> * sounds; // 0x30
		Iterator<SoundGenerator> * soundGenerators; // 0x34
		Iterator<GlobalVariable> * globals; // 0x38
		Iterator<Dialogue> * dialogues; // 0x3C
		Iterator<Region> * regions; // 0x40
		Iterator<void> * birthsigns; // 0x44
		Iterator<StartScript> * startScripts; // 0x48
		Skill skills[27]; // 0x4C
		MagicEffect magicEffects[143]; // 0x5C8
		void * lights; // 0x9DB8
		int unknown_0x9DBC[600];
		void * unknown_0xA71C[4];
		int unknown_0xA72C[4];
		int unknown_0xA73C[450];
		void * unknown_0xAE44[3];
		int unknown_0xAE50;
		int unknown_0xAE54;
		int unknown_0xAE58;
		int sgWireframeProperty; // 0xAE5C
		void * TESFiles; // 0xAE60
		GameFile * activeMods[256]; // 0xAE64
		StlList<Cell> * cells; // 0xB264
		HashMap * allObjectsById; // 0xB268
		HashMap * unknown_0xB26C;
		char dataFilesPath[260]; // 0xB270
		char unknown_0xB374;
		char unknown_0xB375;
		char unknown_0xB376;
		char unknown_0xB377;
		char unknown_0xB378;
		char unknown_0xB379;
		char unknown_0xB37A;
		Iterator<void> * unknown_0xB37C;
		NI::Pointer<NI::SourceTexture> mapTexture; // 0xB380
		Reference * playerSaveGame; // 0xB384
		int unknown_0xB388;
		int unknown_0xB38C;
		int unknown_0xB390;
		int unknown_0xB394;
		int unknown_0xB398;
		int unknown_0xB39C;
		int unknown_0xB3A0;
		int unknown_0xB3A4;
		int unknown_0xB3A8;

		//
		// Other related this-call functions.
		//

		__declspec(dllexport) bool saveGame(const char* fileName, const char* saveName);
		__declspec(dllexport) LoadGameResult loadGame(const char* fileName);
		__declspec(dllexport) LoadGameResult loadGameMainMenu(const char* fileName);

		__declspec(dllexport) BaseObject* resolveObject(const char*);
		__declspec(dllexport) Reference* findFirstCloneOfActor(const char*);
		__declspec(dllexport) Spell* getSpellById(const char*);
		__declspec(dllexport) Script* findScriptByName(const char*);
		__declspec(dllexport) GlobalVariable* findGlobalVariable(const char*);
		__declspec(dllexport) Dialogue* findDialogue(const char*);
		__declspec(dllexport) Sound* findSound(const char*);
		__declspec(dllexport) Faction* findFaction(const char*);
		__declspec(dllexport) bool addNewObject(BaseObject*);
		__declspec(dllexport) void deleteObject(BaseObject*);

		__declspec(dllexport) Cell * getCellByGrid(int x, int y);
		__declspec(dllexport) Cell * getCellByName(const char* name);

		//
		// Custom functions.
		//

		// Path is relative to Data Files.
		NI::Pointer<NI::Object> loadMesh(const char* path);

		// Wrapper around resolveObject that enforces type.
		template <typename T>
		__declspec(dllexport) T * resolveObjectByType(const char* id, ObjectType::ObjectType type = ObjectType::Invalid) {
			TES3::BaseObject* potentialResult = resolveObject(id);
			if (!potentialResult) {
				return nullptr;
			}
			else if (type != 0 && potentialResult->objectType != type) {
				return nullptr;
			}

			return static_cast<T*>(potentialResult);
		}

		template <typename T>
		__declspec(dllexport) T* resolveObjectByType(const std::string& id, ObjectType::ObjectType type = ObjectType::Invalid) {
			return resolveObjectByType<T>(id.c_str(), type);
		}
	};
	static_assert(sizeof(NonDynamicData) == 0xB3AC, "TES3::NonDynamicData failed size validation");
	static_assert(offsetof(NonDynamicData, spellsList) == 0x10, "TES3::NonDynamicData failed offset validation");
	static_assert(offsetof(NonDynamicData, GMSTs) == 0x18, "TES3::NonDynamicData failed offset validation");
	static_assert(offsetof(NonDynamicData, skills) == 0x4C, "TES3::NonDynamicData failed offset validation");
	static_assert(offsetof(NonDynamicData, magicEffects) == 0x5C8, "TES3::NonDynamicData failed offset validation");
	static_assert(offsetof(NonDynamicData, TESFiles) == 0xAE60, "TES3::NonDynamicData failed offset validation");

	struct SoundEvent {
		Reference* reference;
		Sound* sound;
		SoundBuffer* soundBuffer;
		unsigned char unknown_0xC;
	};
	static_assert(sizeof(SoundEvent) == 0x10, "TES3::SoundEvent failed size validation");

	namespace CellGrid {
		enum CellGrid {
			NorthWest = 0,
			North = 1,
			NorthEast = 2,
			West = 3,
			Center = 4,
			East = 5,
			SouthWest = 6,
			South = 7,
			SouthEast = 8
		};
	}

	struct DataHandler {
		NonDynamicData * nonDynamicData; // 0x0
		CellExteriorData* exteriorCellData[9]; // 0x4
		void * unknown_0x28[25]; // 0x28
		NI::Node * worldObjectRoot; // 0x8C
		void * worldPickObjectRoot; // 0x90
		void * worldLandscapeRoot; // 0x94
		void * sgSunlight;
		void * sgFogProperty;
		int centralGridX; // 0xA0
		int centralGridY; // 0xA4
		bool cellChanged; // 0xA8
		char padding_0xA9[3];
		Cell * currentInteriorCell; // 0xAC
		Cell ** interiorCellBuffer; // 0xB0
		Cell ** exteriorCellBuffer; // 0xB4
		int unknown_0xB8;
		int unknown_0xBC;
		Iterator<void> collisionGrid[2304]; // 0xC0
		int collision_0xB4C0;
		int collision_0xB4C4;
		int collision_0xB4C8;
		int collision_0xB4CC;
		Iterator<SoundEvent>* soundEvents; // 0xB4D0
		Iterator<SoundEvent>* tempSoundEvents; // 0xB4D4
		Iterator<SoundEvent>* lightSoundEvents; // 0xB4D8
		bool showActorDrawBounds; // 0xB4DC
		char unknown_0xB4DD;
		char unknown_0xB4DE;
		char unknown_0xB4DF;
		char unknown_0xB4E0;
		char unknown_0xB4E1;
		char unknown_0xB4E2;
		char unknown_0xB4E3;
		char unknown_0xB4E4;
		char unknown_0xB4E5;
		char unknown_0xB4E6;
		char unknown_0xB4E7;
		char unknown_0xB4E8;
		char unknown_0xB4E9;
		char unknown_0xB4EA;
		char unknown_0xB4EB;
		int unknown_0xB4EC;
		int unknown_0xB4F0;
		int unknown_0xB4F4;
		char unknown_0xB4F8;
		char unknown_0xB4F9;
		char unknown_0xB4FA;
		char unknown_0xB4FB;
		int backgroundThreadID; // 0xB4FC
		int mainThreadID; // 0xB500
		int backgroundThread; // 0xB504
		int mainThread; // 0xB508
		char unknown_0xB50C;
		char unknown_0xB50D;
		char unknown_0xB50E;
		char unknown_0xB50F;
		char unknown_0xB510;
		bool backgroundThreadRunning; // 0xB511
		char unknown_0xB512;
		char unknown_0xB513;
		int unknown_0xB514;
		char unknown_0xB518;
		char unknown_0xB519;
		char unknown_0xB51A;
		char unknown_0xB51B;
		int threadSleepTime; // 0xB51C
		int unknown_0xB520; // Time interval?
		char unknown_0xB524;
		char unknown_0xB525;
		char unknown_0xB526;
		char unknown_0xB527;
		float unknown_0xB528;
		float unknown_0xB52C;
		char unknown_0xB530;
		char unknown_0xB531;
		char unknown_0xB532;
		char unknown_0xB533;
		char unknown_0xB534;
		char unknown_0xB535;
		char unknown_0xB536;
		char unknown_0xB537;
		int criticalSection; // 0xB538
		char unknown_0xB53C;
		char unknown_0xB53D;
		char unknown_0xB53E;
		char unknown_0xB53F;
		Cell * currentCell; // 0xB540
		Cell * lastExteriorCell; // 0xB544
		char unknown_0xB548;
		char unknown_0xB549;
		char unknown_0xB54A;
		char unknown_0xB54B;
		char unknown_0xB54C;
		char unknown_0xB54D;
		char unknown_0xB54E;
		char unknown_0xB54F;
		long exteriorCellDataBufferSize; // 0xB550
		void * exteriorCellDataBuffer; // 0xB554

		// Get singleton.
		_declspec (dllexport) static DataHandler * get();

		//
		// Other related this-call functions.
		//

		void addSound(Sound* sound, Reference* reference = nullptr, int playbackFlags = 0, unsigned char volume = 250, float pitch = 1.0, bool isVoiceover = false, int unknown = 0);
		Sound* addSound(const char* soundId, Reference* reference = 0, int playbackFlags = 0, unsigned char volume = 250, float pitch = 1.0, int unknown = 0);
		SoundEvent* getSoundPlaying(Sound*, Reference*);
		void adjustSoundVolume(Sound*, Reference*, unsigned char volume);
		void removeSound(Sound*, Reference*);

	};
	static_assert(sizeof(DataHandler) == 0xB558, "TES3::DataHandler failed size validation");
	static_assert(offsetof(DataHandler, worldObjectRoot) == 0x8C, "TES3::DataHandler failed offset validation");
	static_assert(offsetof(DataHandler, cellChanged) == 0xA8, "TES3::DataHandler failed offset validation");
	static_assert(offsetof(DataHandler, currentInteriorCell) == 0xAC, "TES3::DataHandler failed offset validation");
	static_assert(offsetof(DataHandler, soundEvents) == 0xB4D0, "TES3::DataHandler failed offset validation");
	static_assert(offsetof(DataHandler, backgroundThreadID) == 0xB4FC, "TES3::DataHandler failed offset validation");
	static_assert(offsetof(DataHandler, currentCell) == 0xB540, "TES3::DataHandler failed offset validation");
}
