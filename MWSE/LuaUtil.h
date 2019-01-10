#pragma once

#include "sol.hpp"

#include "NIDefines.h"
#include "NIPointer.h"

#include "TES3Defines.h"

#include "TES3DataHandler.h"
#include "TES3Vectors.h"

#include <unordered_map>

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
		T* getOptionalParamObject(sol::optional<sol::table> maybeParams, const char* key) {
			T* value = NULL;

			if (maybeParams) {
				sol::table params = maybeParams.value();
				sol::object maybeValue = params[key];
				if (maybeValue.valid()) {
					if (maybeValue.is<std::string>()) {
						value = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<T>(maybeValue.as<std::string>().c_str());
					}
					else if (maybeValue.is<T*>()) {
						value = maybeValue.as<T*>();
					}
				}
			}

			return value;
		}

		TES3::Script* getOptionalParamExecutionScript(sol::optional<sol::table> maybeParams);
		TES3::Reference* getOptionalParamExecutionReference(sol::optional<sol::table> maybeParams);
		TES3::Script* getOptionalParamScript(sol::optional<sol::table> maybeParams, const char* key);
		TES3::Reference* getOptionalParamReference(sol::optional<sol::table> maybeParams, const char* key);
		TES3::MobileActor* getOptionalParamMobileActor(sol::optional<sol::table> maybeParams, const char* key);
		TES3::Spell* getOptionalParamSpell(sol::optional<sol::table> maybeParams, const char* key);
		TES3::Dialogue* getOptionalParamDialogue(sol::optional<sol::table> maybeParams, const char* key);
		TES3::Sound* getOptionalParamSound(sol::optional<sol::table> maybeParams, const char* key);
		sol::optional<TES3::Vector3> getOptionalParamVector3(sol::optional<sol::table> maybeParams, const char* key);
		TES3::Cell* getOptionalParamCell(sol::optional<sol::table> maybeParams, const char* key);

		void setVectorFromLua(TES3::Vector3*, sol::stack_object);

		sol::object makeLuaObject(TES3::BaseObject* object);
		sol::object makeLuaObject(TES3::MobileObject* object);
		sol::object makeLuaObject(TES3::Weather* weather);
		sol::object makeLuaObject(TES3::GameFile* gameFile);
		sol::object makeLuaObject(NI::Object* object);

		// Creates a NI::Pointer and packages it into a sol::object for reference counting.
		sol::object makeLuaNiPointer(NI::Object* object);

		// Dumps the current stacktrace to the log.
		void logStackTrace(const char* message = nullptr);
	}
}
