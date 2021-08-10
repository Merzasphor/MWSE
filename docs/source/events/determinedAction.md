# determinedAction

This event fires when an actor has determined an action in a combat session.

```lua
--- @type e event.determinedAction
local function determinedActionCallback(e)
end
event.register("determinedAction", determinedActionCallback)
```

## Event Data

* `session` ([tes3combatSession](../../types/tes3combatSession)): The combat session the action has been determined for.

