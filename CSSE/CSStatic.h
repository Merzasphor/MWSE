#pragma once

#include "CSPhysicalObject.h"

#include "MemoryUtil.h"

namespace se::cs {
	struct Static : PhysicalObject {
		const char* modelPath; // 0x48

		using gDoorMarker = memory::ExternalGlobal<Static*, 0x6D5664>;
	};
	static_assert(sizeof(Static) == 0x4C, "TES3::Static failed size validation");

	typedef memory::ExternalGlobal<Static*, 0x6D5668> gTravelMarker;
	typedef memory::ExternalGlobal<Static*, 0x6D566C> gNorthMarker;
	typedef memory::ExternalGlobal<Static*, 0x6D5670> gPrisonMarker;
	typedef memory::ExternalGlobal<Static*, 0x6D5674> gTempleMarker;
	typedef memory::ExternalGlobal<Static*, 0x6D5678> gDivineMarker;
}
