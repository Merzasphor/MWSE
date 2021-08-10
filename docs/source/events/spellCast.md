# spellCast

This event is triggered just before a spell cast is resolved, at the end of the casting animation. It can control the success chance of the spell cast.

```lua
--- @type e event.spellCast
local function spellCastCallback(e)
end
event.register("spellCast", spellCastCallback)
```

This event can be filtered based on the **`source`** event data.

## Event Data

* `source` ([tes3spell](../../types/tes3spell)): The magic source.
* `weakestSchool` (number): Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast.
* `caster` ([tes3reference](../../types/tes3reference)): The caster of the spell.
* `castChance` (number): The percentage chance of the caster successfully casting the spell. May be modified. Setting it to 0 will cause the cast to fail.

