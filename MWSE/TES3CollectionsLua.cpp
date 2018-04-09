#include "TES3CollectionsLua.h"

#include "LuaManager.h"

#include "TES3Collections.h"
#include "TES3Inventory.h"

namespace mwse {
	namespace lua {
		void bindTES3Collections() {
			bindTArray<TES3::ItemVariables>("TES3ItemVariablesTArray");
		}
	}
}
