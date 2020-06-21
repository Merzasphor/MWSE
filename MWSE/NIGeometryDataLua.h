#pragma once

#include "NIObjectLua.h"
#include "NIGeometryData.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForNIGeometryData(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["bounds"] = &NI::GeometryData::bounds;
			usertypeDefinition["compressFlags"] = &NI::GeometryData::compressFlags;
			usertypeDefinition["dataFlags"] = &NI::GeometryData::dataFlags;
			usertypeDefinition["dirtyFlags"] = &NI::GeometryData::dirtyFlags;
			usertypeDefinition["id"] = &NI::GeometryData::id;
			usertypeDefinition["keepFlags"] = &NI::GeometryData::keepFlags;
			usertypeDefinition["vertexCount"] = sol::readonly_property(&NI::GeometryData::getVertexCount);

			// Safe access to arrays.
			usertypeDefinition["colors"] = sol::readonly_property(&NI::GeometryData::getColors);
			usertypeDefinition["normals"] = sol::readonly_property(&NI::GeometryData::getNormals);
			usertypeDefinition["textures"] = sol::readonly_property(&NI::GeometryData::getTextureCoordinates);
			usertypeDefinition["vertices"] = sol::readonly_property(&NI::GeometryData::getVertices);

			// Basic function binding.
			usertypeDefinition["markAsChanged"] = &NI::GeometryData::markAsChanged;
		}

		void bindNIGeometryData();
	}
}
