#pragma once

#include "sol_forward.hpp"

#include "TES3Object.h"

namespace mwse {
	namespace lua {
		sol::object makeLuaObject(TES3::BaseObject* object);
		sol::object makeLuaObject(TES3::MobileActor* actor);
	}
}
