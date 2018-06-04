#pragma once

#include "NIDefines.h"
#include "TES3Collections.h"

namespace TES3 {

	//
	// Object types. They are char[4], or can be interpreted as a 32-bit integer.
	//

	namespace ObjectType {
		enum ObjectType {
			Activator = 'ITCA',
			Alchemy = 'HCLA',
			Ammo = 'OMMA',
			Apparatus = 'APPA',
			Armor = 'OMRA',
			Book = 'KOOB',
			Bodypart = 'YDOB',
			Birthsign = 'NGSB',
			Cell = 'LLEC',
			Class = 'SALC',
			Clothing = 'TOLC',
			Container = 'TNOC',
			Creature = 'AERC',
			Dialog = 'GAID',
			Door = 'ROOD',
			Enchantment = 'HCNE',
			Faction = 'TCAF',
			Global = 'BOLG',
			GameSetting = 'TSMG',
			DialogInfo = 'OFNI',
			Ingredient = 'RGNI',
			Land = 'DNAL',
			LeveledCreature = 'CVEL',
			LeveledItem = 'IVEL',
			Light = 'HGIL',
			Lockpick = 'KCOL',
			LandTexture = 'XETL',
			MobileObject = 'TCAM',
			MobileNPC = 'HCAM',
			MobileCreature = 'RCAM',
			MobilePlayer = 'PCAM',
			MobileProjectile = 'JRPM',
			Misc = 'CSIM',
			MagicEffect = 'FEGM',
			NPC = '_CPN',
			PathGrid = 'DRGP',
			Probe = 'BORP',
			Race = 'ECAR',
			Reference = 'RFER',
			Region = 'NGER',
			Repair = 'APER',
			Script = 'TPCS',
			Skill = 'LIKS',
			SoundGenerator = 'GDNS',
			Sound = 'NUOS',
			Spell = 'LEPS',
			MagicSourceInstance = 'LLPS',
			Static = 'TATS',
			TES3 = '3SET',
			Weapon = 'PAEW',
		};
	}

	//
	// Enums
	//

	namespace ObjectFlag {
		enum ObjectFlag {
			Modified = 0x2,
			LinksResolved = 0x8,
			Delete = 0x20,
			Persistent = 0x400,
			Disabled = 0x800,
			EmptyInventory = 0x2000
		};
	}

	namespace ObjectFlagBit {
		enum ObjectFlagBit {
			ModifiedBit = 1,
			LinksResolvedBit = 3,
			DeleteBit = 5,
			PersistentBit = 10,
			DisabledBit = 11,
			EmptyInventoryBit = 13
		};
	}

	//
	// Forward declaration of all the types.
	//

	struct Activator;
	struct Actor;
	struct ActorAnimationData;
	struct ActorVirtualTable;
	struct AIConfig;
	struct Alchemy;
	struct Apparatus;
	struct Armor;
	struct BaseObject;
	struct BaseObjectVirtualTable;
	struct Bodypart;
	struct Book;
	struct BoundingBox;
	struct Cell;
	struct CellExteriorData;
	struct Class;
	struct Clothing;
	struct Container;
	struct ContainerInstance;
	struct Creature;
	struct CreatureInstance;
	struct DataHandler;
	struct DialogueFilter;
	struct DialogueInfo;
	struct Door;
	struct Effect;
	struct Enchantment;
	struct EquipmentStack;
	struct Faction;
	struct Game;
	struct GameFile;
	struct GameSetting;
	struct GameSettingInfo;
	struct GlobalScript;
	struct GlobalVariable;
	struct Ingredient;
	struct InputConfig;
	struct InputController;
	struct Inventory;
	struct Item;
	struct ItemData;
	struct LeveledList;
	struct LeveledListNode;
	struct Light;
	struct Lockpick;
	struct MagicEffectInstance;
	struct MagicSourceInstance;
	struct Misc;
	struct MobileActor;
	struct MobileCreature;
	struct MobileNPC;
	struct MobileObject;
	struct MobilePlayer;
	struct MobileProjectile;
	struct Moon;
	struct NPC;
	struct NPCInstance;
	struct Object;
	struct ObjectVirtualTable;
	struct PhysicalObject;
	struct PlayerAnimationData;
	struct Probe;
	struct Race;
	struct Reference;
	struct ReferenceList;
	struct Region;
	struct RepairTool;
	struct Script;
	struct ScriptVariables;
	struct Sound;
	struct SoundGenerator;
	struct Spell;
	struct SpellList;
	struct StartScript;
	struct Static;
	struct Statistic;
	struct Weapon;
	struct Weather;
	struct WeatherController;
	struct WorldController;

