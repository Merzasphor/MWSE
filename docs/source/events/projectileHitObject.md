# projectileHitObject

The projectileHitObject event fires when a projectile collides with an object.

```lua
--- @param e projectileHitObjectEventData
local function projectileHitObjectCallback(e)
end
event.register(tes3.event.projectileHitObject, projectileHitObjectCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `collisionPoint` ([tes3vector3](../../types/tes3vector3)): *Read-only*. The collision point of the mobile projectile.
* `firingReference` ([tes3reference](../../types/tes3reference)): *Read-only*. Reference to the actor that fired the projectile.
* `firingWeapon` ([tes3weapon](../../types/tes3weapon)): *Read-only*. The weapon that fired the projectile.
* `mobile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): *Read-only*. The mobile projectile that is expiring.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. Reference to the object that was hit.

