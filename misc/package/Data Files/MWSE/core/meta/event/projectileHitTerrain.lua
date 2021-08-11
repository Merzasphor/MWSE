--- @meta

--- The projectileHitTerrain event fires when a projectile collides with terrain.
--- @class projectileHitTerrainEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field velocity tes3vector3 The velocity of the mobile projectile.
--- @field position tes3vector3 The position of the mobile projectile.
--- @field collisionPoint tes3vector3 The collision point of the mobile projectile.
--- @field mobile tes3mobileProjectile|tes3mobileSpellProjectile The mobile projectile that is expiring.
--- @field firingReference tes3reference Reference to the actor that fired the projectile.
--- @field firingWeapon tes3weapon The weapon that fired the projectile.
projectileHitTerrain = {}

