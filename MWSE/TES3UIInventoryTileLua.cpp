#include "TES3UIInventoryTileLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ItemData.h"
#include "TES3UIElement.h"
#include "TES3UIInventoryTile.h"

#include "TES3Item.h"

namespace mwse {
	namespace lua {
		void bindTES3UIInventoryTile() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::UI::InventoryTile>("tes3inventoryTile");
			usertypeDefinition["new"] = sol::no_constructor;

			// Functions exposed as properties.
			usertypeDefinition["count"] = sol::readonly_property(&TES3::UI::InventoryTile::count);
			usertypeDefinition["element"] = sol::readonly_property(&TES3::UI::InventoryTile::element);
			usertypeDefinition["flags"] = sol::readonly_property(&TES3::UI::InventoryTile::flags);
			usertypeDefinition["isBoundItem"] = sol::readonly_property(&TES3::UI::InventoryTile::isBoundItem);
			usertypeDefinition["itemData"] = sol::readonly_property(&TES3::UI::InventoryTile::itemData);
			usertypeDefinition["type"] = sol::readonly_property(&TES3::UI::InventoryTile::tileType);

			// Access to other objects that need to be packaged.
			usertypeDefinition["item"] = sol::readonly_property([](TES3::UI::InventoryTile& self) { return self.item; });

			// Access into flags.
			usertypeDefinition["isBartered"] = sol::readonly_property([](TES3::UI::InventoryTile& self) { return self.getFlag(TES3::UI::InventoryTileFlag::Bartered); });
			usertypeDefinition["isEquipped"] = sol::readonly_property([](TES3::UI::InventoryTile& self) { return self.getFlag(TES3::UI::InventoryTileFlag::Equipped); });
		}
	}
}
