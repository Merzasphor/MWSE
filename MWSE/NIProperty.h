#pragma once

#include "NIObjectNET.h"

#include "NIColor.h"
#include "NILinkedList.h"
#include "TES3Collections.h"

#include "Bitset.h"

namespace NI {
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

	struct Property_vTable : Object_vTable {
		PropertyType (__thiscall * getType)(Property*); // 0x2C
		void (__thiscall * update)(Property*, float); // 0x30
	};
	static_assert(sizeof(Property_vTable) == 0x34, "NI::Property's vtable failed size validation");

	struct Property : ObjectNET {
		mwse::bitset16 flags;

		//
		// vTable wrappers.
		//

		__declspec(dllexport) __inline PropertyType getType() {
			return static_cast<PropertyType>(vTable.asProperty->getType(this));
		}

	};
	static_assert(sizeof(Property) == 0x18, "NI::Property failed size validation");

	struct AlphaProperty : Property {
		unsigned char alphaTestRef;
	};
	static_assert(sizeof(AlphaProperty) == 0x1C, "NI::AlphaProperty failed size validation");

	struct FogProperty : Property {
		float density;
		unsigned char color[4];
	};
	static_assert(sizeof(FogProperty) == 0x20, "NI::FogProperty failed size validation");

	struct MaterialProperty : Property {
		int index;
		Color ambient;
		Color diffuse;
		Color specular;
		Color emissive;
		float shininess;
		float alpha;
		unsigned int revisionID;
	};
	static_assert(sizeof(MaterialProperty) == 0x58, "NI::MaterialProperty failed size validation");

	struct StencilProperty : Property {
		bool enabled;
		int testFunc;
		unsigned int reference;
		unsigned int mask;
		int failAction;
		int zFailAction;
		int passAction;
		int drawMode;
	};
	static_assert(sizeof(StencilProperty) == 0x38, "NI::StencilProperty failed size validation");

	struct TexturingProperty : Property {
		enum struct ClampMode {
			CLAMP_S_CLAMP_T,
			CLAMP_S_WRAP_T,
			WRAP_S_CLAMP_T,
			WRAP_S_WRAP_T
		};
		enum struct FilterMode {
			NEAREST,
			BILERP,
			TRILERP,
			NEAREST_MIPNEAREST,
			NEAREST_MIPLERP,
			BILERP_MIPNEAREST
		};
		enum struct ApplyMode {
			REPLACE,
			DECAL,
			MODULATE
		};

		struct Map {
			void * vTable;
			Pointer<Texture> texture;
			ClampMode clampMode;
			FilterMode filterMode;
			unsigned int texCoordSet;
		};
		struct BumpMap : Map {
			float lumaScale;
			float lumaOffset;
			float bumpMat[2][2];
		};

		ApplyMode applyMode;
		TES3::TArray<Map> maps;
		int unknown_34;
	};
	static_assert(sizeof(TexturingProperty) == 0x38, "NI::TexturingProperty failed size validation");
	static_assert(sizeof(TexturingProperty::Map) == 0x14, "NI::TexturingProperty::Map failed size validation");
	static_assert(sizeof(TexturingProperty::BumpMap) == 0x2C, "NI::TexturingProperty::BumpMap failed size validation");

	struct VertexColorProperty : Property {
		int source;
		int lighting;
	};
	static_assert(sizeof(VertexColorProperty) == 0x20, "NI::VertexColorProperty failed size validation");
}
