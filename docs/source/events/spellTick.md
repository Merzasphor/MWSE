# spellTick

The spellTick event happens every frame that an effect is active on a target. This can be used to aid in scripted spells, cancel active spells, or otherwise monitor spell activity on actors.

```lua
--- @param e spellTickEventData
local function spellTickCallback(e)
end
event.register("spellTick", spellTickCallback)
```

This event can be filtered based on the **`source`** event data.

## Event Data

* `deltaTime` (number): The number of seconds since the last spell tick.
* `caster` ([tes3reference](../../types/tes3reference)): The caster of the spell.
* `effectIndex` (number): The index of the effect in source’s effects list.
* `target` ([tes3reference](../../types/tes3reference)): The target of the spell. For self-targeted spells, this matches caster.
* `effectInstance` ([tes3magicEffectInstance](../../types/tes3magicEffectInstance)): The unique instance of the magic effect.
* `effectId` (number): The magic effect ID that is being ticked.
* `source` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): The magic source.
* `effect` ([tes3magicEffect](../../types/tes3magicEffect)): The individual effect structure on source.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): The unique instance of the magic source.

