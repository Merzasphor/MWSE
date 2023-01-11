#include "NIPick.h"

#include "NIGeometry.h"

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

	bool Pick::pickObjectsWithSkinDeforms(const Vector3* origin, const Vector3* direction, bool append, float maxDistance) {
		// Data to restore skinned objects to their original state.
		std::unordered_map<Geometry*, Pointer<SkinInstance>> replacedSkinInstances;
		std::unordered_map<Geometry*, std::vector<Vector3>> replacedVertices;
		std::unordered_map<Geometry*, std::vector<Vector3>> replacedNormals;

		// Perform our first test.
		if (!pickObjects(origin, direction, append, maxDistance)) {
			return false;
		}

		// Store if a redo is needed.
		auto needsRedo = false;

		// Check to see if any skinned objects were hit.
		for (auto& result : results) {
			if (result == nullptr) {
				continue;
			}

			// Skip if we're not affecting tri-based geometry.
			const auto geometry = result->object;
			if (!geometry->isInstanceOfType(RTTIStaticPtr::NiTriBasedGeom)) {
				continue;
			}

			// If the geometry is skinned we apply the skin deform and set the redo flag.
			// This way the redo raycast (and future raycasts) can handle the object correctly.
			if (geometry->skinInstance) {
				needsRedo = true;

				// temporary copy vertices/normals
				const auto& data = geometry->modelData;
				const auto count = data->vertexCount;
				const auto vertices = data->vertex;
				const auto normals = data->normal;

				// Backup vertices.
				auto& srcVertices = replacedVertices[geometry];
				srcVertices.reserve(count);
				srcVertices.insert(srcVertices.end(), &vertices[0], &vertices[count]);

				// Backup normals.
				auto& srcNormals = replacedNormals[geometry];
				srcNormals.reserve(count);
				srcNormals.insert(srcNormals.end(), &normals[0], &normals[count]);

				// Apply the skin deform
				geometry->skinInstance->deform(srcVertices.data(), srcNormals.data(), data->vertexCount, data->vertex, data->normal);
				data->markAsChanged();

				// Remove the skin instance, but back it up in our restore data.
				replacedSkinInstances[geometry] = geometry->skinInstance;
				geometry->skinInstance = nullptr;

				geometry->update();
			}
		}

		// Perform another raytest if necessary.
		// TODO: To optimize this further, perform a second pick in another root with only the skinned geometry, and update the existing distances.
		if (needsRedo) {
			clearResults();
			pickObjects(origin, direction, append, maxDistance);
		}

		// Restore existing geomtry data.
		for (auto& [geometry, skinInstance] : replacedSkinInstances) {
			const auto& data = geometry->modelData;

			auto& srcVertices = replacedVertices[geometry];
			memcpy_s(data->vertex, sizeof(Vector3) * data->vertexCount, srcVertices.data(), sizeof(Vector3) * srcVertices.size());

			auto& srcNormals = replacedNormals[geometry];
			memcpy_s(data->normal, sizeof(Vector3) * data->vertexCount, srcNormals.data(), sizeof(Vector3) * srcNormals.size());

			geometry->skinInstance = skinInstance;

			data->markAsChanged();
			geometry->update();
		}

		return true;
	}

	void Pick::clearResults() {
#if defined(SE_NI_PICK_FNADDR_CLEARRESULTS) && SE_NI_PICK_FNADDR_CLEARRESULTS > 0
		const auto TES3_Pick_clearResults = reinterpret_cast<void(__thiscall*)(Pick*)>(SE_NI_PICK_FNADDR_CLEARRESULTS);
		TES3_Pick_clearResults(this);
#else
		throw not_implemented_exception();
#endif
	}

	PickRecord* Pick::getFirstUnskinnedResult() const {
		for (const auto& result : results) {
			if (result && result->object && result->object->skinInstance == nullptr) {
				return result;
			}
		}
		return nullptr;
	}

	std::reference_wrapper<unsigned short[3]> PickRecord::getVertexIndex() {
		return std::ref(vertexIndex);
	}
}
