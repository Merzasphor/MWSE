#pragma once

#include "TES3Collections.h"

#include "TES3Cell.h"
#include "TES3GameSetting.h"
#include "TES3MagicEffect.h"
#include "TES3Skill.h"
#include "TES3Spell.h"

namespace TES3 {
	struct RecordLists {
		struct UnknownStruct {
			void * vTable; // 0x00
			long unknown_0x04;
			void * unknown_0x08;
			void * unknown_0x0C;
			void * unknown_0x10;
			long unknown_0x14;
			long unknown_0x18;
			long unknown_0x1C;
			long unknown_0x20;
			long unknown_0x24;
			long unknown_0x28;
			void * unknown_0x2C;
		};
		long unknown_0x00;
		long unknown_0x04; // always 0?
		BaseObject * unknown_0x08; // Points to info about the last loaded save?
		LinkedList<BaseObject> * list; // 0x0C
		LinkedList<Spell> * spellsList; // 0x10
		void * unknown_0x14;
		GameSetting ** GMSTs; // 0x18 // Pointer to array of GMST pointers.
		UnknownStruct * unknown5[12]; // 0x1C
		Skill skills[27]; // 0x4C
		MagicEffect magic_effects[143]; // 0x05C8
	};
	static_assert(sizeof(RecordLists::UnknownStruct) == 0x30, "TES3::RecordList::UnknownStruct failed size validation");
	static_assert(sizeof(RecordLists) == 0x9DB8, "TES3::RecordList failed size validation");

	enum CellGrid {
		CellGridNorthWest = 0,
		CellGridNorth = 1,
		CellGridNorthEast = 2,
		CellGridWest = 3,
		CellGridCenter = 4,
		CellGridEast = 5,
		CellGridSouthWest = 6,
		CellGridSouth = 7,
		CellGridSouthEast = 8
	};

	struct CellPointer {
		long size;
		Cell * cell;
	};
	static_assert(sizeof(CellPointer) == 0x08, "TES3::CellPointer failed size validation");

	struct CellMaster {
		RecordLists * recordLists; // 0x00
		CellPointer * exteriorCells[9]; // 0x04
		int unknown_0x28;
		int unknown_0x2C;
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		int unknown_0x44;
		int unknown_0x48;
		int unknown_0x4C;
		int unknown_0x50;
		int unknown_0x54;
		int unknown_0x58;
		int unknown_0x5C;
		int unknown_0x60;
		int unknown_0x64;
		int unknown_0x68;
		int unknown_0x6C;
		int unknown_0x70;
		int unknown_0x74;
		int unknown_0x78;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		int unknown_0x8C;
		int unknown_0x90;
		int unknown_0x94;
		int unknown_0x98;
		int unknown_0x9C;
		int unknown_0xA0;
		int unknown_0xA4;
		int unknown_0xA8;
		Cell * interiorCell; // 0xAC
		int unknown_0xB0;
		int unknown_0xB4;
		int unknown_0xB8;
		int unknown_0xBC;
	};
	static_assert(sizeof(CellMaster) == 0xC0, "TES3::CellMaster failed size validation");
}
