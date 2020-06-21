#include "NIDynamicEffect.h"

namespace NI {
	const auto NI_DynamicEffect_ctor = reinterpret_cast<void(__thiscall*)(const DynamicEffect*)>(0x6F34E0);

	DynamicEffect::DynamicEffect() {
		NI_DynamicEffect_ctor(this);
	}

	DynamicEffect::~DynamicEffect() {
		// Call dtor without deletion.
		vTable.asObject->destructor(this, 0);
	}

	int DynamicEffect::getType() {
		return vTable.asDynamicEffect->getType(this);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::DynamicEffect)
