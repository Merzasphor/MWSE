# combatStarted

The combatStarted event occurs after combat has begun between two actors.

```lua
--- @type e event.combatStarted
local function combatStartedCallback(e)
end
event.register("combatStarted", combatStartedCallback)
```

## Event Data

* `target` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who combat has been triggered against.
* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who has entered combat.

