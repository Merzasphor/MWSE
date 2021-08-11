# filterInventory

This event fires when an item in the inventory is filtered.

```lua
--- @type e event.filterInventory
local function filterInventoryCallback(e)
end
event.register("filterInventory", filterInventoryCallback)
```

## Event Data

* `tile` (tes3uiInventoryTile): The inventory tile being filtered.
* `item` ([tes3item](../../types/tes3item)): The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data for the item being filtered.

