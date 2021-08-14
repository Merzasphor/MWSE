--- @meta

--- This event is triggered just before the player levels up.
--- @class preLevelUpEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field level number *Read-only*. The new level about to be obtained.
