# combatStart

The combatStart event occurs when combat is about to begin between two actors. This event allows scripts to prevent combat from starting.

```lua
--- @param e combatStartEventData
local function combatStartCallback(e)
end
event.register("combatStart", combatStartCallback)
```

## Event Data

* `target` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who combat is being triggered against.
* `actor` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor who is entering combat.

