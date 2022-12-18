#pragma once

#include "CSDefines.h"

#include "CSBaseObject.h"
#include "NIIteratedList.h"

namespace se::cs {
	struct Dialogue : BaseObject {
		const char* id; // 0x10
		unsigned char type; // 0x14
		NI::IteratedList<DialogueInfo*> topics; // 0x18
	};
	static_assert(sizeof(Dialogue) == 0x2C, "Dialogue failed size validation");
}
