# projectileExpire

The projectileExpire event fires just prior to a fired projectile expiring.

```lua
--- @type e event.projectileExpire
local function projectileExpireCallback(e)
end
event.register("projectileExpire", projectileExpireCallback)
```

## Event Data

* `mobile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): The mobile projectile that is expiring.
* `firingReference` ([tes3reference](../../types/tes3reference)): Reference to the actor that fired the projectile.
* `firingWeapon` ([tes3weapon](../../types/tes3weapon)): The weapon that fired the projectile.

