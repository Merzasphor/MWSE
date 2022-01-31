# damagedHandToHand

The damagedHandToHand event triggers after an actor takes fatigue damage from hand-to-hand combat. It does not trigger on health damage, but the `damaged` event will.

```lua
--- @param e damagedHandToHandEventData
local function damagedHandToHandCallback(e)
end
event.register(tes3.event.damagedHandToHand, damagedHandToHandCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor dealing the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): *Read-only*. The attacker mobile's associated reference. Can be nil.
* `fatigueDamage` (number): *Read-only*. The amount of fatigue damage done.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that took fatigue damage.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The mobile’s associated reference.

