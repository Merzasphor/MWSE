# death

This event triggers when an actor dies.

```lua
--- @param e deathEventData
local function deathCallback(e)
end
event.register("death", deathCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that has died.

