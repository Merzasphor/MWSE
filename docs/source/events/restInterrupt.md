# restInterrupt

This event is invoked when a rest is about to be interrupted. The ambushing spawn can be overridden by changing the creature parameter.

```lua
--- @param e restInterruptEventData
local function restInterruptCallback(e)
end
event.register("restInterrupt", restInterruptCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `creature` ([tes3creature](../../types/tes3creature), [tes3npc](../../types/tes3npc), [tes3leveledCreature](../../types/tes3leveledCreature)): The creature that is interrupting rest. Can be set to a creature, NPC, or leveled creature.
* `resting` (boolean): *Read-only*. If true, the player is attempting to rest, as opposed to wait.
* `waiting` (boolean): *Read-only*. If true, the player is attempting to wait, as opposed to rest.

