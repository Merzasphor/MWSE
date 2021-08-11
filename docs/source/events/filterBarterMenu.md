# filterBarterMenu

This event fires when an item in the barter menu is filtered.

```lua
--- @param e filterBarterMenuEventData
local function filterBarterMenuCallback(e)
end
event.register("filterBarterMenu", filterBarterMenuCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `tile` (tes3uiInventoryTile): The inventory tile being filtered.
* `item` ([tes3item](../../types/tes3item)): The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data for the item being filtered.

