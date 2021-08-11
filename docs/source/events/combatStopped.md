# combatStopped

The combatStopped event occurs after an actor has left combat.

```lua
--- @type e event.combatStopped
local function combatStoppedCallback(e)
end
event.register("combatStopped", combatStoppedCallback)
```

## Event Data

* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who has left combat.

