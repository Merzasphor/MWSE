# projectileExpire

The projectileExpire event fires just prior to a fired projectile expiring.

```lua
--- @param e projectileExpireEventData
local function projectileExpireCallback(e)
end
event.register(tes3.event.projectileExpire, projectileExpireCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `firingReference` ([tes3reference](../../types/tes3reference)): *Read-only*. Reference to the actor that fired the projectile.
* `firingWeapon` ([tes3weapon](../../types/tes3weapon)): *Read-only*. The weapon that fired the projectile.
* `mobile` ([tes3mobileProjectile](../../types/tes3mobileProjectile)): *Read-only*. The mobile projectile that is expiring.

