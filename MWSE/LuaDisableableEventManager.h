#pragma once

namespace mwse {
	namespace lua {
		namespace event {
			class DisableableEventManager {
			public:
				DisableableEventManager() = delete;
				~DisableableEventManager() = delete;

				static void bindToLua();
			};
		}
	}
}
