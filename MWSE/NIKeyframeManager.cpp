#include "NIKeyframeManager.h"

#include "MemoryUtil.h"

namespace NI {
	const auto NI_Sequence_dtor = reinterpret_cast<void(__thiscall*)(Sequence*)>(0x70F720);
	void Sequence::release() {
		NI_Sequence_dtor(this);
		mwse::tes3::free(this);
	}
}