#pragma once

#include "TES3Defines.h"

#include "TES3Actor.h"

namespace TES3 {
	namespace ActorFlagContainer {
		typedef unsigned int value_type;

		enum Flag : value_type {
			Organic = 0x1,
			Respawns = 0x2,
			IsBase = 0x8,
		};

		enum FlagBig {
			OrganicBit = 0,
			RespawnsBit = 1,
			IsBaseBit = 2,
		};
	}

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
