#pragma once

#include "TES3UIDefines.h"


namespace mwse {
	namespace lua {
		void bindTES3UIWidgets();
		sol::object makeWidget(TES3::UI::Element& element);
		std::string getWidgetText(TES3::UI::Element& element);
		void setWidgetText(TES3::UI::Element& element, const char* text);
	}
}
