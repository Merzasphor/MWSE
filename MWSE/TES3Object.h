#pragma once

#include "NIDefines.h"
#include "TES3Defines.h"

#include "TES3Collections.h"

#include "Bitset.h"

#include <string>

namespace TES3 {

	//
	// Object types. They are char[4], or can be interpreted as a 32-bit integer.
	//

	namespace ObjectType {
		enum ObjectType {
			Invalid = 0,
			Activator = 'ITCA',
			Alchemy = 'HCLA',
			Ammo = 'OMMA',
			Apparatus = 'APPA',
			Armor = 'OMRA',
			Birthsign = 'NGSB',
			Bodypart = 'YDOB',
			Book = 'KOOB',
			Cell = 'LLEC',
			Class = 'SALC',
			Clothing = 'TOLC',
			Container = 'TNOC',
			Creature = 'AERC',
			Dialogue = 'LAID',
			DialogueInfo = 'OFNI',
			Door = 'ROOD',
			Enchantment = 'HCNE',
			Faction = 'TCAF',
			GameSetting = 'TSMG',
			Global = 'BOLG',
			Ingredient = 'RGNI',
			Land = 'DNAL',
			LandTexture = 'XETL',
			LeveledCreature = 'CVEL',
			LeveledItem = 'IVEL',
			Light = 'HGIL',
			Lockpick = 'KCOL',
			MagicEffect = 'FEGM',
			MagicSourceInstance = 'LLPS',
			Misc = 'CSIM',
			MobileCreature = 'RCAM',
			MobileNPC = 'HCAM',
			MobileObject = 'TCAM',
			MobilePlayer = 'PCAM',
			MobileProjectile = 'JRPM',
			NPC = '_CPN',
			Quest = 'SEUQ',
			PathGrid = 'DRGP',
			Probe = 'BORP',
			Race = 'ECAR',
			Reference = 'RFER',
			Region = 'NGER',
			Repair = 'APER',
			Script = 'TPCS',
			Skill = 'LIKS',
			Sound = 'NUOS',
			SoundGenerator = 'GDNS',
			Spell = 'LEPS',
			Static = 'TATS',
			TES3 = '3SET',
			Weapon = 'PAEW',
		};
	}

	//
	// Enums
	//

