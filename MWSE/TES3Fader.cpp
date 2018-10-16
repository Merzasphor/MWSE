#include "TES3Fader.h"

namespace TES3 {
	const auto TES3_Fader_fadeTo = reinterpret_cast<void(__thiscall*)(Fader*, float, float, FaderCallback)>(0x4096B0);
	void Fader::fadeTo(float value, float duration, FaderCallback callback) {
		TES3_Fader_fadeTo(this, value, duration, callback);
	}
}
