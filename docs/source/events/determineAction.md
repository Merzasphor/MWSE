# determineAction

This event fires when an actor determines an action in a combat session.

```lua
--- @param e determineActionEventData
local function determineActionCallback(e)
end
event.register(tes3.event.determineAction, determineActionCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `session` ([tes3combatSession](../../types/tes3combatSession)): *Read-only*. The combat session the action is being determined for.

