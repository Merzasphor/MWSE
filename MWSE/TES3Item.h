#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"

namespace TES3 {
	struct ItemData {
		int stackCount;
		PhysicalObject * owner;
		union {
			long rank;
			GlobalVariable * variable;
		} requirement;
		int condition;
		float enchantCharge;
		Script * script;
		ScriptVariables * scriptData;
	};
	static_assert(sizeof(ItemData) == 0x1C, "TES3::ItemData failed size validation");

	struct Item : PhysicalObject {
		Iterator<void> stolenList; // 0x30
		char * name; // 0x44
		Script * script; // 0x48
		char * model; // 0x4C
		char * icon; // 0x50
	};
	static_assert(sizeof(Item) == 0x54, "TES3::Item failed size validation");

	struct ItemContained : PhysicalObject {
		Iterator<void> stolenList; // 0x30
		char name[32]; // 0x44
		int unknown_0x64;
		char modal[32]; // 0x68
		char icon[32]; // 0x88
	};
}
