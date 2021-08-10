# leveledItemPicked

This event is called after any leveled item list is resolved.

```lua
--- @type e event.leveledItemPicked
local function leveledItemPickedCallback(e)
end
event.register("leveledItemPicked", leveledItemPickedCallback)
```

This event can be filtered based on the **`list`** event data.

## Event Data

* `list` ([tes3leveledItem](../../types/tes3leveledItem)): The list responsible for creating a pick.
* `pick` ([tes3item](../../types/tes3item)): The result of the pick by vanilla mechanism.

