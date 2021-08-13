--- @meta

--- One of the movement events, calcSwimSpeed is used when calculating the movement speed while in water.
--- @class calcSwimSpeedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor whose speed is being calculated.
--- @field reference tes3reference mobile’s related reference.
--- @field speed number The previous speed calculated, starting with the base engine values.
--- @field type number The type of movement that was calculated. This is always 3 for this event.
