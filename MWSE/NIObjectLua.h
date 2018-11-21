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
			usertypeDefinition.set("isOfType", static_cast<bool (__thiscall NI::Object::*)(uintptr_t)>(&NI::Object::isOfType));
			usertypeDefinition.set("isInstanceOfType", static_cast<bool (__thiscall NI::Object::*)(uintptr_t)>(&NI::Object::isInstanceOfType));

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
			usertypeDefinition.set("properties", sol::readonly_property(&NI::AVObject::propertyNode));
			usertypeDefinition.set("flags", &NI::AVObject::flags);
			usertypeDefinition.set("rotation", &NI::AVObject::localRotation);
			usertypeDefinition.set("scale", &NI::AVObject::localScale);
			usertypeDefinition.set("translation", &NI::AVObject::localTranslate);
			usertypeDefinition.set("worldBoundOrigin", &NI::AVObject::worldBoundOrigin);
			usertypeDefinition.set("worldBoundRadius", &NI::AVObject::worldBoundRadius);
			usertypeDefinition.set("worldTransform", &NI::AVObject::worldTransform);

			// Ensure that rotation calls the required functions.
			usertypeDefinition.set("rotation", sol::property(
				[](NI::AVObject& self) { return self.localRotation; },
				[](NI::AVObject& self, TES3::Matrix33* matrix) { self.setLocalRotationMatrix(matrix); }
			));

			// TODO: Deprecated. Remove before 2.1 releases.
			usertypeDefinition.set("localRotation", &NI::AVObject::localRotation);
			usertypeDefinition.set("localScale", &NI::AVObject::localScale);
			usertypeDefinition.set("localTranslate", &NI::AVObject::localTranslate);

			// Basic function binding.
			usertypeDefinition.set("attachProperty", &NI::AVObject::attachProperty);
			usertypeDefinition.set("clearTransforms", &NI::AVObject::clearTransforms);
			usertypeDefinition.set("propegatePositionChange", [](NI::AVObject& self) { self.propagatePositionChange(); });
			usertypeDefinition.set("updateNodeEffects", &NI::AVObject::updateNodeEffects);
			usertypeDefinition.set("updateTextureProperties", &NI::AVObject::updateTextureProperties);

			// Functions that need their results wrapped.
			usertypeDefinition.set("getObjectByName", [](NI::AVObject& self, const char* name) { return makeLuaObject(self.getObjectByName(name)); });
			usertypeDefinition.set("getProperty", [](NI::AVObject& self, int type) { return makeLuaNiPointer(self.getProperty(type)); });
			usertypeDefinition.set("parent", sol::readonly_property([](NI::AVObject& self) { return makeLuaObject(self.parentNode); }));

			// Make remove property a bit more friendly.
			usertypeDefinition.set("detachProperty", [](NI::AVObject& self, int type) {
				NI::Pointer<NI::Property> prop;
				self.detachProperty(&prop, type);
				return makeLuaNiPointer(prop);
			});

			// Friendly access to flags.
			usertypeDefinition.set("appCulled", sol::property(
				[](NI::AVObject& self) -> bool { return (self.flags & 1) == 1; },
				[](NI::AVObject& self, bool set) { set ? self.flags |= 1 : self.flags &= ~1; }
			));
		}

		void bindNIObject();
	}
}
