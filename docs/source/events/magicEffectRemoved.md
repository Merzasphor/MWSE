# magicEffectRemoved

This event triggers when a magic effect has been removed from an actor. This includes magic effects that have been resisted.

```lua
--- @param e magicEffectRemovedEventData
local function magicEffectRemovedCallback(e)
end
event.register(tes3.event.magicEffectRemoved, magicEffectRemovedCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `caster` ([tes3reference](../../types/tes3reference)): *Read-only*. The caster of the magic source that contained the magic effect. Can be `nil`.
* `effect` ([tes3effect](../../types/tes3effect)): *Read-only*. The specific magic effect that triggered the event. This is equal to `e.source.effects[effectIndex]`. Can be `nil`.
* `effectIndex` (number): *Read-only*. The index of the magic effect in the magic source's effects list.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor the magic effect is removed from.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference of the mobile actor the magic effect is removed from.
* `source` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): *Read-only*. The magic source that contains the effect.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): *Read-only*. The unique instance of the magic source that contains the effect.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. The target of the magic source that contained the magic effect. Can be `nil`.

