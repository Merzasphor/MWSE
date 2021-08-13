--- @meta

--- One of the movement events, calcRunSpeed is used when calculating when the player is running, but not swimming or flying.
--- @class calcRunSpeedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor whose speed is being calculated.
--- @field reference tes3reference mobile’s related reference.
--- @field speed number The previous speed calculated, starting with the base engine values.
--- @field type number The type of movement that was calculated. This is always 2 for this event.
