#pragma once

#include "sol_forward.hpp"

#include "TES3Defines.h"

#include "TES3Object.h"
#include "TES3Inventory.h"

namespace TES3 {
	namespace ActorFlag {
		enum ActorFlag {
			Female = 0x1,
			Essential = 0x2,
			Respawns = 0x4,
			IsBase = 0x8,
			AutoCalc = 0x10,
			BloodSkeleton = 0x400,
			BloodMetal = 0x800,
		};
	}

	namespace ActorFlagBit {
		enum ActorFlagBit {
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
		unsigned int (__thiscall * clone)(Actor*, Reference*); // 0x15C
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
		void * animationData; // 0x30
		unsigned int actorFlags; // 0x34 // See ActorFlag above.
		int cloneCount; // 0x38
		Inventory inventory; // 0x3C
		Iterator<EquipmentStack> equipment; // 0x58

		//
		// Function wrappers for our virtual table.
		//

		int getBaseBarterGold();
		void setBaseBarterGold(int);
		bool getIsAttacked();
		unsigned int clone(Reference*);

		//
		// Other related this-call functions.
		//

		int equipItem(TES3::BaseObject* item, TES3::ItemData* itemData, TES3::EquipmentStack** out_equipmentStack, TES3::MobileActor* mobileActor);
		int unequipItem(TES3::BaseObject* item, char unknown1, TES3::MobileActor* mobileActor, char unknown2, TES3::ItemData* itemData);
		Reference* dropItem(BaseObject*, ItemData*, int, bool);

		//
		// Custom functions.
		//

		bool getActorFlag(unsigned int);
		void setActorFlag(unsigned int, bool);

	};
	static_assert(sizeof(Actor) == 0x6C, "TES3::Actor failed size validation");
}
