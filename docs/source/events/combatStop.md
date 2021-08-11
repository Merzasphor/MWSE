# combatStop

The combatStop event occurs when an actor is about to leave combat. This event allows scripts to prevent combat from stopping.

```lua
--- @param e combatStopEventData
local function combatStopCallback(e)
end
event.register("combatStop", combatStopCallback)
```

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who is exiting combat.

