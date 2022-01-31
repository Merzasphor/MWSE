# spellCast

This event is triggered just before a spell cast is resolved, at the end of the casting animation. It can control the success chance of the spell cast.

```lua
--- @param e spellCastEventData
local function spellCastCallback(e)
end
event.register(tes3.event.spellCast, spellCastCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `castChance` (number): The percentage chance of the caster successfully casting the spell. May be modified. Setting it to 0 will cause the cast to fail.
* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the spell.
* `source` ([tes3spell](../../types/tes3spell)): *Read-only*. The magic source.
* `weakestSchool` (number): *Read-only*. Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast.

