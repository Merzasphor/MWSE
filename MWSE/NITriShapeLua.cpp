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
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for NI::TriShape.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TriShape>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::AVObject, NI::ObjectNET, NI::Object>());
				setUserdataForNIAVObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("data", sol::property(&NI::TriShape::getModelData, &NI::TriShape::setModelData));

				// Finish up our usertype.
				state.set_usertype("niTriShape", usertypeDefinition);
			}
		}
	}
}
