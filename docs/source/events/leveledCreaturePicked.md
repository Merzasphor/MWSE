# leveledCreaturePicked

This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.

```lua
--- @type e event.leveledCreaturePicked
local function leveledCreaturePickedCallback(e)
end
event.register("leveledCreaturePicked", leveledCreaturePickedCallback)
```

This event can be filtered based on the **`list`** event data.

## Event Data

* `list` ([tes3leveledCreature](../../types/tes3leveledCreature)): The list responsible for creating a pick.
* `pick` ([tes3creature](../../types/tes3creature)): The result of the pick by vanilla mechanism. This can be modified to change the result to something else.

