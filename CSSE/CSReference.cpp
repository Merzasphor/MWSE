#include "CSReference.h"

namespace se::cs {
	LightAttachmentNode* Reference::getLightAttachment() const {
		const auto Reference_getLightAttachment = reinterpret_cast<LightAttachmentNode*(__thiscall*)(const Reference*)>(0x4043EA);
		return Reference_getLightAttachment(this);
	}

	void Reference::updateBaseObjectAndAttachment7() const {
		const auto Reference_updateBaseObjectAndAttachment7 = reinterpret_cast<void(__thiscall*)(const Reference*)>(0x4026E4);
		Reference_updateBaseObjectAndAttachment7(this);
	}

	Reference* Reference::getAttachment7() const {
		const auto Reference_getAttachment7 = reinterpret_cast<Reference * (__thiscall*)(const Reference*)>(0x53F3B0);
		return Reference_getAttachment7(this);
	}

	void Reference::updateRotationMatrixForRaceAndSex(NI::Matrix33& matrix, bool unknown) const {
		const auto Reference_updateRotationMatrixForRaceAndSex = reinterpret_cast<void(__thiscall*)(const Reference*, NI::Matrix33*, bool)>(0x4028B0);
		return Reference_updateRotationMatrixForRaceAndSex(this, &matrix, unknown);
	}
}
