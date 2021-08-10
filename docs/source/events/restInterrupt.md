# restInterrupt

This event is invoked when a rest is about to be interrupted. The ambushing spawn can be overridden by changing the creature parameter.

```lua
--- @type e event.restInterrupt
local function restInterruptCallback(e)
end
event.register("restInterrupt", restInterruptCallback)
```

## Event Data

* `creature` ([tes3creature](../../types/tes3creature), [tes3npc](../../types/tes3npc), [tes3leveledCreature](../../types/tes3leveledCreature)): The creature that is interrupting rest. Can be set to a creature, NPC, or leveled creature.
* `resting` (boolean): If true, the player is attempting to rest, as opposed to wait.
* `waiting` (boolean): If true, the player is attempting to wait, as opposed to rest.

