#pragma once

#include "sol_forward.hpp"

namespace mwse::lua
{

sol::object createActivator( sol::table params );
sol::object createMiscItem( sol::table params );
sol::object createStatic( sol::table params );

}
