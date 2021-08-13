# filterInventorySelect

This event fires when an inventory filter has been selected for an item.

```lua
--- @param e filterInventorySelectEventData
local function filterInventorySelectCallback(e)
end
event.register("filterInventorySelect", filterInventorySelectCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `item` ([tes3item](../../types/tes3item)): The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data for the item being filtered.
* `type` (string): The inventory filter type.

