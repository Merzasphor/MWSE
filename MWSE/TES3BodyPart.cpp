#include "TES3BodyPart.h"

namespace TES3 {
	bool BodyPart::getFlag(BodyPartFlag::Flag flag) {
		return (flags & flag) != 0;
	}

	void BodyPart::setFlag(BodyPartFlag::Flag flag, bool set) {
		if (set) {
			flags |= flag;
		}
		else {
			flags &= ~flag;
		}
	}
}
