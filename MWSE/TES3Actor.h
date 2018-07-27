#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Armor.h"
#include "TES3Clothing.h"
#include "TES3Inventory.h"
#include "TES3Object.h"

namespace TES3 {
	namespace ActorFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Female = 0x1,
			Essential = 0x2,
			Respawns = 0x4,
			IsBase = 0x8,
			AutoCalc = 0x10,
			BloodSkeleton = 0x400,
			BloodMetal = 0x800,
		};

		enum FlagBit {
			FemaleBit = 0,
			EssentialBit = 1,
			RespawnsBit = 2,
			IsBaseBit = 3,
			AutocalcBit = 4,
			BloodSkeletonBit = 10,
			BloodMetalBit = 11,
		};
	}

	struct ActorVirtualTable : ObjectVirtualTable {
		void * unknown_0x13C;
		void * unknown_0x140;
		void * getStolenList; // 0x144
		void * loadAnimation; // 0x148
		void * getBaseNPC; // 0x14C
		void * addItem; // 0x150
		int (__thiscall * getBaseBarterGold)(Actor*); // 0x154
		void (__thiscall * setBaseBarterGold)(Actor*, int); // 0x158
		void (__thiscall * clone)(Actor*, Reference*); // 0x15C
		void * onCloseInventory; // 0x160
		void * unknown_0x164;
		bool (__thiscall * getIsAttacked)(Actor*); // 0x168
		void * unknown_0x16C;
		void * unknown_0x170;
		void * unknown_0x174;
		void * unknown_0x178;
		void * setAIPackage; // 0x17C
	};
	static_assert(sizeof(ActorVirtualTable) == 0x180, "TES3::ActorVirtualTable failed size validation");

	struct Actor : PhysicalObject {
		ActorAnimationData * animationData; // 0x30
		ActorFlag::value_type actorFlags; // 0x34
		int cloneCount; // 0x38
		Inventory inventory; // 0x3C
		Iterator<EquipmentStack> equipment; // 0x58

		//
		// Function wrappers for our virtual table.
		//

		int getBaseBarterGold();
		void setBaseBarterGold(int);
		bool getIsAttacked();
		void clone(Reference*);

		//
		// Other related this-call functions.
		//

		Object* equipItem(Object* item, ItemData* itemData, EquipmentStack** out_equipmentStack, MobileActor* mobileActor);
		EquipmentStack* unequipItem(Object* item, bool deleteStack, MobileActor* mobileActor, bool updateGUI, ItemData* itemData);
		Reference* dropItem(Object* item, ItemData* itemData, int count, bool matchAny);
		void postUnequipUIRefresh(MobileActor* mobileActor);
		EquipmentStack* getEquippedItem(Object* item);
		EquipmentStack* getEquippedArmorBySlot(ArmorSlot::value_type slot);
		EquipmentStack* getEquippedClothingBySlot(ClothingSlot::value_type slot);

		//
		// Custom functions.
		//

		bool getActorFlag(ActorFlag::Flag);
		void setActorFlag(ActorFlag::Flag, bool);

	};
	static_assert(sizeof(Actor) == 0x6C, "TES3::Actor failed size validation");
}
