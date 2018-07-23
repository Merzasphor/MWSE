#pragma once

#include "sol.hpp"
#include "TES3UIElement.h"

namespace mwse {
	namespace lua {
		void registerUIEvent(TES3::UI::Element& target, TES3::UI::Property eventID, sol::protected_function callback);
		void unregisterUIEvent(TES3::UI::Element& target, TES3::UI::Property eventID);
		TES3::UI::Boolean eventForwarder(sol::table eventData);
		void triggerEvent(TES3::UI::Element& target, TES3::UI::Property eventID, int data0, int data1);

		void bindTES3UIManager();
	}
}
