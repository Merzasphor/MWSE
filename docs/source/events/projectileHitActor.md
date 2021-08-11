# projectileHitActor

The projectileHitActor event fires when a projectile collides with an actor.

```lua
--- @param e projectileHitActorEventData
local function projectileHitActorCallback(e)
end
event.register("projectileHitActor", projectileHitActorCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `firingWeapon` ([tes3weapon](../../types/tes3weapon)): The weapon that fired the projectile.
* `target` ([tes3reference](../../types/tes3reference)): Reference to the actor that was hit.
* `firingReference` ([tes3reference](../../types/tes3reference)): Reference to the actor that fired the projectile.
* `mobile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): The mobile projectile that is expiring.

