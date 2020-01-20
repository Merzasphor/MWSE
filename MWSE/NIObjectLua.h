#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Object.
		template <typename T>
		void setUserdataForNIObject(T& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["refCount"] = sol::readonly_property(&NI::Object::refCount);

			// Basic function binding.
			usertypeDefinition["clone"] = [](NI::Object& self) { return self.createClone(); };
			usertypeDefinition["isOfType"] = sol::resolve<bool(uintptr_t) const>(&NI::Object::isOfType);
			usertypeDefinition["isInstanceOfType"] = sol::resolve<bool(uintptr_t) const>(&NI::Object::isInstanceOfType);

			// Functions exposed as properties.
			usertypeDefinition["RTTI"] = sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); });
			usertypeDefinition["runTimeTypeInformation"] = sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); });
		}

		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNIObjectNET(T& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["controller"] = sol::readonly_property(&NI::ObjectNET::controllers);
			usertypeDefinition["name"] = sol::property(
				[](NI::ObjectNET& self) { return self.name; },
				[](NI::ObjectNET& self, const char * name) { self.setName(name); }
			);

			// Basic function binding.
			usertypeDefinition["prependController"] = &NI::ObjectNET::prependController;
			usertypeDefinition["removeController"] = &NI::ObjectNET::removeController;
			usertypeDefinition["removeAllControllers"] = &NI::ObjectNET::removeAllControllers;
		}

		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNIAVObject(T& usertypeDefinition) {
			setUserdataForNIObjectNET(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["properties"] = sol::readonly_property(&NI::AVObject::propertyNode);
			usertypeDefinition["flags"] = &NI::AVObject::flags;
			usertypeDefinition["scale"] = &NI::AVObject::localScale;
			usertypeDefinition["translation"] = &NI::AVObject::localTranslate;
			usertypeDefinition["worldBoundOrigin"] = &NI::AVObject::worldBoundOrigin;
			usertypeDefinition["worldBoundRadius"] = &NI::AVObject::worldBoundRadius;
			usertypeDefinition["worldTransform"] = &NI::AVObject::worldTransform;

			// Ensure that rotation calls the required functions.
			usertypeDefinition["rotation"] = sol::property(
				[](NI::AVObject& self) { return self.localRotation; },
				[](NI::AVObject& self, TES3::Matrix33* matrix) { self.setLocalRotationMatrix(matrix); }
			);

			// TODO: Deprecated. Remove before 2.1 releases.
			usertypeDefinition["localRotation"] = &NI::AVObject::localRotation;
			usertypeDefinition["localScale"] = &NI::AVObject::localScale;
			usertypeDefinition["localTranslate"] = &NI::AVObject::localTranslate;

			// Basic function binding.
			usertypeDefinition["attachProperty"] = &NI::AVObject::attachProperty;
			usertypeDefinition["clearTransforms"] = &NI::AVObject::clearTransforms;
			usertypeDefinition["propagatePositionChange"] = [](NI::AVObject& self) { self.update(); };
			usertypeDefinition["updateEffects"] = &NI::AVObject::updateEffects;
			usertypeDefinition["updateProperties"] = &NI::AVObject::updateProperties;

			// Functions that need their results wrapped.
			usertypeDefinition["getObjectByName"] = &NI::AVObject::getObjectByName;
			usertypeDefinition["getProperty"] = [](NI::AVObject& self, int type) { return self.getProperty(NI::PropertyType(type)); };
			usertypeDefinition["parent"] = sol::readonly_property(&NI::AVObject::parentNode);

			// Make remove property a bit more friendly.
			usertypeDefinition["detachProperty"] = [](NI::AVObject& self, int type) {
				NI::Pointer<NI::Property> prop;
				self.detachProperty(&prop, NI::PropertyType(type));
				return prop;
			};

			// Update function with table arguments.
			usertypeDefinition["update"] = [](NI::AVObject& self, sol::optional<sol::table> args) {
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
			};

			// Friendly access to flags.
			usertypeDefinition["appCulled"] = sol::property(&NI::AVObject::getAppCulled, &NI::AVObject::setAppCulled);

			// Legacy access. TODO: Remove.
			usertypeDefinition["propegatePositionChange"] = [](NI::AVObject& self) { self.update(); };
			usertypeDefinition["updateNodeEffects"] = &NI::AVObject::updateEffects;
		}

		void bindNIObject();
	}
}
