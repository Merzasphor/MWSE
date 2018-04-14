#include "TES3ReferenceLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3ReferenceList() {
			sol::state& state = LuaManager::getInstance().getState();
			
			state.new_usertype<TES3::ReferenceList>("TES3ReferenceList",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties
				//

				"size", sol::readonly_property(&TES3::ReferenceList::size),
				"head", sol::readonly_property(&TES3::ReferenceList::head),
				"tail", sol::readonly_property(&TES3::ReferenceList::tail)

				);
		}
	}
}
