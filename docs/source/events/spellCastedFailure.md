# spellCastedFailure

This event is triggered when any spell fails to cast due to failing the cast chance check. It does not trigger when there is insufficient magicka.

```lua
--- @param e spellCastedFailureEventData
local function spellCastedFailureCallback(e)
end
event.register(tes3.event.spellCastedFailure, spellCastedFailureCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the spell.
* `expGainSchool` (number): Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast. This school can be altered, or set to nil to remove experience gain, possibly in favour of your own experience calculation.
* `source` ([tes3spell](../../types/tes3spell)): *Read-only*. The magic source.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): *Read-only*. The unique instance of the magic source.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. The target of the spell. For self-targeted spells, this matches caster.

