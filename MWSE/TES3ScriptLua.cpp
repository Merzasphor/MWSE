#include "TES3ScriptLua.h"

#include "LuaManager.h"

#include "ScriptUtil.h"

#include "TES3Script.h"

namespace mwse {
	namespace lua {

		sol::object ScriptContext::index(std::string key) {
			sol::state& state = LuaManager::getInstance().getState();

			TES3::ScriptVariables* vars = getScriptVariables();

			unsigned int index = 0;
			char type = script->getLocalVarIndexAndType(key.c_str(), &index);
			switch (type) {
			case 's':
				return sol::make_object(state, vars->shortVarValues[index]);
			case 'l':
				return sol::make_object(state, vars->longVarValues[index]);
			case 'f':
				return sol::make_object(state, vars->floatVarValues[index]);
			}

			return sol::nil;
		}

		void ScriptContext::new_index(std::string key, sol::stack_object value) {
			if (!value.is<double>()) {
				return;
			}

			unsigned int index = 0;
			char type = script->getLocalVarIndexAndType(key.c_str(), &index);
			if (!type) {
				return;
			}

			TES3::ScriptVariables* vars = getScriptVariables();

			switch (type) {
			case 's':
				vars->shortVarValues[index] = value.as<double>();
				break;
			case 'l':
				vars->longVarValues[index] = value.as<double>();
				break;
			case 'f':
				vars->floatVarValues[index] = value.as<double>();
				break;
			}
		}

		size_t ScriptContext::length() {
			return (script->shortCount + script->longCount + script->floatCount);
		}

		TES3::ScriptVariables* ScriptContext::getScriptVariables() {
			// First, if we have an explicit variable set, use that.
			if (variables != NULL) {
				return variables;
			}

			// If we have a local script context, use that.
			TES3::ScriptVariables* localVariables = mwse::mwscript::getLocalScriptVariables();
			if (localVariables) {
				return localVariables;
			}

			// Otherwise, we resort to the script itself.
			return &script->varValues;
		}

		//
		//
		//

		sol::object getLocalVarData(TES3::Script* script, const char* name, bool useLocals = true) {
			sol::state& state = LuaManager::getInstance().getState();

			unsigned int index = 0;
			char type = script->getLocalVarIndexAndType(name, &index);
			switch (type) {
			case 's':
				return state.create_table_with("type", type, "index", index, "value", script->getShortValue(index, useLocals));
			case 'l':
				return state.create_table_with("type", type, "index", index, "value", script->getLongValue(index, useLocals));
			case 'f':
				return state.create_table_with("type", type, "index", index, "value", script->getFloatValue(index, useLocals));
			}
			return sol::nil;
		}

		sol::object getLocalVarData(TES3::Script* script, bool useLocals = true) {
			if (script->shortCount == 0 && script->longCount == 0 && script->floatCount == 0) {
				return sol::nil;
			}

			sol::state& state = LuaManager::getInstance().getState();
			sol::table results = state.create_table();

			// Append any short variables.
			for (int i = 0; i < script->shortCount; i++) {
				const char* varName = script->shortVarNamePointers[i];
				results[varName] = getLocalVarData(script, varName, useLocals);
			}

			// Append any long variables.
			for (int i = 0; i < script->longCount; i++) {
				const char* varName = script->longVarNamePointers[i];
				results[varName] = getLocalVarData(script, varName, useLocals);
			}

			// Append any float variables.
			for (int i = 0; i < script->floatCount; i++) {
				const char* varName = script->floatVarNamePointers[i];
				results[varName] = getLocalVarData(script, varName, useLocals);
			}

			return results;
		}

		void bindTES3Script() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<ScriptContext>("MWSEScriptContext",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				// Implement dynamic object metafunctions.
				sol::meta_function::index, &ScriptContext::index,
				sol::meta_function::new_index, &ScriptContext::new_index,
				sol::meta_function::length, &ScriptContext::length

				);

			state.new_usertype<TES3::Script>("TES3Script",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Script::objectType,

				"id", sol::readonly_property(&TES3::Script::getObjectID),
				"name", sol::property([](TES3::Script& self) { return self.name; }),

				"context", sol::readonly_property([](TES3::Script& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(&self, &self.varValues)); }),

				//
				// Functions.
				//

				"getVariableData", [](TES3::Script& self, sol::optional<bool> useLocals) { return getLocalVarData(&self, useLocals.value_or(true)); }

				);
		}
	}
}
