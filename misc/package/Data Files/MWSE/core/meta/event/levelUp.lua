--- @meta

--- This even is called whenever the player successfully finishes leveling up.
--- @class levelUpEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field level number The new level obtained.
levelUp = {}

