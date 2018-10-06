#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Object.
		template <typename T>
		void setUserdataForNIObject(sol::simple_usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition.set("references", sol::readonly_property(&NI::Object::references));

			// Basic function binding.
			usertypeDefinition.set("clone", [](NI::Object& self) { return makeLuaObject(self.createClone()); });
			usertypeDefinition.set("isOfType", static_cast<bool (NI::Object::*)(uintptr_t)>(&NI::Object::isOfType));
			usertypeDefinition.set("isInstanceOfType", static_cast<bool (NI::Object::*)(uintptr_t)>(&NI::Object::isInstanceOfType));

			// Functions exposed as properties.
			usertypeDefinition.set("RTTI", sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); }));
			usertypeDefinition.set("runTimeTypeInformation", sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); }));
		}

		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNIObjectNET(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("controller", sol::readonly_property(&NI::ObjectNET::controllers));
			usertypeDefinition.set("name", sol::property(
				[](NI::ObjectNET& self) { return self.name; },
				[](NI::ObjectNET& self, const char * name) { self.setName(name); }
			));

			// Basic function binding.
			usertypeDefinition.set("prependController", &NI::ObjectNET::prependController);
			usertypeDefinition.set("removeController", &NI::ObjectNET::removeController);
			usertypeDefinition.set("removeAllControllers", &NI::ObjectNET::removeAllControllers);
		}

		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNIAVObject(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIObjectNET(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("flags", &NI::AVObject::flags);
			usertypeDefinition.set("localRotation", &NI::AVObject::localRotation);
			usertypeDefinition.set("localScale", &NI::AVObject::localScale);
			usertypeDefinition.set("localTranslate", &NI::AVObject::localTranslate);
			usertypeDefinition.set("worldBoundOrigin", &NI::AVObject::worldBoundOrigin);
			usertypeDefinition.set("worldBoundRadius", &NI::AVObject::worldBoundRadius);
			usertypeDefinition.set("worldTransform", &NI::AVObject::worldTransform);

			// Basic function binding.
			usertypeDefinition.set("clearTransforms", &NI::AVObject::clearTransforms);
			usertypeDefinition.set("updateNodeEffects", &NI::AVObject::updateNodeEffects);
			usertypeDefinition.set("updateTextureProperties", &NI::AVObject::updateTextureProperties);

			// Friendly access to flags.
			usertypeDefinition.set("appCulled", sol::property(
				[](NI::AVObject& self) -> bool { return (self.flags & 1) == 1; },
				[](NI::AVObject& self, bool set) { set ? self.flags |= 1 : self.flags &= ~1; }
			));

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("parent", sol::readonly_property([](NI::AVObject& self) { return makeLuaObject(self.parentNode); }));

			// Basic function binding.
			usertypeDefinition.set("getObjectByName", [](NI::AVObject& self, const char* name) { return makeLuaObject(self.getObjectByName(name)); });
		}

		void bindNIObject();
	}
}
