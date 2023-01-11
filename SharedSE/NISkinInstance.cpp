#include "NISkinInstance.h"

namespace NI {
	void SkinInstance::deform(const NI::Vector3* srcVertices, const NI::Vector3* srcNormals, unsigned int vertexCount, NI::Vector3* dstVertices, NI::Vector3* dstNormals) const {
#if defined(SE_NI_SKININSTANCE_FNADDR_DEFORM) && SE_NI_SKININSTANCE_FNADDR_DEFORM > 0
		const auto NI_SkinInstance_Deform = reinterpret_cast<void(__thiscall*)(const NI::SkinInstance*, const NI::Vector3*, size_t, const NI::Vector3*, size_t, NI::Vector3*, NI::Vector3*, size_t)>(SE_NI_SKININSTANCE_FNADDR_DEFORM);
		return NI_SkinInstance_Deform(this, srcVertices, sizeof(Vector3), srcNormals, vertexCount, dstVertices, dstNormals, sizeof(Vector3));
#else
		throw not_implemented_exception();
#endif
	}
}
