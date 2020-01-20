#pragma once

#include "sol.hpp"

#include "LuaUtil.h"

#include "NINode.h"
#include "TES3GameFile.h"
#include "TES3ReferenceList.h"

#include "BitUtil.h"

namespace mwse {
	namespace lua {
		template <typename T>
		void setUserdataForBaseObject(sol::usertype<T>& usertypeDefinition) {
			// Basic property binding.
			usertypeDefinition["objectType"] = sol::readonly_property(&T::objectType);
			usertypeDefinition["objectFlags"] = sol::readonly_property(&T::objectFlags);

			// Allow object to be converted to strings using their object ID.
			usertypeDefinition[sol::meta_function::to_string] = &T::getObjectID;

			// Allow objects to be serialized to json using their ID.
			usertypeDefinition["__tojson"] = [](T& self, sol::table state) {
				std::ostringstream ss;
				ss << "\"tes3baseObject:" << self.getObjectID() << "\"";
				return ss.str();
			};

			// Functions exposed as properties.
			usertypeDefinition["id"] = sol::readonly_property(&T::getObjectID);
			usertypeDefinition["sourceMod"] = sol::readonly_property([](T& self) -> const char* {
				if (self.sourceMod) {
					return self.sourceMod->filename;
				}
				return nullptr;
			});
			usertypeDefinition["modified"] = sol::property(&T::getObjectModified, &T::setObjectModified);
			usertypeDefinition["disabled"] = sol::readonly_property([](T& self) { return BIT_TEST(self.objectFlags, TES3::ObjectFlag::DisabledBit); });
			usertypeDefinition["deleted"] = sol::readonly_property([](T& self) { return BIT_TEST(self.objectFlags, TES3::ObjectFlag::DeleteBit); });
		}

		template <typename T>
		void setUserdataForObject(sol::usertype<T>& usertypeDefinition) {
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["nextInCollection"] = sol::readonly_property(&T::nextInCollection);
			usertypeDefinition["previousInCollection"] = sol::readonly_property(&T::previousInCollection);
			usertypeDefinition["scale"] = sol::property(&T::getScale, &T::setScale);
			usertypeDefinition["sceneNode"] = sol::readonly_property(&T::sceneNode);
			usertypeDefinition["sceneCollisionRoot"] = sol::readonly_property(&T::sceneCollisionRoot);

			// Indirect bindings to unions and arrays.
			usertypeDefinition["owningCollection"] = sol::property([](T& self) { return self.owningCollection.asReferenceList; });
		}

		template <typename T>
		void setUserdataForPhysicalObject(sol::usertype<T>& usertypeDefinition) {
			setUserdataForObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["boundingBox"] = sol::readonly_property(&T::boundingBox);

			// Functions exposed as properties.
			usertypeDefinition["stolenList"] = sol::readonly_property(&T::getStolenList);
		}
	}
}