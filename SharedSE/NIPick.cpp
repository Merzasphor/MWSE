#include "NIPick.h"

#include "ExceptionUtil.h"
#include "MemoryUtil.h"

namespace NI {
	Pick::Pick() {
#if defined(SE_NI_PICK_FNADDR_CTOR) && SE_NI_PICK_FNADDR_CTOR > 0
		// Cleanup automatic cruft.
		se::memory::_delete(results.storage);
		memset(this, 0, sizeof(Pick));

		const auto NI_Pick_ctor = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_CTOR);
		NI_Pick_ctor(this);
#else
		throw not_implemented_exception();
#endif
	}

	Pick::~Pick() {
#if defined(SE_NI_PICK_FNADDR_DTOR) && SE_NI_PICK_FNADDR_DTOR > 0
		const auto NI_Pick_ctor = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_DTOR);
		NI_Pick_ctor(this);
#else
		throw not_implemented_exception();
#endif
	}

	bool Pick::pickObjects(const Vector3* origin, const Vector3* direction, bool append, float maxDistance) {
#if defined(SE_NI_PICK_FNADDR_PICKOBJECTS) && SE_NI_PICK_FNADDR_PICKOBJECTS > 0
		const auto TES3_Pick_pickObjects = reinterpret_cast<bool(__thiscall*)(Pick*, const Vector3*, const Vector3*, bool, float)>(SE_NI_PICK_FNADDR_PICKOBJECTS);
		return TES3_Pick_pickObjects(this, origin, direction, append, maxDistance);
#else
		throw not_implemented_exception();
#endif
	}

	void Pick::clearResults() {
#if defined(SE_NI_PICK_FNADDR_CLEARRESULTS) && SE_NI_PICK_FNADDR_CLEARRESULTS > 0
		const auto TES3_Pick_clearResults = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_CLEARRESULTS);
		TES3_Pick_clearResults(this);
#else
		throw not_implemented_exception();
#endif
	}

	std::reference_wrapper<unsigned short[3]> PickRecord::getVertexIndex() {
		return std::ref(vertexIndex);
	}
}
