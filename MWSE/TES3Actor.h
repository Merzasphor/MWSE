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
			IsBase = 0x8,
		};
	}

	struct ActorVirtualTable : PhysicalObjectVirtualTable {
		void * loadAnimation; // 0x148
		Actor * (__thiscall * getBaseActor)(Actor*); // 0x14C
		void * addItem; // 0x150
		int (__thiscall * getBaseBarterGold)(Actor*); // 0x154
		void (__thiscall * setBaseBarterGold)(Actor*, int); // 0x158
		void (__thiscall * clone)(Actor*, Reference*); // 0x15C
		void (__thiscall * onCloseInventory)(Actor*, Reference*, int); // 0x160
		void * unknown_0x164;
		bool (__thiscall * getIsAttacked)(Actor*); // 0x168
		void * unknown_0x16C;
		void * unknown_0x170;
		void * unknown_0x174;
		void * unknown_0x178;
		void (__thiscall * setAIPackage)(Actor*, AIPackageConfig*, Reference*); // 0x17C
	};
	static_assert(sizeof(ActorVirtualTable) == 0x180, "TES3::ActorVirtualTable failed size validation");

	struct Actor : PhysicalObject {
		ActorAnimationData * animationData; // 0x30
		unsigned int actorFlags; // 0x34
		int cloneCount; // 0x38
		Inventory inventory; // 0x3C
		Iterator<EquipmentStack> equipment; // 0x58

		//
		// Function wrappers for our virtual table.
		//

		Actor * getBaseActor();
		int getBaseBarterGold();
		void setBaseBarterGold(int);
		bool getIsAttacked();
		void clone(Reference*);
		void onCloseInventory(Actor* actor, Reference* reference, int unknown = 0);
		void setAIPackage(AIPackageConfig* packageConfig, Reference* reference);

		//
		// Other related this-call functions.
		//

		Object* equipItem(Object* item, ItemData* itemData, EquipmentStack** out_equipmentStack, MobileActor* mobileActor);
		EquipmentStack* unequipItem(Object* item, bool deleteStack, MobileActor* mobileActor, bool updateGUI, ItemData* itemData);
		void unequipAllItems(MobileActor * mobileActor);
		Reference* dropItem(Object* item, ItemData* itemData, int count, bool matchAny);
		void postUnequipUIRefresh(MobileActor* mobileActor);
		EquipmentStack* getEquippedItem(Object* item);
		EquipmentStack* getEquippedArmorBySlot(ArmorSlot::value_type slot);
		EquipmentStack* getEquippedClothingBySlot(ClothingSlot::value_type slot);

		//
		// Custom functions.
		//

		bool getActorFlag(unsigned int);
		void setActorFlag(unsigned int, bool);

		bool isBaseActor();
		bool isClone();

	};
	static_assert(sizeof(Actor) == 0x6C, "TES3::Actor failed size validation");
}
