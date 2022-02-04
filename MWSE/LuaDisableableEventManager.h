#pragma once

namespace mwse::lua::event {
	class DisableableEventManager {
	public:
		DisableableEventManager() = delete;
		~DisableableEventManager() = delete;

		static void bindToLua();
	};
}
