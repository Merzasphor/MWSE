#pragma once

#include "sol.hpp"

#include "TES3Object.h"

namespace mwse {
	namespace lua {
		template <typename T>
		T getOptionalParam(sol::optional<sol::table> maybeParams, const char* key, T defaultValue) {
			T value = defaultValue;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid() && maybeValue.is<T>()) {
					value = maybeValue.as<T>();
				}
			}

			return value;
		}

		template <typename T>
		T* getOptionalParamObject(sol::optional<sol::table> maybeParams, const char* key, TES3::ObjectType::ObjectType type) {
			T* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = tes3::getObjectByID<T>(maybeValue.as<std::string>(), type);
					}
					else if (maybeValue.is<T*>()) {
						value = maybeValue.as<T*>();
					}
				}
			}

			return value;

		}

		void bindScriptUtil();
	}
}
