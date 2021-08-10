# projectileHitTerrain

The projectileHitTerrain event fires when a projectile collides with terrain.

```lua
--- @type e event.projectileHitTerrain
local function projectileHitTerrainCallback(e)
end
event.register("projectileHitTerrain", projectileHitTerrainCallback)
```

## Event Data

* `velocity` ([tes3vector3](../../types/tes3vector3)): The velocity of the mobile projectile.
* `position` ([tes3vector3](../../types/tes3vector3)): The position of the mobile projectile.
* `collisionPoint` ([tes3vector3](../../types/tes3vector3)): The collision point of the mobile projectile.
* `mobile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): The mobile projectile that is expiring.
* `firingReference` ([tes3reference](../../types/tes3reference)): Reference to the actor that fired the projectile.
* `firingWeapon` ([tes3weapon](../../types/tes3weapon)): The weapon that fired the projectile.

