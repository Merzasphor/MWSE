--- @meta

--- This even is called whenever the player successfully finishes leveling up.
--- @class levelUpEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field level number *Read-only*. The new level obtained.
