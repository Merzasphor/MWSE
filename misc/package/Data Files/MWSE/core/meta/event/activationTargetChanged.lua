--- @meta

--- This event is raised when the potential activation target for the player changes.
--- @class activationTargetChangedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field previous tes3reference The previous activation target.
--- @field current tes3reference The activation target for the player, should they press the activation key.
