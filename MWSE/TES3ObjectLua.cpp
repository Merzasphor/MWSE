#include "TES3ActionDataLua.h"

#include "sol.hpp"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "NINode.h"

#include "TES3Object.h"
#include "TES3Cell.h"
#include "TES3GameFile.h"
#include "TES3ReferenceList.h"

namespace mwse {
	namespace lua {
		void bindTES3Object() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::BaseObject.
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::BaseObject>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Allow objects to be converted to strings using their object ID.
				usertypeDefinition.set(sol::meta_function::to_string, &TES3::BaseObject::getObjectID);

				// Basic property binding.
				usertypeDefinition.set("objectType", sol::readonly_property(&TES3::BaseObject::objectType));
				usertypeDefinition.set("objectFlags", sol::readonly_property(&TES3::BaseObject::objectFlags));

				// User-friendly access to object flags.
				//! TODO

				// Functions exposed as read-only properties.
				usertypeDefinition.set("id", sol::readonly_property(&TES3::BaseObject::getObjectID));
				usertypeDefinition.set("sourceMod", sol::readonly_property([](TES3::BaseObject& self) { return self.sourceMod->fileName; }));

				// Finish up our usertype.
				state.set_usertype("TES3BaseObject", usertypeDefinition);
			}

			// Binding for TES3::Object
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Object>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("owningCollection", sol::property([](TES3::Object& self) { return self.owningCollection.asReferenceList; }));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("nextInCollection", sol::readonly_property([](TES3::Object& self) { return makeLuaObject(self.nextInCollection); }));
				usertypeDefinition.set("previousInCollection", sol::readonly_property([](TES3::Object& self) { return makeLuaObject(self.previousInCollection); }));
				usertypeDefinition.set("sceneNode", sol::readonly_property([](TES3::Object& self) { return makeLuaObject(self.sceneNode); }));
				usertypeDefinition.set("sceneReference", sol::readonly_property([](TES3::Object& self) { return makeLuaObject(self.sceneGraphReference); }));

				// Finish up our usertype.
				state.set_usertype("TES3Object", usertypeDefinition);
			}

			// Binding for TES3::PhysicalObject
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::PhysicalObject>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Object, TES3::BaseObject>());

				// Basic property binding.
				usertypeDefinition.set("boundingBox", sol::readonly_property(&TES3::PhysicalObject::boundingBox));

				// Finish up our usertype.
				state.set_usertype("TES3PhysicalObject", usertypeDefinition);
			}
		}
	}
}
