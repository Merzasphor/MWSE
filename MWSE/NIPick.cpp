#include "NIPick.h"

#include "MemoryUtil.h"
#include "NIUtil.h"

#define NI_Pick_ctor 0x6F2DF0
#define NI_Pick_dtor 0x6F2EA0
#define NI_Pick_pickObjects 0x6F3050
#define NI_Pick_clearResults 0x6F2F80

namespace NI {
	Pick* Pick::malloc() {
		return reinterpret_cast<Pick*(__thiscall *)(Pick*)>(NI_Pick_ctor)(mwse::tes3::malloc<Pick>());
	}

	void Pick::free() {
		reinterpret_cast<void(__thiscall *)(Pick*)>(NI_Pick_dtor)(this);
		mwse::tes3::free(this);
	}

	void Pick::pickObjects(TES3::Vector3 * origin, TES3::Vector3 * direction, bool append, float maxDistance) {
		reinterpret_cast<void(__thiscall*)(Pick*, TES3::Vector3*, TES3::Vector3*, bool, float)>(NI_Pick_pickObjects)(this, origin, direction, append, maxDistance);
	}

	void Pick::clearResults() {
		reinterpret_cast<void(__thiscall*)(Pick*)>(NI_Pick_clearResults)(this);
	}

	std::reference_wrapper<unsigned short[3]> PickRecord::getVertexIndex() {
		return std::ref(vertexIndex);
	}

	TES3::Reference* PickRecord::getTES3Reference() {
		return getAssociatedReference(object);
	}
}
