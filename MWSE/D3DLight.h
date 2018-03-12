#pragma once

#include "D3DColorValue.h"
#include "D3DVector.h"

namespace D3D {
	struct Light {
		int size;
		int type;
		ColorValue color;
		Vector position;
		Vector direction;
		float range;
		float falloff;
		float attenuation0;
		float attenuation1;
		float attenuation2;
		float theta;
		float phi;
	};
	static_assert(sizeof(Light) == 0x4C, "TES3::Light failed size validation");

	struct Light8 {
		int type;
		ColorValue color;
		Vector position;
		Vector direction;
		float range;
		float falloff;
		float attenuation0;
		float attenuation1;
		float attenuation2;
		float theta;
		float phi;
	};
	static_assert(sizeof(Light8) == 0x48, "TES3::Light8 failed size validation");
}
