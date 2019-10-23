#include "NISwitchNode.h"

#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDefines.h"
#include "NIRTTI.h"
#include "NITriShape.h"

namespace mwse {
	namespace lua {
		void bindNITriShape() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for NI::TriShape.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TriShape>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::TriBasedGeometry, NI::Geometry, NI::AVObject, NI::ObjectNET, NI::Object>());
				setUserdataForNIAVObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("data", sol::property(&NI::TriShape::getModelData, &NI::TriShape::setModelData));

				// Get vertex list as a self-contained collection.
				usertypeDefinition.set("vertices", sol::readonly_property(
					[](NI::TriShape& self) {
						auto data = self.getModelData();
						std::vector<TES3::Vector3*> vertices;
						for (unsigned short i = 0; i < data->vertexCount; i++) {
							vertices.push_back(&data->vertex[i]);
						}
						return std::move(vertices);
					}
				));

				// Finish up our usertype.
				state.set_usertype("niTriShape", usertypeDefinition);
			}
		}
	}
}
