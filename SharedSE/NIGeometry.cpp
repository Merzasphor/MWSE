#include "NIGeometry.h"

namespace NI {

	void Geometry::updateDeforms() {
		updateDeforms(worldVertices, worldNormals);
	}

	void Geometry::updateDeforms(Vector3* out_vertices, Vector3* out_normals) {
		if (skinInstance == nullptr) {
			return;
		}

		skinInstance->deform(modelData->vertex, modelData->normal, modelData->getActiveVertexCount(), out_vertices, out_normals);
		TransformVertices(out_vertices, modelData->getActiveVertexCount(), out_vertices, &worldTransform);
	}

	void __cdecl TransformVertices(Vector3* out_vertices, unsigned short vertexCount, const Vector3* in_vertices, const Transform* transform) {
		for (auto i = 0u; i < vertexCount; ++i) {
			out_vertices[i] = (transform->rotation * transform->scale * in_vertices[i]) + transform->translation;
		}
	}
}
