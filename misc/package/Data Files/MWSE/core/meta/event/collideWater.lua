--- @meta

--- This event is triggered when a mobile object collides with water.
--- @class collideWaterEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field inWater boolean *Read-only*. 
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobileProjectile|tes3mobileSpellProjectile *Read-only*. Mobile object which collided.
--- @field reference tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobileProjectile|tes3mobileSpellProjectile *Read-only*. `mobile`'s reference.
