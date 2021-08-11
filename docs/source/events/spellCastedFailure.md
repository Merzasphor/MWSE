# spellCastedFailure

This event is triggered when any spell fails to cast due to failing the cast chance check. It does not trigger when there is insufficient magicka.

```lua
--- @type e event.spellCastedFailure
local function spellCastedFailureCallback(e)
end
event.register("spellCastedFailure", spellCastedFailureCallback)
```

This event can be filtered based on the **`source`** event data.

## Event Data

* `target` ([tes3reference](../../types/tes3reference)): The target of the spell. For self-targeted spells, this matches caster.
* `source` ([tes3spell](../../types/tes3spell)): The magic source.
* `expGainSchool` (number): Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast. This school can be altered, or set to nil to remove experience gain, possibly in favour of your own experience calculation.
* `caster` ([tes3reference](../../types/tes3reference)): The caster of the spell.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): The unique instance of the magic source.

