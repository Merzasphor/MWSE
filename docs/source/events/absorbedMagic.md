# absorbedMagic

This event is triggered after magic absorption absorbs and cancels a magic effect, and just before magic absorption gives magicka to the target. It can control the amount of magicka restored.

This event occurs once per effect restored, so a multi-effect spell may trigger this multiple times. The default amount restored is equal to the casting cost of the entire spell, which is the vanilla behaviour.

```lua
--- @param e absorbedMagicEventData
local function absorbedMagicCallback(e)
end
event.register("absorbedMagic", absorbedMagicCallback)
```

This event can be filtered based on the **`target`** event data.

## Event Data

* `target` ([tes3reference](../../types/tes3reference)): The actor that absorbed the spell.
* `source` ([tes3alchemy](../../types/tes3alchemy), [tes3enchantment](../../types/tes3enchantment), [tes3spell](../../types/tes3spell)): The magic source.
* `absorb` (number): The amount of magicka to restore to the actor.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that absorbed the spell.
* `sourceInstance` ([tes3magicSourceInstance](../../types/tes3magicSourceInstance)): The unique instance of the magic source.

