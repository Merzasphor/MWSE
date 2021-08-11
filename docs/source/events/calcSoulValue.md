# calcSoulValue

This event is raised when determining the value of a soul, unmodified by GMSTs. The value can be modified, or used to provide a soul value to NPCs who would normally not be allowed one.

```lua
--- @param e calcSoulValueEventData
local function calcSoulValueCallback(e)
end
event.register("calcSoulValue", calcSoulValueCallback)
```

## Event Data

* `value` (number): The value of the actor's soul.
* `actor` ([tes3creature](../../types/tes3creature), [tes3npc](../../types/tes3npc)): The actor whose soul is being evaluated.

