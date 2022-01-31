# determinedAction

This event fires when an actor has determined an action in a combat session.

```lua
--- @param e determinedActionEventData
local function determinedActionCallback(e)
end
event.register(tes3.event.determinedAction, determinedActionCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `session` ([tes3combatSession](../../types/tes3combatSession)): *Read-only*. The combat session the action has been determined for.

