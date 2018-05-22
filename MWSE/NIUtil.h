#pragma once

#include "NIDefines.h"
#include "TES3Object.h"

namespace NI {
	Pick* getGlobalPick();

	TES3::Reference* getAssociatedReference(AVObject*);
}
