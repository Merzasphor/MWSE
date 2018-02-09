#pragma once

#include "ObjectTypes.h"

#include "TES3Script.h"

namespace TES3 {
	enum ApparatusType {
		ApparatusMortarPestle,
		ApparatusAlembic,
		ApparatusCalcinator,
		ApparatusRetort
	};

	struct Apparatus_vTable {

	};

	struct Apparatus {
		Apparatus_vTable * vTable;
		ObjectType::ObjectType objectType;
		int baseFlags; // 0x08
		int unknown_0x0C;
		int unknown_0x10;
		int unknown_0x14;
		int unknown_0x18;
		BaseObject * previousRecord; // 0x1C
		BaseObject * nextRecord; // 0x20
		int unknown_0x24;
		int unknown_0x28;
		mwString objectID; // 0x2C
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char model[32]; // 0x44
		char name[32]; // 0x64
		Script * script;
		char texture[32]; // 0x84
		ApparatusType type; // 0 = Mortar & Pestle, 1 = Alembic, 2 = Calcinator, 3 = Retort
		mwFloat quality; // 0xAC
		mwFloat weight; // 0xB0
		mwLong value; // 0xB4
	};
	static_assert(sizeof(Apparatus) == 0xB8, "TES3::Apparatus failed size validation");
}
