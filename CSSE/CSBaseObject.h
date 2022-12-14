#pragma once

#include "CSDefines.h"

namespace se::cs {
	namespace ObjectType {
		enum ObjectType {
			Invalid = 0,
			Activator = 'ITCA',
			Alchemy = 'HCLA',
			Ammo = 'OMMA',
			AnimationGroup = 'GINA',
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
			CreatureClone = 'CERC',
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
			MobileSpellProjectile = 'PSPM',
			NPC = '_CPN',
			NPCClone = 'CCPN',
			PathGrid = 'DRGP',
			Probe = 'BORP',
			Quest = 'SEUQ',
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

	struct BaseObject_VirtualTable {
		void(__thiscall* destructor)(BaseObject*, signed char); // 0x0
		int(__thiscall* loadObjectSpecific)(BaseObject*, GameFile*); // 0x4
		int(__thiscall* saveRecordSpecific)(BaseObject*, GameFile*); // 0x8
		int(__thiscall* loadObject)(BaseObject*, GameFile*); // 0xC
		int(__thiscall* saveObject)(BaseObject*, GameFile*); // 0x10
		void(__thiscall* setObjectModified)(BaseObject*, bool); // 0x14
		int(__thiscall* setObjectFlag40)(BaseObject*, bool); // 0x18
		void* unknown_0x1C;
		const char* (__thiscall* getObjectID)(const BaseObject*); // 0x20
	};

	struct BaseObject {
		union {
			BaseObject_VirtualTable* baseObject;
			Object_VirtualTable* object;
		} vtbl; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		unsigned int flags; // 0x8
		GameFile* sourceFile; // 0xC

		const char* getObjectID() const;
		void setModified(bool modified);

		void setFlag80(bool set);
	};
	static_assert(sizeof(BaseObject) == 0x10, "TES3::BaseObject failed size validation");
	static_assert(sizeof(BaseObject_VirtualTable) == 0x24, "TES3::BaseObject_VirtualTable failed size validation");
}
