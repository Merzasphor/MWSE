#pragma once

#include "TES3UIDefines.h"

#include "sol_forward.hpp"

namespace mwse {
	namespace lua {
		void bindTES3UIWidgets();
		sol::object makeWidget(TES3::UI::Element& element);
	}
}
