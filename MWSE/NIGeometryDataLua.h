#pragma once

#include "NIObjectLua.h"
#include "NIGeometryData.h"

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
			usertypeDefinition.set("colors", sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.color, self.vertexCount); }));
			usertypeDefinition.set("normals", sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.normal, self.vertexCount); }));
			usertypeDefinition.set("textures", sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.texture, self.vertexCount); }));
			usertypeDefinition.set("vertices", sol::readonly_property([](NI::GeometryData& self) { return nonstd::span(self.vertex, self.vertexCount); }));

			// Basic function binding.
			usertypeDefinition.set("markAsChanged", &NI::GeometryData::markAsChanged);
		}

		void bindNIGeometryData();
	}
}
