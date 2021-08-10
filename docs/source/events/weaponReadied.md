# weaponReadied

This event is called when a weapon is readied, and pairs with the weaponUnreadied event. It can be used to reliably tell if a specific weapon is readied for attack. This does not necessarily mean that the animation state has changed for the first time.

```lua
--- @type e event.weaponReadied
local function weaponReadiedCallback(e)
end
event.register("weaponReadied", weaponReadiedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference associated with the change in readied weapon.
* `weaponStack` ([tes3baseObject](../../types/tes3baseObject)): The bundle that contains the newly readied weapon and its associated data.

