# filterInventory

This event fires when an item in the inventory is filtered.

```lua
--- @param e filterInventoryEventData
local function filterInventoryCallback(e)
end
event.register("filterInventory", filterInventoryCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `item` ([tes3item](../../types/tes3item)): *Read-only*. The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The item data for the item being filtered.
* `tile` ([tes3inventoryTile](../../types/tes3inventoryTile)): *Read-only*. The inventory tile being filtered.

