# combatStop

The combatStop event occurs when an actor is about to leave combat. This event allows scripts to prevent combat from stopping.

```lua
--- @param e combatStopEventData
local function combatStopCallback(e)
end
event.register(tes3.event.combatStop, combatStopCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor who is exiting combat.

