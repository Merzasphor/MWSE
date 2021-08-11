--- @meta

--- The potionBrewed event is raised when the player brews a new potion.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/potionBrewed).
--- @class potionBrewedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field object tes3alchemy The potion created by the player.
--- @field ingredients table An array of up to 4 tes3ingredient objects, which were used to create the potion.
--- @field alembic tes3apparatus The alembic apparatus used to create the potion.
--- @field retort tes3apparatus The retort apparatus used to create the potion.
--- @field mortar tes3apparatus The mortar apparatus used to create the potion.
--- @field calcinator tes3apparatus The calcinator apparatus used to create the potion.
potionBrewed = {}

