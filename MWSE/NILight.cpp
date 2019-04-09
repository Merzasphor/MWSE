#include "NILight.h"

namespace NI {
	const auto NI_Light_ctor = reinterpret_cast<Light*(__thiscall*)(Light*)>(0x6F9940);
	Light * Light::ctor() {
		return NI_Light_ctor(this);
	}
}
