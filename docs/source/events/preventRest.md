# preventRest

This event can be used to prevent player from resting by returning false.

```lua
--- @type e event.preventRest
local function preventRestCallback(e)
end
event.register("preventRest", preventRestCallback)
```

This event can be filtered based on the **`mobile`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): Mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): Mobile actor which is preventing the player from resting

