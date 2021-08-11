# determinedAction

This event fires when an actor has determined an action in a combat session.

```lua
--- @param e determinedActionEventData
local function determinedActionCallback(e)
end
event.register("determinedAction", determinedActionCallback)
```

## Event Data

* `session` ([tes3combatSession](../../types/tes3combatSession)): The combat session the action has been determined for.

