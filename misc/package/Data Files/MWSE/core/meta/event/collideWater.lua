--- @meta

--- This event is triggered when a mobile object collides with water.
--- @class collideWaterEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobileProjectile|tes3mobileSpellProjectile `mobile`'s reference.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer|tes3mobileProjectile|tes3mobileSpellProjectile Mobile object which collided.
--- @field inWater boolean 
collideWater = {}

