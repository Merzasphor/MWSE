# damageHandToHand

The damageHandToHand event triggers before an actor takes fatigue damage from hand-to-hand combat. It does not trigger on health damage, but the `damage` event will. The `fatigueDamage` value can be modified, or can be prevented completely by blocking the event. The player as attacker will gain hand-to-hand experience only if `fatigueDamage` is greater than zero.

```lua
--- @param e damageHandToHandEventData
local function damageHandToHandCallback(e)
end
event.register(tes3.event.damageHandToHand, damageHandToHandCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor dealing the damage. Can be nil.
* `attackerReference` ([tes3reference](../../types/tes3reference)): *Read-only*. The attacker mobile's associated reference. Can be nil.
* `fatigueDamage` (number): The amount of fatigue damage done.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is taking fatigue damage.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The mobile’s associated reference.

