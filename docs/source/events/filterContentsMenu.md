# filterContentsMenu

This event fires when an item in the contents menu is filtered.

```lua
--- @param e filterContentsMenuEventData
local function filterContentsMenuCallback(e)
end
event.register("filterContentsMenu", filterContentsMenuCallback)
```

## Event Data

* `tile` (tes3uiInventoryTile): The inventory tile being filtered.
* `item` ([tes3item](../../types/tes3item)): The item being filtered.
* `itemData` ([tes3itemData](../../types/tes3itemData)): The item data for the item being filtered.

