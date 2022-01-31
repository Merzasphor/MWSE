# itemTileUpdated

This event is fired whenever an inventory item tile is updated, as well as when the tile is created. This can be used to easily manipulate or extend the appearance of inventory tiles.

```lua
--- @param e itemTileUpdatedEventData
local function itemTileUpdatedCallback(e)
end
event.register(tes3.event.itemTileUpdated, itemTileUpdatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `element` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The UI element that the tile is displayed on.
* `item` ([tes3item](../../types/tes3item)): *Read-only*. The tile's item.
* `itemData` ([tes3itemData](../../types/tes3itemData)): *Read-only*. The tile's item data, if any.
* `menu` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The root menu of the tile. This will typically be the MenuInventory, MenuContents, or MenuBarter menus.
* `tile` ([tes3inventoryTile](../../types/tes3inventoryTile)): *Read-only*. The tile data itself. This typically contains references to all the other event fields, among other tile-specific information.

