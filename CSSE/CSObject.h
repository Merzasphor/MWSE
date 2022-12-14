#pragma once

#include "CSBaseObject.h"

#include "NIDefines.h"

namespace se::cs {
	struct Object : BaseObject {
		NI::Node* sceneNode; // 0x10
		int unknown_0x14;
		void* referenceToThis; // 0x18
		Object* previousInCollection; // 0x1C
		Object* nextInCollection; // 0x20
		int unknown_0x24;
	};
}
