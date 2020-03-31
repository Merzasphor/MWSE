#include "NIGeometryDataLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIGeometryData.h"
#include "NIRTTI.h"
#include "NiTriBasedGeometryData.h"
#include "NITriShapeData.h"

namespace mwse::lua {
	void bindNIGeometryData() {
		// Get our lua state.
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		// Bind NI::GeometryData
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::GeometryData>("niGeometryData");
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
			usertypeDefinition.set("new", sol::no_constructor);

			// Base class binding.
			setUserdataForNIGeometryData(usertypeDefinition);
		}

		// Bind NI::TriBasedGeometryData
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::TriBasedGeometryData>("niTriBasedGeometryData");
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::GeometryData>());
			usertypeDefinition.set("new", sol::no_constructor);

			// Base class binding.
			setUserdataForNIGeometryData(usertypeDefinition);

			// Functions exposed as properties.
			usertypeDefinition.set("triangleCount", sol::readonly_property(&NI::TriBasedGeometryData::getTriangleCount));
		}

		// Bind NI::TriBasedGeometryData
		{
			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<NI::TriShapeData>("niTriShapeData");
			usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object, NI::GeometryData, NI::TriBasedGeometryData>());
			usertypeDefinition.set("new", sol::no_constructor);

			// Base class binding.
			setUserdataForNIGeometryData(usertypeDefinition);

			// Functions exposed as properties.
			usertypeDefinition.set("triangleCount", sol::readonly_property(&NI::TriShapeData::getTriangleCount));
		}
	}
}
