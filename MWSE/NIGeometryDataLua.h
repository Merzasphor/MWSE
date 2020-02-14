#pragma once

#include "NIObjectLua.h"
#include "NIGeometryData.h"

#include <nonstd/span.hpp>

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Node.
		template <typename T>
		void setUserdataForNIGeometryData(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("bounds", &NI::GeometryData::bounds);
			usertypeDefinition.set("compressFlags", &NI::GeometryData::compressFlags);
			usertypeDefinition.set("dataFlags", &NI::GeometryData::dataFlags);
			usertypeDefinition.set("dirtyFlags", &NI::GeometryData::dirtyFlags);
			usertypeDefinition.set("id", &NI::GeometryData::id);
			usertypeDefinition.set("keepFlags", &NI::GeometryData::keepFlags);
			usertypeDefinition.set("vertexCount", sol::readonly_property(&NI::GeometryData::getVertexCount));

			// Safe access to arrays.
			usertypeDefinition.set("colors", [](NI::GeometryData& self) { return nonstd::span(self.color, self.getVertexCount()); });
			usertypeDefinition.set("normals", [](NI::GeometryData& self) { return nonstd::span(self.normal, self.getVertexCount()); });
			usertypeDefinition.set("textures", [](NI::GeometryData& self) { return nonstd::span(self.texture, self.getVertexCount()); });
			usertypeDefinition.set("vertices", [](NI::GeometryData& self) { return nonstd::span(self.vertex, self.getVertexCount()); });

			// Basic function binding.
			usertypeDefinition.set("markAsChanged", &NI::GeometryData::markAsChanged);
		}

		void bindNIGeometryData();
	}
}
