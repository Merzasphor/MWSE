# spellResist

This event is used when calculating a creature's spell resistance, and allows Lua scripts to override the behavior of spell resistance by changing the resistedPercent value. This can be used to enable willpower-based resistance checks, provide specific resistances to specific spells, spells that heal instead of harm, and a variety of new mechanics.

```lua
--- @param e spellResistEventData
local function spellResistCallback(e)
end
event.register("spellResist", spellResistCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `effectInstance` ([tes3magicEffectInstance](../../types/tes3magicEffectInstance)): The unique instance of the magic effect.
* `target` ([tes3reference](../../types/tes3reference)): The target of the spell. For self-targeted spells, this matches caster.
* `caster` ([tes3reference](../../types/tes3reference)): The caster of the spell.
* `effectIndex` (number): The index of the effect in source's effects list.
* `source` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): The magic source.
* `resistedPercent` (number): The percent of the spell that has been resisted. This can be modified, but a value outside the range of 0 to 100 does not have consistent effects. For fire damage, for example, a value over 100 causes the spell to heal the target instead of harming them.
* `resistAttribute` (number): The attribute resisted. This is an index into a tes3mobileActor.effectAttributes. Note that the index here is 0-based, while Lua is 1-based.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): The unique instance of the magic source.

