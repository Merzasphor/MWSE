# leveledCreaturePicked

This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

```lua
--- @param e leveledCreaturePickedEventData
local function leveledCreaturePickedCallback(e)
end
event.register("leveledCreaturePicked", leveledCreaturePickedCallback)
```

!!! tip
	This event can be filtered based on the **`list`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `list` ([tes3leveledCreature](../../types/tes3leveledCreature)): *Read-only*. The list responsible for creating a pick.
* `pick` ([tes3creature](../../types/tes3creature)): The result of the pick by vanilla mechanism. This can be modified to change the result to something else.

