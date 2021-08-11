# itemTileUpdated

This event fires when a dialogue response is triggered.

```lua
--- @type e event.itemTileUpdated
local function itemTileUpdatedCallback(e)
end
event.register("itemTileUpdated", itemTileUpdatedCallback)
```

## Event Data

* `tile` (tes3uiInventoryTile): The dialogue info object.
* `menu` (tesuiElement): The dialogue object.
* `item` ([tes3item](../../types/tes3item)): The reference.
* `element` (tesuiElement): The command.
* `itemData` (tesitemData): The script variables.

