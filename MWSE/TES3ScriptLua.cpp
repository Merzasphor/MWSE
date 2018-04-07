#include "TES3ScriptLua.h"

#include "LuaManager.h"

#include "TES3Script.h"

namespace mwse {
	namespace lua {
		sol::object getLocalVarData(TES3::Script* script, std::string& name, bool useLocals = true) {
			sol::state& state = LuaManager::getInstance().getState();

			unsigned int index = 0;
			char type = script->getLocalVarIndexAndType(name.c_str(), &index);
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

		void bindTES3Script() {
			LuaManager::getInstance().getState().new_usertype<TES3::Script>("TES3Script",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Script::objectType,

				"id", sol::readonly_property(&TES3::Script::getObjectID),
				"name", sol::property([](TES3::Script& self) { return self.name; }),

				"shortVariableCount", sol::readonly_property(&TES3::Script::shortCount),
				"longVariableCount", sol::readonly_property(&TES3::Script::longCount),
				"floatVariableCount", sol::readonly_property(&TES3::Script::floatCount),

				"shortVariableNames", sol::readonly_property([](TES3::Script& self) { return std::ref(self.shortVarNamePointers); }),
				"longVariableNames", sol::readonly_property([](TES3::Script& self) { return std::ref(self.longVarNamePointers); }),
				"floatVariableNames", sol::readonly_property([](TES3::Script& self) { return std::ref(self.floatVarNamePointers); }),

				"shortVariableValues", sol::readonly_property([](TES3::Script& self) { return std::ref(self.varValues.shortVarValues); }),
				"longVariableValues", sol::readonly_property([](TES3::Script& self) { return std::ref(self.varValues.longVarValues); }),
				"floatVariableValues", sol::readonly_property([](TES3::Script& self) { return std::ref(self.varValues.floatVarValues); }),

				//
				// Functions.
				//

				"getVariableData", [](TES3::Script& self, std::string name, bool useLocals = true) { return getLocalVarData(&self, name, useLocals); }

				);
		}
	}
}
