# calcSpellmakingSpellPointCost

This event is called when determining the spell point cost of making a spell. The spell point cost can be modified.

```lua
--- @param e calcSpellmakingSpellPointCostEventData
local function calcSpellmakingSpellPointCostCallback(e)
end
event.register(tes3.event.calcSpellmakingSpellPointCost, calcSpellmakingSpellPointCostCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor of the spellmaking service npc the player is interacting with.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile's related reference.
* `spellPointCost` (number): The spell point cost of the spell.

