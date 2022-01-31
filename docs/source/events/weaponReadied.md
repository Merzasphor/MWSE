# weaponReadied

This event is called when a weapon is readied, and pairs with the weaponUnreadied event. It can be used to reliably tell if a specific weapon is readied for attack. This does not necessarily mean that the animation state has changed for the first time.

```lua
--- @param e weaponReadiedEventData
local function weaponReadiedCallback(e)
end
event.register(tes3.event.weaponReadied, weaponReadiedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference associated with the change in readied weapon.
* `weaponStack` ([tes3baseObject](../../types/tes3baseObject)): *Read-only*. The bundle that contains the newly readied weapon and its associated data.

