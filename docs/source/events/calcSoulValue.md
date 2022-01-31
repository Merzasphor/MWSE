# calcSoulValue

This event is raised when determining the value of a soul, unmodified by GMSTs. The value can be modified, or used to provide a soul value to NPCs who would normally not be allowed one.

```lua
--- @param e calcSoulValueEventData
local function calcSoulValueCallback(e)
end
event.register(tes3.event.calcSoulValue, calcSoulValueCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3creature](../../types/tes3creature), [tes3npc](../../types/tes3npc)): *Read-only*. The actor whose soul is being evaluated.
* `value` (number, nil): The value of the actor's soul. This may be `nil` for NPCs.

