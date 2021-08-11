# potionBrewFailed

The potionBrewFailed event is raised when the player fails a potion brew attempt.

```lua
--- @param e potionBrewFailedEventData
local function potionBrewFailedCallback(e)
end
event.register("potionBrewFailed", potionBrewFailedCallback)
```

## Event Data

* `calcinator` ([tes3apparatus](../../types/tes3apparatus)): The calcinator apparatus used to create the potion.
* `ingredients` (table): An array of up to 4 tes3ingredient objects, which were used to create the potion.
* `alembic` ([tes3apparatus](../../types/tes3apparatus)): The alembic apparatus used to create the potion.
* `retort` ([tes3apparatus](../../types/tes3apparatus)): The retort apparatus used to create the potion.
* `mortar` ([tes3apparatus](../../types/tes3apparatus)): The mortar apparatus used to create the potion.

