--- @meta

--- This event is triggered on a collision.
--- @class collisionEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference Mobile object's associated reference.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobileProjectile|tes3mobileSpellProjectile Mobile object which collided with its target reference.
--- @field target tes3reference Reference which mobile object has collided with.
collision = {}

