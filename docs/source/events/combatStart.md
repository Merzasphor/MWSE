# combatStart

The combatStart event occurs when combat is about to begin between two actors. This event allows scripts to prevent combat from starting.

```lua
--- @param e combatStartEventData
local function combatStartCallback(e)
end
event.register(tes3.event.combatStart, combatStartCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor who is entering combat.
* `target` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor who combat is being triggered against.

