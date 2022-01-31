# leveledCreaturePicked

This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

```lua
--- @param e leveledCreaturePickedEventData
local function leveledCreaturePickedCallback(e)
end
event.register(tes3.event.leveledCreaturePicked, leveledCreaturePickedCallback)
```

!!! tip
	This event can be filtered based on the **`list`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `cell` ([tes3cell](../../types/tes3cell), nil): The cell associated with the pick, if any. This may be the `spawner`'s cell, the temporarily created empty cell, or the cell the player's sleep was interrupted in.
* `list` ([tes3leveledCreature](../../types/tes3leveledCreature)): *Read-only*. The list responsible for creating a pick.
* `pick` ([tes3creature](../../types/tes3creature), nil): The result of the pick by vanilla mechanism. This can be modified to change the result to something else.
* `source` (string): The context that the creature is being spawned in. Valid values include: `"reference"` for when spawned from a placed leveled spawn; `"emptyCell"` for when the player is exploring empty, undefined exterior cells; `"sleepInterrupt"` for when a random creature is chosen to attack the player when resting; and `"script"` for otherwise scripted picking.
* `spawner` ([tes3reference](../../types/tes3reference), nil): If spawned from a placed leveled creature reference, this is a handle to the creating reference.