	namespace UI {
		struct Block;
		struct InventoryTile;
		struct String;
		struct Tree;
		struct Vector;
	}

	//
	// The core building blocks of TES3 objects.
	//

	struct BaseObjectVirtualTable {
		void (__thiscall * destructor)(BaseObject*, signed char); // 0x0
		int (__thiscall * loadObjectSpecific)(BaseObject*, int); // 0x4
		int (__thiscall * saveRecordSpecific)(BaseObject*, int); // 0x8
		int (__thiscall * loadObject)(BaseObject*, int); // 0xC
		int (__thiscall * saveObject)(BaseObject*, int); // 0x10
		int (__thiscall * setObjectModified)(BaseObject*, unsigned char); // 0x14
		int (__thiscall * setObjectFlag40)(BaseObject*, unsigned char); // 0x18
		void * unknown_0x1C;
		char * (__thiscall * getObjectID)(BaseObject*); // 0x20
	};
	static_assert(sizeof(BaseObjectVirtualTable) == 0x24, "TES3::BaseObjectVirtualTable failed size validation");

	struct ObjectVirtualTable : BaseObjectVirtualTable {
		void * copyEntity;
		void (__thiscall * setID)(BaseObject*, const char*); // 0x10C
		void * getVisualNode;
		void * unknown_0x30;
		void * unknown_0x34;
		char * (__thiscall * getName)(BaseObject*); // 0x38
		char * (__thiscall * getIconPath)(BaseObject*); // 0x3C
		void * unknown_0x40;
		void * unknown_0x44;
		char * (__thiscall * getModelPath)(BaseObject*); // 0x48
		Script * (__thiscall * getScript)(BaseObject*); // 0x4C
		void * unknown_0x50;
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
		unsigned char(__thiscall * setAutoCalc)(BaseObject*, unsigned char); // 0xEC
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
		void * getScale; // 0x120
		void * setScale; // 0x124
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
			ActorVirtualTable * actor;
		} vTable; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		unsigned int objectFlags; // 0x8
		GameFile * sourceMod; // 0xC

		//
		// Function wrappers for our virtual table.
		//

		int setObjectModified(unsigned char);
		char * getObjectID();

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
		NI::Node * sceneGraphReference; // 0x24

		//
		// Function wrappers for our virtual table.
		//

		void setID(const char*);
		char * getName();
		char * getIconPath();
		char * getModelPath();
		Script * getScript();
		char * getRaceID();
		char * getClassID();
		char * getBirthsignID();
		Race * getRace();
		Class * getClass();
		Faction * getFaction();
		bool isFemale();
		int getFactionRank();
		int getLevel();
		signed char setDispositionRaw(signed char);
		int modDisposition(signed int);
		int getFactionIndex();
		signed char setFactionIndex(signed char);
		int getDispositionRaw();
		signed char modFactionIndex(signed char);
		int getType();
		char * getTypeName();
		float getWeight();
		int getValue();
		void setDurability(int);
		int getDurability();
		int getMagicka();
		int getFatigue();
		float getQuality();
		bool isLeftPartOfPair();
		bool isEssential();
		bool isRespawn();
		int getUses();
		Enchantment * getEnchantment();
		Enchantment * setEnchantment(Enchantment*);
		AIConfig * getAIConfig();
		unsigned char getAutoCalc();
		unsigned char setAutoCalc(unsigned char);
		char* setModelPath(const char*);
		char* setName(const char*);
	};
	static_assert(sizeof(Object) == 0x28, "TES3::Object failed size validation");

	struct PhysicalObject : Object {
		BoundingBox * boundingBox; // 0x28
		char * objectID; // 0x2C
	};
	static_assert(sizeof(PhysicalObject) == 0x30, "TES3::PhysicalObject failed size validation");
}
