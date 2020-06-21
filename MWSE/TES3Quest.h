#pragma once

#include "TES3Object.h"
#include "TES3Collections.h"

namespace TES3 {
	struct Quest : BaseObject {
		char * name; // 0x10
		Iterator<Dialogue> dialogue; // 0x14
		Iterator<DialogueInfo> activeInfo; // 0x28

		//
		// Virtual table overrides.
		//

		char* getObjectID() const;

		//
		// Custom functions.
		//

		std::string toJson() const;

	};
	static_assert(sizeof(Quest) == 0x3C, "TES3::Quest failed size validation");
}
