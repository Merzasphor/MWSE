--- @meta

--- One of the movement events, calcWalkSpeed is used when calculating the base walk speed.
--- @class calcWalkSpeedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor whose speed is being calculated.
--- @field reference tes3reference *Read-only*. mobile’s related reference.
--- @field speed number The previous speed calculated, starting with the base engine values.
--- @field type number *Read-only*. The type of movement that was calculated. This is always 1 for this event.
