#pragma once

#include "D3DColorValue.h"

namespace D3D {
	struct Material {
		ColorValue diffuse;
		ColorValue ambient;
		ColorValue specular;
		ColorValue emissive;
		float power;
	};
	static_assert(sizeof(Material) == 0x44, "D3D::Material failed size validation");
}
