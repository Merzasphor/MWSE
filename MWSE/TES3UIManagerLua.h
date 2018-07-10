#pragma once

#include "sol.hpp"
#include "TES3UIElement.h"

namespace mwse {
	namespace lua {
		void registerUIEvent(TES3::UI::Element& target, TES3::UI::Property eventID, sol::protected_function callback);
		void unregisterUIEvent(TES3::UI::Element& target, TES3::UI::Property eventID);

		void bindTES3UIManager();
	}
}
