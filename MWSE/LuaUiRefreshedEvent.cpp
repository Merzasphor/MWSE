#include "LuaUiRefreshedEvent.h"

#include "LuaManager.h"

#include "TES3UIElement.h"

namespace mwse::lua::event {
	UiRefreshedEvent::UiRefreshedEvent(TES3::UI::Element* element) :
		GenericEvent("uiRefreshed"),
		m_Element(element)
	{

	}

	sol::table UiRefreshedEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table eventData = state.create_table();

		eventData["element"] = m_Element;

		return eventData;
	}

	sol::object UiRefreshedEvent::getEventOptions() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;
		sol::table options = state.create_table();

		options["filter"] = m_Element->name.cString;

		return options;
	}

	bool UiRefreshedEvent::m_EventEnabled = false;
}
