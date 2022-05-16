#pragma once

#include "MGEApi.h"

namespace mge {
	class ShaderHandleLua {
	public:
		ShaderHandleLua(ShaderHandle h);
		~ShaderHandleLua();

		//
		// Basic utility functions.
		//

		bool reload();
		inline auto getName() const { return name; }
		inline auto getEnabled() const { return mge::api->shaderGetEnabled(handle); }
		void setEnabled(bool value) { mge::api->shaderSetEnabled(handle, value); }

		//
		// Convenience functions for lua.
		//

		std::string toJson() const;
		sol::table listVariables(sol::this_state ts) const;
		sol::object getVariable(sol::this_state ts, const char* varName) const;
		void setVariable(const char* varName, sol::stack_object value);

	private:
		void initialize();

		ShaderHandle handle;
		std::string name;
		std::unordered_map<std::string, char> variableTypes;
	};
}
