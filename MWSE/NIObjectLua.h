#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Object.
		template <typename T>
		void setUserdataForNIObject(sol::usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["refCount"] = sol::readonly_property(&T::refCount);

			// Basic function binding.
			usertypeDefinition["clone"] = &T::createClone;
			usertypeDefinition["isOfType"] = sol::resolve<bool(uintptr_t) const>(&T::isOfType);
			usertypeDefinition["isInstanceOfType"] = sol::resolve<bool(uintptr_t) const>(&T::isInstanceOfType);
			usertypeDefinition["saveBinary"] = &T::saveBinary;

			// Functions exposed as properties.
			usertypeDefinition["RTTI"] = sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); });
			usertypeDefinition["runTimeTypeInformation"] = sol::readonly_property([](NI::Object& self) { return self.getRunTimeTypeInformation(); });
		}

		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNIObjectNET(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["controller"] = sol::readonly_property(&T::controllers);
			usertypeDefinition["name"] = sol::property(
				[](T& self) { return self.name; },
				[](T& self, const char * name) { self.setName(name); }
			);

			// Basic function binding.
			usertypeDefinition["prependController"] = &T::prependController;
			usertypeDefinition["removeController"] = &T::removeController;
			usertypeDefinition["removeAllControllers"] = &T::removeAllControllers;
		}

		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNIAVObject(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIObjectNET(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["properties"] = sol::readonly_property(&T::propertyNode);
			usertypeDefinition["flags"] = &T::flags;
			usertypeDefinition["scale"] = &T::localScale;
			usertypeDefinition["translation"] = &T::localTranslate;
			usertypeDefinition["worldBoundOrigin"] = &T::worldBoundOrigin;
			usertypeDefinition["worldBoundRadius"] = &T::worldBoundRadius;
			usertypeDefinition["worldTransform"] = &T::worldTransform;

			// Ensure that rotation calls the required functions.
			usertypeDefinition["rotation"] = sol::property(
				[](T& self) { return self.localRotation; },
				[](T& self, TES3::Matrix33* matrix) { self.setLocalRotationMatrix(matrix); }
			);

			// TODO: Deprecated. Remove before 2.1 releases.
			usertypeDefinition["localRotation"] = &T::localRotation;
			usertypeDefinition["localScale"] = &T::localScale;
			usertypeDefinition["localTranslate"] = &T::localTranslate;

			// Basic function binding.
			usertypeDefinition["attachProperty"] = &T::attachProperty;
			usertypeDefinition["clearTransforms"] = &T::clearTransforms;
			usertypeDefinition["propagatePositionChange"] = [](T& self) { self.update(); };
			usertypeDefinition["updateEffects"] = &T::updateEffects;
			usertypeDefinition["updateProperties"] = &T::updateProperties;

			// Functions that need their results wrapped.
			usertypeDefinition["getObjectByName"] = &T::getObjectByName;
			usertypeDefinition["getProperty"] = [](T& self, int type) { return self.getProperty(NI::PropertyType(type)); };
			usertypeDefinition["parent"] = sol::readonly_property(&T::parentNode);

			// Make remove property a bit more friendly.
			usertypeDefinition["detachProperty"] = [](T& self, int type) {
				NI::Pointer<NI::Property> prop;
				self.detachProperty(&prop, NI::PropertyType(type));
				return prop;
			};

			// Update function with table arguments.
			usertypeDefinition["update"] = [](T& self, sol::optional<sol::table> args) {
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
			usertypeDefinition["appCulled"] = sol::property(&T::getAppCulled, &T::setAppCulled);

			// Legacy access. TODO: Remove.
			usertypeDefinition["propegatePositionChange"] = [](T& self) { self.update(); };
			usertypeDefinition["updateNodeEffects"] = &T::updateEffects;
		}

		void bindNIObject();
	}
}
