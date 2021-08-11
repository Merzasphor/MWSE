--- @meta

--- The projectileHitActor event fires when a projectile collides with an actor.
--- @class projectileHitActorEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field firingWeapon tes3weapon The weapon that fired the projectile.
--- @field target tes3reference Reference to the actor that was hit.
--- @field firingReference tes3reference Reference to the actor that fired the projectile.
--- @field mobile tes3mobileProjectile|tes3mobileSpellProjectile The mobile projectile that is expiring.
projectileHitActor = {}