	namespace ObjectFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Modified = 0x2,
			LinksResolved = 0x8,
			Delete = 0x20,
			Persistent = 0x400,
			Disabled = 0x800,
			SelectedByConsole = 0x1000,
			EmptyInventory = 0x2000
		};

		enum FlagBit {
			ModifiedBit = 1,
			LinksResolvedBit = 3,
			DeleteBit = 5,
			PersistentBit = 10,
			DisabledBit = 11,
			SelectedByConsoleBit = 12,
			EmptyInventoryBit = 13
		};
	}

	//
	// The core building blocks of TES3 objects.
	//

	struct BaseObjectVirtualTable {
		void (__thiscall * destructor)(BaseObject*, signed char); // 0x0
		int (__thiscall * loadObjectSpecific)(BaseObject*, GameFile*); // 0x4
		int (__thiscall * saveRecordSpecific)(BaseObject*, GameFile*); // 0x8
		int (__thiscall * loadObject)(BaseObject*, GameFile*); // 0xC
		int (__thiscall * saveObject)(BaseObject*, GameFile*); // 0x10
		void (__thiscall * setObjectModified)(BaseObject*, bool); // 0x14
		int (__thiscall * setObjectFlag40)(BaseObject*, unsigned char); // 0x18
		void * unknown_0x1C;
		char * (__thiscall * getObjectID)(BaseObject*); // 0x20
	};
	static_assert(sizeof(BaseObjectVirtualTable) == 0x24, "TES3::BaseObjectVirtualTable failed size validation");

	struct ObjectVirtualTable : BaseObjectVirtualTable {
		void * copyEntity;
		void (__thiscall * setID)(BaseObject*, const char*); // 0x10C
		NI::Node * (__thiscall * getSceneGraphNode)(BaseObject*); // 0x110
		void * unknown_0x30;
		void * unknown_0x34;
		char * (__thiscall * getName)(BaseObject*); // 0x38
		char * (__thiscall * getIconPath)(BaseObject*); // 0x3C
		void * unknown_0x40;
		void * unknown_0x44;
		char * (__thiscall * getModelPath)(BaseObject*); // 0x48
		Script * (__thiscall * getScript)(BaseObject*); // 0x4C
		Sound * (__thiscall * getSound)(BaseObject*); // 0x50
		char * (__thiscall * getRaceID)(BaseObject*); // 0x54
		char * (__thiscall * getClassID)(BaseObject*); // 0x58
		char * (__thiscall * getBirthsignID)(BaseObject*); // 0x5C
		Race * (__thiscall * getRace)(BaseObject*); // 0x60
		Class * (__thiscall * getClass)(BaseObject*); // 0x64
		Faction * (__thiscall * getFaction)(BaseObject*); // 0x68
		bool (__thiscall * isFemale)(BaseObject*); // 0x6C
		int (__thiscall * getFactionRank)(BaseObject*); // 0x70
		int (__thiscall * getLevel)(BaseObject*); // 0x74
		void * unknown_0x78;
		signed char (__thiscall * setDispositionRaw)(BaseObject*, signed char); // 0x7C
		int (__thiscall * modDisposition)(BaseObject*, signed int); // 0x80
		int (__thiscall * getFactionIndex)(BaseObject*); // 0x84
		signed char (__thiscall * setFactionIndex)(BaseObject*, signed char); // 0x88
		int (__thiscall * getDispositionRaw)(BaseObject*); // 0x8C
		signed char(__thiscall * modFactionIndex)(BaseObject*, signed char); // 0x90
		int (__thiscall * getType)(BaseObject*); // 0x94
		char * (__thiscall * getTypeName)(BaseObject*); // 0x98
		float (__thiscall * getWeight)(BaseObject*); // 0x9C
		int (__thiscall * getValue)(BaseObject*); // 0xA0
		void (__thiscall * setDurability)(BaseObject*, int); // 0xA4
		int (__thiscall * getDurability)(BaseObject*); // 0xA8
		int (__thiscall * getMagicka)(BaseObject*); // 0xAC
		int (__thiscall * getFatigue)(BaseObject*); // 0xB0
		float (__thiscall * getQuality)(BaseObject*); // 0xB4
		bool (__thiscall * isLeftPartOfPair)(BaseObject*); // 0xB8
		bool (__thiscall * isEssential)(BaseObject*); // 0xBC
		bool (__thiscall * isRespawn)(BaseObject*); // 0xC0
		void * unknown_0xC4;
		int (__thiscall * getUses)(BaseObject*); // 0xC8
		int (__thiscall * getEnchantCapacity)(BaseObject*);  // 0xCC
		Enchantment * (__thiscall * getEnchantment)(BaseObject*); // 0xD0
		Enchantment * (__thiscall * setEnchantment)(BaseObject*, Enchantment*); // 0xD4
		AIConfig * (__thiscall * getAIConfig)(BaseObject*); // 0xD8
		void * (__thiscall * getAIPackageList)(BaseObject*); // 0xDC
		void * resolveInternalIDs; // 0xE0
		void * unknown_0xE4;
		unsigned char (__thiscall * getAutoCalc)(BaseObject*); // 0xE8
		void (__thiscall * setAutoCalc)(BaseObject*, unsigned char); // 0xEC
		void * unknown_0xF0;
		void * unknown_0xF4;
		void * unknown_0xF8;
		char* (__thiscall * setModelPath)(BaseObject*, const char*); // 0xFC
		void * unknown_0x100;
		void * unknown_0x104;
		void * isLocationMarker; // 0x108
		char* (__thiscall * setName)(BaseObject*, const char*); // 0x10C
		void * unknown_0x110;
		void * unknown_0x114;
		void * unknown_0x118;
		void * unknown_0x11C;
		float (__thiscall * getScale)(BaseObject*); // 0x120
		void (__thiscall * setScale)(BaseObject*, float, bool); // 0x124
		void * unknown_0x128;
		void * unknown_0x12C;
		void * unknown_0x130;
		void * loadModel; // 0x134
		void * unknown_0x138;
	};
	static_assert(sizeof(ObjectVirtualTable) == 0x13C, "TES3::ObjectVirtualTable failed size validation");

	struct BaseObject {
		union {
			BaseObjectVirtualTable * base;
			ObjectVirtualTable * object;
			PhysicalObjectVirtualTable * physical;
			ActorVirtualTable * actor;
		} vTable; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		mwse::bitset32 objectFlags; // 0x8
		GameFile * sourceMod; // 0xC

		//
		// Basic operators.
		//

		__declspec(dllexport) static void *operator new(size_t size);
		__declspec(dllexport) static void operator delete(void *block);

		//
		// Function wrappers for our virtual table.
		//

		__declspec(dllexport) bool getObjectModified();
		__declspec(dllexport) void setObjectModified(bool);
		__declspec(dllexport) char * getObjectID();

		//
		// Custom functions.
		//

		BaseObject * getBaseObject();

		bool isActor();

	};
	static_assert(sizeof(BaseObject) == 0x10, "TES3::BaseObject failed size validation");

	struct Object : BaseObject {
		NI::Node * sceneNode; // 0x10
		union {
			TES3::LinkedList<TES3::Spell> * asSpellList;
			ReferenceList * asReferenceList;
		} owningCollection; // 0x14
		void * referenceToThis; // 0x18
		Object * previousInCollection; // 0x1C
		Object * nextInCollection; // 0x20
		NI::Node * sceneCollisionRoot; // 0x24

		//
		// Function wrappers for our virtual table.
		//

		__declspec(dllexport) void setID(const char*);
		__declspec(dllexport) char * getName();
		__declspec(dllexport) char * getIconPath();
		__declspec(dllexport) char * getModelPath();
		__declspec(dllexport) Script * getScript();
		__declspec(dllexport) Sound * getSound();
		__declspec(dllexport) char * getRaceID();
		__declspec(dllexport) char * getClassID();
		__declspec(dllexport) char * getBirthsignID();
		__declspec(dllexport) Race * getRace();
		__declspec(dllexport) Class * getClass();
		__declspec(dllexport) Faction * getFaction();
		__declspec(dllexport) bool isFemale();
		__declspec(dllexport) int getFactionRank();
		__declspec(dllexport) int getLevel();
		__declspec(dllexport) signed char setDispositionRaw(signed char);
		__declspec(dllexport) int modDisposition(signed int);
		__declspec(dllexport) int getFactionIndex();
		__declspec(dllexport) signed char setFactionIndex(signed char);
		__declspec(dllexport) int getDispositionRaw();
		__declspec(dllexport) signed char modFactionIndex(signed char);
		__declspec(dllexport) int getType();
		__declspec(dllexport) char * getTypeName();
		__declspec(dllexport) float getWeight();
		__declspec(dllexport) int getValue();
		__declspec(dllexport) void setDurability(int);
		__declspec(dllexport) int getDurability();
		__declspec(dllexport) int getMagicka();
		__declspec(dllexport) int getFatigue();
		__declspec(dllexport) float getQuality();
		__declspec(dllexport) bool isLeftPartOfPair();
		__declspec(dllexport) bool isEssential();
		__declspec(dllexport) bool isRespawn();
		__declspec(dllexport) int getUses();
		__declspec(dllexport) Enchantment * getEnchantment();
		__declspec(dllexport) Enchantment * setEnchantment(Enchantment*);
		__declspec(dllexport) AIConfig * getAIConfig();
		__declspec(dllexport) bool getAutoCalc();
		__declspec(dllexport) void setAutoCalc(bool);
		__declspec(dllexport) void setModelPath(const char*);
		__declspec(dllexport) void setName(const char*);
		__declspec(dllexport) float getScale();
		__declspec(dllexport) void setScale(float value, bool cap = false);

		//
		// Function wrappers for our virtual table.
		//

		__declspec(dllexport) NI::Node * getSceneGraphNode();

		//
		// Custom functions.
		//

		__declspec(dllexport) Object * skipDeletedObjects();

	};
	static_assert(sizeof(Object) == 0x28, "TES3::Object failed size validation");

	struct PhysicalObjectVirtualTable : ObjectVirtualTable {
		void * unknown_0x13C;
		void * unknown_0x140;
		Iterator<BaseObject> * (__thiscall * getStolenList)(PhysicalObject*); // 0x144
	};

	struct PhysicalObject : Object {
		BoundingBox * boundingBox; // 0x28
		char * objectID; // 0x2C

		//
		// Function wrappers for our virtual table.
		//

		__declspec(dllexport) Iterator<BaseObject> * getStolenList();

	};
	static_assert(sizeof(PhysicalObject) == 0x30, "TES3::PhysicalObject failed size validation");
}
