#include "LuaDisableableEventManager.h"

#include "LuaManager.h"

#include "LuaInfoFilterEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			void DisableableEventManager::bindToLua() {
				// Get our lua state.
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;

				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<DisableableEventManager>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Give access to the enabled state.
				usertypeDefinition.set("infoFilter", sol::property(&InfoFilterEvent::getEventEnabled, &InfoFilterEvent::setEventEnabled));

				// Finish up our usertype.
				state.set_usertype("mwseDisableableEventManager", usertypeDefinition);
			}
		}
	}
}
