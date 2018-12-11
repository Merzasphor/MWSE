#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"
#include "TES3Item.h"

namespace TES3 {
	enum class ApparatusType {
		MortarPestle,
		Alembic,
		Calcinator,
		Retort
	};

	struct Apparatus : Item {
		Iterator<TES3::BaseObject> stolenList; // 0x30
		char model[32]; // 0x44
		char name[32]; // 0x64
		Script * script;
		char texture[32]; // 0x84
		ApparatusType type;
		float quality; // 0xAC
		float weight; // 0xB0
		long value; // 0xB4
	};
	static_assert(sizeof(Apparatus) == 0xB8, "TES3::Apparatus  failed size validation");
}
