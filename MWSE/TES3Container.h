#pragma once

#include "TES3Defines.h"

#include "TES3Actor.h"

namespace TES3 {
	struct Container : Actor {
		char * model;
		char * name;
		Script * script;
		float capacity;
	};
	static_assert(sizeof(Container) == 0x7C, "TES3::Container failed size validation");

	struct ContainerInstance : Actor {
		Container * container;

		//
		// Base object helper functions.
		//

		float getCapacity();
		void setCapacity(float);

	};
	static_assert(sizeof(ContainerInstance) == 0x70, "TES3::ContainerInstance failed size validation");
}
