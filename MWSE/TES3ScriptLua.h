#pragma once

#include "sol_forward.hpp"

#include <cstddef>
#include <string>

#include "TES3Object.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		class ScriptContext {
		public:
			ScriptContext(TES3::Script* s, TES3::ScriptVariables* v = NULL) {
				script = s;
				variables = v;
			}

			sol::object index(std::string);
			void new_index(std::string, sol::stack_object);
			size_t length();

		private:
			TES3::Script* script;
			TES3::ScriptVariables* variables;

			TES3::ScriptVariables* getScriptVariables();
		};

		void bindTES3Script();
	}
}