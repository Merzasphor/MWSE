# filterSoulGemTarget

This event fires when a soul gem target is filtered

```lua
--- @param e filterSoulGemTargetEventData
local function filterSoulGemTargetCallback(e)
end
event.register("filterSoulGemTarget", filterSoulGemTargetCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference.
* `soulGem` ([tes3misc](../../types/tes3misc)): *Read-only*. The soul gem object.

