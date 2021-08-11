# filterSoulGemTarget

This event fires when a soul gem target is filtered

```lua
--- @param e filterSoulGemTargetEventData
local function filterSoulGemTargetCallback(e)
end
event.register("filterSoulGemTarget", filterSoulGemTargetCallback)
```

## Event Data

* `soulGem` ([tes3misc](../../types/tes3misc)): The soul gem object.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.

