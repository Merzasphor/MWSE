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
		inline auto getEnabled() const { return api->shaderGetEnabled(handle); }
		inline void setEnabled(bool value) { api->shaderSetEnabled(handle, value); }
		inline auto getPriority() const { return api->shaderGetPriority(handle); }
		inline void setPriority(int value) { api->shaderSetPriority(handle, value); }

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
