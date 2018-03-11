#pragma once

#include "TES3Object.h"

namespace TES3 {
	namespace ApparatusType {
		enum ApparatusType {
			ApparatusMortarPestle,
			ApparatusAlembic,
			ApparatusCalcinator,
			ApparatusRetort
		};
	}

	struct Apparatus : PhysicalObject {
		int unknown_0x30;
		int unknown_0x34;
		int unknown_0x38;
		int unknown_0x3C;
		int unknown_0x40;
		char model[32]; // 0x44
		char name[32]; // 0x64
		Script * script;
		char texture[32]; // 0x84
		long type; // 0 = Mortar & Pestle, 1 = Alembic, 2 = Calcinator, 3 = Retort
		float quality; // 0xAC
		float weight; // 0xB0
		long value; // 0xB4
	};
	static_assert(sizeof(Apparatus) == 0xB8, "TES3::Apparatus  failed size validation");
}
