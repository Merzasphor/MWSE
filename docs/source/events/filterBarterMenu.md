# filterBarterMenu

This event fires when an item in the barter menu is filtered.

```lua
--- @type e event.filterBarterMenu
local function filterBarterMenuCallback(e)
end
event.register("filterBarterMenu", filterBarterMenuCallback)
```

## Event Data

* `tile` (tes3uiInventoryTile): The inventory tile being filtered.
* `item` ([tes3item](../../types/tes3item)): The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data for the item being filtered.

