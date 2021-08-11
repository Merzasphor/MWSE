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

* `tile` (tes3uiInventoryTile): The dialogue info object.
* `menu` (tesuiElement): The dialogue object.
* `item` ([tes3item](../../types/tes3item)): The reference.
* `element` (tesuiElement): The command.
* `itemData` (tesitemData): The script variables.

