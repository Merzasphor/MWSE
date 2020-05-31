#pragma once

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Object.
		template <typename T>
		void setUserdataForNIObject(sol::simple_usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition.set("refCount", sol::readonly_property(&NI::Object::refCount));

			// Basic function binding.
			usertypeDefinition.set("clone", [](NI::Object& self) { return makeLuaNiPointer(self.createClone()); });
			usertypeDefinition.set("isOfType", static_cast<bool (__thiscall NI::Object::*)(uintptr_t)>(&NI::Object::isOfType));
			usertypeDefinition.set("isInstanceOfType", static_cast<bool (__thiscall NI::Object::*)(uintptr_t)>(&NI::Object::isInstanceOfType));
			usertypeDefinition.set("saveBinary", &NI::Object::saveBinary);

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
			usertypeDefinition.set("propagatePositionChange", [](NI::AVObject& self) { self.update(); });
			usertypeDefinition.set("updateEffects", &NI::AVObject::updateEffects);
			usertypeDefinition.set("updateProperties", &NI::AVObject::updateProperties);

			// Functions that need their results wrapped.
			usertypeDefinition.set("getObjectByName", [](NI::AVObject& self, const char* name) { return makeLuaNiPointer(self.getObjectByName(name)); });
			usertypeDefinition.set("getProperty", [](NI::AVObject& self, int type) { return makeLuaNiPointer(self.getProperty(NI::PropertyType(type))); });
			usertypeDefinition.set("parent", sol::readonly_property([](NI::AVObject& self) { return makeLuaNiPointer(self.parentNode); }));

			// Make remove property a bit more friendly.
			usertypeDefinition.set("detachProperty", [](NI::AVObject& self, int type) {
				NI::Pointer<NI::Property> prop;
				self.detachProperty(&prop, NI::PropertyType(type));
				return makeLuaNiPointer(prop);
			});

			// Update function with table arguments.
			usertypeDefinition.set("update", [](NI::AVObject& self, sol::optional<sol::table> args) {
				if (args) {
					auto values = args.value();
					float time = values.get_or("time", 0.0f);
					bool updateControllers = values.get_or("controllers", false);
					bool updateBounds = values.get_or("bounds", true);

					self.update(time, updateControllers, updateBounds);
				}
				else {
					self.update();
				}
			});

			// Friendly access to flags.
			usertypeDefinition.set("appCulled", sol::property(&NI::AVObject::getAppCulled, &NI::AVObject::setAppCulled));

			// Legacy access. TODO: Remove.
			usertypeDefinition.set("propegatePositionChange", [](NI::AVObject& self) { self.update(); });
			usertypeDefinition.set("updateNodeEffects", &NI::AVObject::updateEffects);
		}

		void bindNIObject();
	}
}
