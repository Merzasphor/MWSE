#pragma once

namespace mwse {
	class Configuration {
	public:
		static bool LogWarningsWithLuaStack;
		static bool EnableLegacyLuaMods;

		static sol::table getDefaults();

		static void bindToLua();
	};
}
