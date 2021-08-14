# potionBrewFailed

The potionBrewFailed event is raised when the player fails a potion brew attempt.

```lua
--- @param e potionBrewFailedEventData
local function potionBrewFailedCallback(e)
end
event.register("potionBrewFailed", potionBrewFailedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `alembic` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The alembic apparatus used to create the potion.
* `calcinator` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The calcinator apparatus used to create the potion.
* `ingredients` (table): *Read-only*. An array of up to 4 tes3ingredient objects, which were used to create the potion.
* `mortar` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The mortar apparatus used to create the potion.
* `retort` ([tes3apparatus](../../types/tes3apparatus)): *Read-only*. The retort apparatus used to create the potion.

