#pragma once

#include "CSBaseObject.h"

#include "NIColor.h"
#include "NINode.h"
#include "NIIteratedList.h"
#include "LinkedObjectsList.h"

namespace se::cs {
	struct ReferenceList : LinkedObjectList<Reference> {
		Cell* cell; // 0xC
	};

	struct Cell : BaseObject {
		const char* name; // 0x10
		NI::Pointer<NI::Node> pickObjectsRoot; // 0x14
		DWORD cellFlags; // 0x18
		union {
			struct {
				NI::PackedColor ambientColor;
				NI::PackedColor sunColor;
				NI::PackedColor fogColor;
				float fogDensity;
			};
			struct {
				NI::PackedColor regionMapColor;
				BaseObject* landscape;
				int gridX;
				int gridY;
			};
		}; // 0x1C
		NI::Pointer<NI::Node> staticObjectsRoot; // 0x2C
		ReferenceList unknown_0x30;
		ReferenceList unknown_0x40;
		NI::IteratedList<void*>* movedReferences; // 0x50
		int unknown_0x54;
		BaseObject* unknown_0x58;
		union {
			float waterLevel;
			BaseObject* region;
		}; // 0x5C
	};
	static_assert(sizeof(Cell) == 0x60, "Cell failed size validation");
}
