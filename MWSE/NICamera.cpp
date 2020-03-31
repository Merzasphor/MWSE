#include "NICamera.h"

namespace NI {
	const auto NI_Camera_click = reinterpret_cast<void (__thiscall*)(Camera*, bool)>(0x6CC7B0);
	void Camera::click(bool something) {
		NI_Camera_click(this, something);
	}
}
