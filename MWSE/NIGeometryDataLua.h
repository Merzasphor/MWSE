#pragma once

#include "NIObjectLua.h"
#include "NIGeometryData.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Node.
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
			usertypeDefinition["colors"] = sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.color, self.vertexCount); });
			usertypeDefinition["normals"] = sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.normal, self.vertexCount); });
			usertypeDefinition["textures"] = sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.texture, self.vertexCount); });
			usertypeDefinition["vertices"] = sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.vertex, self.vertexCount); });

			// Basic function binding.
			usertypeDefinition["markAsChanged"] = &NI::GeometryData::markAsChanged;
		}

		void bindNIGeometryData();
	}
}
