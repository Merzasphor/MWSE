#pragma once

#include "CSBaseObject.h"

#include "NIDefines.h"

namespace se::cs {
	struct Object : BaseObject {
		NI::Node* sceneNode; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
	};
}
