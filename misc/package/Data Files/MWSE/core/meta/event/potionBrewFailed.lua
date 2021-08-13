--- @meta

--- The potionBrewFailed event is raised when the player fails a potion brew attempt.
--- @class potionBrewFailedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field alembic tes3apparatus The alembic apparatus used to create the potion.
--- @field calcinator tes3apparatus The calcinator apparatus used to create the potion.
--- @field ingredients table An array of up to 4 tes3ingredient objects, which were used to create the potion.
--- @field mortar tes3apparatus The mortar apparatus used to create the potion.
--- @field retort tes3apparatus The retort apparatus used to create the potion.
