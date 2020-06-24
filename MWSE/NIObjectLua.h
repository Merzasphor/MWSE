#pragma once

#include "NIObject.h"
#include "NINode.h"
#include "NIRTTI.h"

#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Object.
		template <typename T>
		void setUserdataForNIObject(sol::usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["refCount"] = sol::readonly_property(&NI::Object::refCount);

			// Basic function binding.
			usertypeDefinition["clone"] = &NI::Object::createClone;
			usertypeDefinition["isOfType"] = sol::resolve<bool(uintptr_t) const>(&NI::Object::isOfType);
			usertypeDefinition["isInstanceOfType"] = sol::resolve<bool(uintptr_t) const>(&NI::Object::isInstanceOfType);
			usertypeDefinition["saveBinary"] = &NI::Object::saveBinary;

			// Functions exposed as properties.
			usertypeDefinition["RTTI"] = sol::readonly_property(&NI::Object::getRunTimeTypeInformation);
			usertypeDefinition["runTimeTypeInformation"] = sol::readonly_property(&NI::Object::getRunTimeTypeInformation);
		}

		// Speed-optimized binding for NI::ObjectNET.
		template <typename T>
		void setUserdataForNIObjectNET(sol::usertype<T>& usertypeDefinition) {
			setUserdataForNIObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["controller"] = sol::readonly_property(&NI::ObjectNET::controllers);
			usertypeDefinition["name"] = sol::property(&NI::ObjectNET::getName, &NI::ObjectNET::setName);

			// Basic function binding.
			usertypeDefinition["prependController"] = &NI::ObjectNET::prependController;
			usertypeDefinition["removeController"] = &NI::ObjectNET::removeController;
			usertypeDefinition["removeAllControllers"] = &NI::ObjectNET::removeAllControllers;
			usertypeDefinition["getGameReference"] &NI::ObjectNET::getTes3Reference_lua;
		}

		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNIAVObject(sol::usertype<T>& usertypeDefinition) {
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
			usertypeDefinition["rotation"] = sol::property(&NI::AVObject::getLocalRotationMatrix, &NI::AVObject::setLocalRotationMatrix);

			// TODO: Deprecated. Remove before 2.1 releases.
			usertypeDefinition["localRotation"] = &NI::AVObject::localRotation;
			usertypeDefinition["localScale"] = &NI::AVObject::localScale;
			usertypeDefinition["localTranslate"] = &NI::AVObject::localTranslate;

			// Basic function binding.
			usertypeDefinition["attachProperty"] = &NI::AVObject::attachProperty;
			usertypeDefinition["clearTransforms"] = &NI::AVObject::clearTransforms;
			usertypeDefinition["propagatePositionChange"] = &NI::AVObject::update_lua;
			usertypeDefinition["updateEffects"] = &NI::AVObject::updateEffects;
			usertypeDefinition["updateProperties"] = &NI::AVObject::updateProperties;

			// Functions that need their results wrapped.
			usertypeDefinition["getObjectByName"] = &NI::AVObject::getObjectByName;
			usertypeDefinition["getProperty"] = &NI::AVObject::getProperty;
			usertypeDefinition["parent"] = sol::readonly_property(&NI::AVObject::parentNode);

			// Make remove property a bit more friendly.
			usertypeDefinition["detachProperty"] = &NI::AVObject::detachPropertyByType;

			// Update function with table arguments.
			usertypeDefinition["update"] = &NI::AVObject::update_lua;

			// Friendly access to flags.
			usertypeDefinition["appCulled"] = sol::property(&NI::AVObject::getAppCulled, &NI::AVObject::setAppCulled);

			// Legacy access. TODO: Remove.
			usertypeDefinition["propegatePositionChange"] = &NI::AVObject::update_lua;
			usertypeDefinition["updateNodeEffects"] = &NI::AVObject::updateEffects;
		}

		void bindNIObject();
	}
}
