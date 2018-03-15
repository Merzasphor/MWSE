#pragma once

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
			Spll = 'LLPS',
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
	struct AIConfig;
	struct Alchemy;
	struct Apparatus;
	struct Armor;
	struct BaseObject;
	struct Bodypart;
	struct Cell;
	struct CellExteriorData;
	struct Class;
	struct Creature;
	struct CreatureInstance;
	struct DataHandler;
	struct Door;
	struct Effect;
	struct Enchantment;
	struct Faction;
	struct Game;
	struct GameSetting;
	struct GlobalVariable;
	struct InputConfig;
	struct InputController;
	struct Item;
	struct ItemData;
	struct Light;
	struct Lockpick;
	struct MobileActor;
	struct MobileCreature;
	struct MobileNPC;
	struct MobilePlayer;
	struct NPC;
	struct NPCInstance;
	struct Object;
	struct PhysicalObject;
	struct Probe;
	struct Race;
	struct Reference;
	struct Region;
	struct RepairTool;
	struct Script;
	struct ScriptVariables;
	struct Spell;
	struct Weapon;
	struct WorldController;

	//
	// The core building blocks of TES3 objects.
	//

	struct vtBaseObject {
		void * destructor; // 0x0
		int(__thiscall * loadObjectSpecific)(BaseObject*, int); // 0x4
		int(__thiscall * saveRecordSpecific)(BaseObject*, int); // 0x8
		int(__thiscall * loadObject)(BaseObject*, int); // 0xC
		int(__thiscall * saveObject)(BaseObject*, int); // 0x10
		int(__thiscall * setObjectModified)(BaseObject*, unsigned char); // 0x14
		int(__thiscall * setObjectFlag40)(BaseObject*, unsigned char); // 0x18
		void * unknown_0x1C;
		char * (__thiscall * getObjectID)(BaseObject*); // 0x20
		void * copyEntity;
		void * setID;
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
		void * setDurability;
		int (__thiscall * getDurability)(BaseObject*);
		void * getMagicka;
		void * getFatigue;
		float (__thiscall * getQuality)(BaseObject*);
		void * isLeftPartOfPair;
		void * isEssential;
		void * isRespawn;
		void * unknown_0xC4;
		void * getUses;
		void * unknown_0xCC;
		Enchantment * (__thiscall * getEnchantment)(BaseObject*);
		Enchantment * (__thiscall * setEnchantment)(BaseObject*, Enchantment*);
		AIConfig * (__thiscall * getAIConfig)(BaseObject*);
		void * getAIPackageList;
		void * resolveInternalIDs;
		void * unknown_0xE4;
		unsigned char (__thiscall * getAutoCalc)(BaseObject*);
		unsigned char(__thiscall * setAutoCalc)(BaseObject*, unsigned char);
		void * unknown_0xF0;
		void * unknown_0xF4;
		void * unknown_0xF8;
		void * setModelPath;
		void * unknown_0x100;
		void * unknown_0x104;
		void * isLocationMarker;
		void * setName;
		void * unknown_0x110;
		void * unknown_0x114;
		void * unknown_0x118;
		void * unknown_0x11C;
		void * getScale;
		void * setScale;
		void * unknown_0x128;
		void * unknown_0x12C;
		void * unknown_0x130;
		void * loadModel;
		void * unknown_0x138;
	};

	struct BaseObject {
		vtBaseObject * vTable; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		int objectFlags; // 0x8
		void * sourceMod; // 0xC
	};
	static_assert(sizeof(BaseObject) == 0x10, "TES3::BaseObject failed size validation");

	struct Object : BaseObject {
		void * sceneNode; // 0x10
		void * owningCollection; // 0x14
		void * referenceToThis; // 0x18
		Object * previousInCollection; // 0x1C
		Object * nextInCollection; // 0x20
		void * sceneGraphReference; // 0x24
	};
	static_assert(sizeof(Object) == 0x28, "TES3::Object failed size validation");

	struct PhysicalObject : Object {
		void * boundingBox; // 0x28
		char * objectID; // 0x2C
	};
	static_assert(sizeof(PhysicalObject) == 0x30, "TES3::PhysicalObject failed size validation");
}
