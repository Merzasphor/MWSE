#pragma once

#include "TES3Object.h"
#include "TES3ReferenceList.h"

namespace TES3 {
	namespace CellFlag {
		enum CellFlag {
			Interior = 0x1,
			HasWater = 0x2,
			SleepIsIllegal = 0x4,
			BehavesAsExterior = 0x80
		};
	}

	struct CellExteriorData {
		int size;
		Cell* cell;
		int gridX;
		int gridY;
	};

	struct Cell : BaseObject {
		char * name; // 0x10
		void * unknown_0x14;
		int cellFlags; // 0x18
		union {
			struct {
				int unknown_0x0;
				int unknown_0x4;
				int gridX; // 0x8
				int gridY; // 0xC
			} exterior;
			struct {
				int ambientColor; // 0x0
				int sunColor; // 0x4
				int fogColor; // 0x8
				int fogDensity; // 0xC
			} interior;
		} VariantData; // 0x1C
		void * unknown_0x2C;
		ReferenceList actors; // 0x30
		ReferenceList activators; // 0x40
		void * unknown_0x50; // Pointer list?
		int unknown_0x54;
		ReferenceList statics; // 0x58
		Iterator<Reference> moveReferences;
		int unknown_0x7C;
		int unknown_0x80;
		int unknown_0x84;
		int unknown_0x88;
		void * pathGrid;
		union {
			int waterLevel;
			Region * region;
		} waterLevelOrRegion;
	};
	static_assert(sizeof(Cell) == 0x94, "TES3::Cell failed size validation");
}
