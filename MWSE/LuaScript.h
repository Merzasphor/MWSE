#pragma once

#include "sol.hpp"

#include "DynamicLuaObject.h"

#include "TES3Object.h"

namespace mwse {
	namespace lua {
		struct LuaScript : public DynamicLuaObject {
			LuaScript() :
				script(NULL),
				reference(NULL) {

			}
			TES3::Script * script;
			TES3::Reference * reference;
		};
	}
}
