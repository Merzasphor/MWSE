# spellTick

The spellTick event happens every frame that an effect is active on a target. This can be used to aid in scripted spells, cancel active spells, or otherwise monitor spell activity on actors.

```lua
--- @param e spellTickEventData
local function spellTickCallback(e)
end
event.register(tes3.event.spellTick, spellTickCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the spell.
* `deltaTime` (number): *Read-only*. The number of seconds since the last spell tick.
* `effect` ([tes3magicEffect](../../types/tes3magicEffect)): *Read-only*. The individual effect structure on source.
* `effectId` (number): *Read-only*. The magic effect ID that is being ticked.
* `effectIndex` (number): *Read-only*. The index of the effect in source’s effects list.
* `effectInstance` ([tes3magicEffectInstance](../../types/tes3magicEffectInstance)): *Read-only*. The unique instance of the magic effect.
* `source` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): *Read-only*. The magic source.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): *Read-only*. The unique instance of the magic source.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. The target of the spell. For self-targeted spells, this matches caster.

