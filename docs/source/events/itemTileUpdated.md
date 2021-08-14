# itemTileUpdated

This event fires when a dialogue response is triggered.

```lua
--- @param e itemTileUpdatedEventData
local function itemTileUpdatedCallback(e)
end
event.register("itemTileUpdated", itemTileUpdatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `element` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The command.
* `item` ([tes3item](../../types/tes3item)): *Read-only*. The reference.
* `itemData` (tesitemData): *Read-only*. The script variables.
* `menu` ([tes3uiElement](../../types/tes3uiElement)): *Read-only*. The dialogue object.
* `tile` ([tes3inventoryTile](../../types/tes3inventoryTile)): *Read-only*. The dialogue info object.

