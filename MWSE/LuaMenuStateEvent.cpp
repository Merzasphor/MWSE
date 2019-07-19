#include "LuaMenuStateEvent.h"

#include "LuaManager.h"

#include "UIUtil.h"

#include "TES3UIElement.h"

namespace mwse {
	namespace lua {
		namespace event {
			MenuStateEvent::MenuStateEvent(bool inMenuMode) :
				m_InMenuMode(inMenuMode)
			{

			}

			const char* MenuStateEvent::getEventName() {
				if (m_InMenuMode) {
					return "menuEnter";
				}
				else {
					return "menuExit";
				}
			}

			sol::table MenuStateEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				eventData["menuMode"] = m_InMenuMode;
				if (m_InMenuMode) {
					eventData["menu"] = tes3::ui::getTopMenu();
				}

				return eventData;
			}

			sol::object MenuStateEvent::getEventOptions() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table options = state.create_table();

				auto menu = tes3::ui::getTopMenu();
				if (menu) {
					options["filter"] = menu->name.cString;
				}

				return options;
			}

			bool MenuStateEvent::m_EventEnabled = false;
		}
	}
}
