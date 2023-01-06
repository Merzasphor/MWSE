#pragma once

#include "CSAnimatedObject.h"

#include "NIIteratedList.h"

namespace se::cs {
	namespace ActorFlag {
		typedef unsigned int value_type;

		enum Flag : value_type {
			IsBase = 0x8,
		};
	}

	struct Inventory {
		unsigned int flags; // 0x0
		NI::IteratedList<void*> items; // 0x4
		Light* internalLight;
	};

	struct Actor : AnimatedObject {
		unsigned int actorFlags; // 0x4C
		int unknown_0x50;
		Inventory inventory; // 0x54
		void* equipment; // 0x70
		int unknown_0x74;
		int unknown_0x78;
	};
	static_assert(sizeof(Actor) == 0x7C, "CS::Actor failed size validation");
}