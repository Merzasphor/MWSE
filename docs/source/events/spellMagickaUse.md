# spellMagickaUse

This event is triggered just before a spell or power is used by any actor. It allows modification of the magicka required to cast the spell. Magicka cost change is not reflected in the UI system, because the UI does not expect spell costs to change.

```lua
--- @param e spellMagickaUseEventData
local function spellMagickaUseCallback(e)
end
event.register(tes3.event.spellMagickaUse, spellMagickaUseCallback)
```

!!! tip
	This event can be filtered based on the **`caster`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the spell.
* `cost` (number): The magicka cost required to cast the spell. May be modified. This value is rounded to an integer when used by the engine.
* `instance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): The magic source instance.
* `spell` ([tes3spell](../../types/tes3spell)): *Read-only*. The spell being cast.

