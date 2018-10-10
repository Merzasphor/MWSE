#pragma once

#include "NIObjectNET.h"

namespace NI {
	struct Property_vTable : Object_vTable {
		int(__thiscall * getType)(Property*); // 0x2C
		void(__thiscall * update)(Property*, float); // 0x30
	};
	static_assert(sizeof(Property_vTable) == 0x34, "NI::Property's vtable failed size validation");

	enum class PropertyType : int {
		Alpha = 0x0,
		Fog = 0x1,
		Material = 0x2,
		Stencil = 0x3,
		Texturing = 0x4,
		VertexColor = 0x5,
		Wireframe = 0x6,
		ZBuffer = 0x7,
		Dither = 0x8,
		Specular = 0x9,
		Shade = 0xA,
		RendererSpecific = 0xB,
	};

	struct Property : ObjectNET {
		unsigned short flags;

		//
		// vTable wrappers.
		//

		__declspec(dllexport) __inline int getType() {
			return vTable.asProperty->getType(this);
		}

	};
	static_assert(sizeof(Property) == 0x18, "NI::Property failed size validation");
}
