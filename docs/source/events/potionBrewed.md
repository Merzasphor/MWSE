# potionBrewed

The potionBrewed event is raised when the player brews a new potion.

```lua
--- @type e event.potionBrewed
local function potionBrewedCallback(e)
end
event.register("potionBrewed", potionBrewedCallback)
```

## Event Data

* `object` ([tes3alchemy](../../types/tes3alchemy)): The potion created by the player.
* `ingredients` (table): An array of up to 4 tes3ingredient objects, which were used to create the potion.
* `alembic` ([tes3apparatus](../../types/tes3apparatus)): The alembic apparatus used to create the potion.
* `retort` ([tes3apparatus](../../types/tes3apparatus)): The retort apparatus used to create the potion.
* `mortar` ([tes3apparatus](../../types/tes3apparatus)): The mortar apparatus used to create the potion.
* `calcinator` ([tes3apparatus](../../types/tes3apparatus)): The calcinator apparatus used to create the potion.

