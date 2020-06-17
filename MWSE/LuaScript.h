#pragma once

#include "DynamicLuaObject.h"

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
