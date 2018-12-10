#include "NIObjectLua.h"

#include "sol.hpp"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIDefines.h"
#include "NIAVObject.h"
#include "NINode.h"
#include "NIObject.h"
#include "NIObjectNET.h"
#include "NIPointer.h"
#include "NIRTTI.h"

namespace mwse {
	namespace lua {
		void bindNIObject() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for NI::RTTI.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::RTTI>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("name", &NI::RTTI::name);
				usertypeDefinition.set("parent", &NI::RTTI::baseRTTI);

				// Finish up our usertype.
				state.set_usertype("niRTTI", usertypeDefinition);
			}

			// Binding for NI::Object.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::Object>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Inherit NI::Object.
				setUserdataForNIObject(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niObject", usertypeDefinition);
			}

			// Binding for NI::ObjectNET.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::ObjectNET>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
				setUserdataForNIObjectNET(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niObjectNET", usertypeDefinition);
			}

			// Binding for NI::AVObject.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::AVObject>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::ObjectNET, NI::Object>());
				setUserdataForNIAVObject(usertypeDefinition);

				// Finish up our usertype.
				state.set_usertype("niAVObject", usertypeDefinition);
			}

			// Binding for NI::AVObject::PropertyListNode.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::AVObject::PropertyListNode>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("data", sol::readonly_property([](NI::AVObject::PropertyListNode& self) { return makeLuaNiPointer(self.data); }));
				usertypeDefinition.set("next", &NI::AVObject::PropertyListNode::next);

				// Finish up our usertype.
				state.set_usertype("niAVObjectPropertyListNode", usertypeDefinition);
			}
		}
	}
}
