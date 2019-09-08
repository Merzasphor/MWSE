#pragma once

#include "NIDefines.h"

#include "NIRenderer.h"

namespace NI {
	class DX8Renderer : Renderer {
		unsigned char unknown_0x1C[0x684];
	};
	static_assert(sizeof(DX8Renderer) == 0x6A0, "NI::DX8Renderer failed size validation");
}
