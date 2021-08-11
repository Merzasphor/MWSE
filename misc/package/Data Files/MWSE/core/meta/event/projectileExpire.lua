--- @meta

--- The projectileExpire event fires just prior to a fired projectile expiring.
--- @class projectileExpireEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileProjectile|tes3mobileSpellProjectile The mobile projectile that is expiring.
--- @field firingReference tes3reference Reference to the actor that fired the projectile.
--- @field firingWeapon tes3weapon The weapon that fired the projectile.
projectileExpire = {}

