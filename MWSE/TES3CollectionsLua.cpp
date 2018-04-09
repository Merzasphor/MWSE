#include "TES3CollectionsLua.h"

#include "LuaManager.h"

#include "TES3Collections.h"
#include "TES3Faction.h"
#include "TES3Inventory.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		void bindTES3Collections() {
			// Iterator bindings.
			bindIterator<TES3::EquipmentStack>("TES3EquipmentStackIterator");
			bindIterator<TES3::Reference>("TES3ReferenceIterator");
			bindIterator<TES3::Faction::ReactionNode>("TES3ReactionNodeIterator");
			bindIterator<TES3::ItemStack>("TES3ItemStackIterator");

			// Generic TES3::Object iterators. As above, but the result data will be
			// reinterpreted at runtime.
			bindGenericObjectIterator<TES3::MobileActor>("TES3MobileActorIterator");

			// TArray bindings.
			bindTArray<TES3::ItemVariables>("TES3ItemVariablesTArray");
		}
	}
}
