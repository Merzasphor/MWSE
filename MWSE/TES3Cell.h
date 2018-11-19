#pragma once

#include "TES3Defines.h"

#include "TES3Object.h"
#include "TES3ReferenceList.h"

#include "NIPointer.h"
#include "NISourceTexture.h"

namespace TES3 {
	namespace CellFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Interior = 0x1,
			HasWater = 0x2,
			SleepIsIllegal = 0x4,
			BehavesAsExterior = 0x80
		};
	}

	struct CellExteriorData {
		int size; // 0x0
		Cell* cell; // 0x4
		int gridX; // 0x8
		int gridY; // 0xC
	};
	static_assert(sizeof(CellExteriorData) == 0x10, "TES3::CellExteriorData failed size validation");
	
	struct PackedColor {
		unsigned char r; // 0x0
		unsigned char g; // 0x1
		unsigned char b; // 0x2
		unsigned char a; // 0x3
	};
	static_assert(sizeof(PackedColor) == 0x4, "TES3::PackedColor failed size validation");

	struct MapNote {
		Vector3 position; // 0x0
		char * text; // 0xC
	};
	static_assert(sizeof(MapNote) == 0x10, "TES3::MapNote failed size validation");

	struct Cell : BaseObject {
		struct struct_0x84 {
			int unknown_0x0;
			int unknown_0x4;
			int unknown_0x8;
			int unknown_0xC;
			int unknown_0x10;
			NI::Pointer<NI::SourceTexture> texture; // 0x14
		};
		char * name; // 0x10
		void * unknown_0x14;
		CellFlag::value_type cellFlags; // 0x18
		union {
			CellExteriorData exterior;
			struct {
				PackedColor ambientColor; // 0x0
				PackedColor sunColor; // 0x4
				PackedColor fogColor; // 0x8
				float fogDensity; // 0xC
			} interior;
		} VariantData; // 0x1C
		void * unknown_0x2C;
		ReferenceList actors; // 0x30
		ReferenceList activators; // 0x40
		void * unknown_0x50; // Pointer list?
		int unknown_0x54;
		ReferenceList statics; // 0x58
		Iterator<Reference> moveReferences; // 0x68
		int unknown_0x7C;
		int unknown_0x80;
		struct_0x84 * unknown_0x84;
		Iterator<MapNote> * mapNotes; // 0x88
		void * pathGrid; // 0x8C
		union {
			float waterLevel;
			Region * region;
		} waterLevelOrRegion; // 0x90

		//
		// Other related this-call functions.
		//

		static Cell* create();

		Reference * getFirstObjectOfType(ObjectType::ObjectType, bool);

		bool __declspec(dllexport) isInterior();
		int __declspec(dllexport) getGridX();
		void __declspec(dllexport) setGridX(int x);
		int __declspec(dllexport) getGridY();
		void __declspec(dllexport) setGridY(int y);

		void setName(const char* name);

		//
		// Other getter/setter functions.
		//

		bool getCellFlag(unsigned int);
		void setCellFlag(unsigned int, bool);

		float getFogDensity();
		void setFogDensity(float);

		float getWaterLevel();
		void setWaterLevel(float);

		Region * getRegion();
	};
	static_assert(sizeof(Cell) == 0x94, "TES3::Cell failed size validation");
}
