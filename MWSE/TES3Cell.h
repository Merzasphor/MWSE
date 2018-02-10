
namespace TES3 {
	struct Reference;
}

#pragma once

#include "ObjectTypes.h"

#include "TES3Reference.h"

namespace TES3 {
	struct RefListHead {
		long size;
		Reference * first;
		Reference * last;
		Reference * container;
	};
	static_assert(sizeof(RefListHead) == 0x10, "TES3::RefListHead failed size validation");

	struct Cell_vTable {

	};

	struct Cell {
		char unknown_0x00[16];
		mwString name; // 0x10 // May be null.
		char unknown_0x14[28];
		RefListHead npc; // 0x30
		RefListHead statics; // 0x40
		long unknown_0x50;
		long unknown_0x54;
		RefListHead otheritems; // 0x58
	};
	static_assert(sizeof(Cell) == 0x68, "TES3::Cell failed size validation");
}
