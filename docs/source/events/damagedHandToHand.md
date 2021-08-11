# damagedHandToHand

The damagedHandToHand event triggers after an actor takes fatigue damage from hand-to-hand combat. It does not trigger on health damage, but the 'damaged' event will.

```lua
--- @param e damagedHandToHandEventData
local function damagedHandToHandCallback(e)
end
event.register("damagedHandToHand", damagedHandToHandCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `fatigueDamage` (number): The amount of fatigue damage done.
* `reference` ([tes3reference](../../types/tes3reference)): The mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that took fatigue damage.
* `attackerReference` ([tes3reference](../../types/tes3reference)): The attacker mobile's associated reference. Can be nil.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor dealing the damage. Can be nil.

