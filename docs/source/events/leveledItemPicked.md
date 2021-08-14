# leveledItemPicked

This event is called after any leveled item list is resolved.

```lua
--- @param e leveledItemPickedEventData
local function leveledItemPickedCallback(e)
end
event.register("leveledItemPicked", leveledItemPickedCallback)
```

!!! tip
	This event can be filtered based on the **`list`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `list` ([tes3leveledItem](../../types/tes3leveledItem)): *Read-only*. The list responsible for creating a pick.
* `pick` ([tes3item](../../types/tes3item)): The result of the pick by vanilla mechanism.

