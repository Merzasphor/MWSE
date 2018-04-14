#include "TES3CollectionsLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		void bindTES3Collections() {
			// Iterator bindings.
			bindIterator<TES3::EquipmentStack>("TES3EquipmentStackIterator", "TES3EquipmentStackIteratorNode");
			bindIterator<TES3::Reference>("TES3ReferenceIterator", "TES3ReferenceIteratorNode");
			bindIterator<TES3::Faction::ReactionNode>("TES3ReactionNodeIterator", "TES3ReactionNodeIteratorNode");
			bindIterator<TES3::ItemStack>("TES3ItemStackIterator", "TES3ItemStackIteratorNode");

			// Generic TES3::Object iterators. As above, but the result data will be
			// reinterpreted at runtime.
			bindGenericObjectIterator<TES3::MobileActor>("TES3MobileActorIterator");

			// TArray bindings.
			bindTArray<TES3::ItemData>("TES3ItemDataTArray");
		}
	}
}
