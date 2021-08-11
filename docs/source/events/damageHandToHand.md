# damageHandToHand

The damageHandToHand event triggers before an actor takes fatigue damage from hand-to-hand combat. It does not trigger on health damage, but the 'damage' event will. The fatigueDamage value can be modified, or can be prevented completely by blocking the event. The player as attacker will gain hand-to-hand experience only if fatigueDamage is greater than zero.

```lua
--- @param e damageHandToHandEventData
local function damageHandToHandCallback(e)
end
event.register("damageHandToHand", damageHandToHandCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `fatigueDamage` (number): The amount of fatigue damage done.
* `reference` ([tes3reference](../../types/tes3reference)): The mobile’s associated reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor that is taking fatigue damage.
* `attackerReference` ([tes3reference](../../types/tes3reference)): The attacker mobile's associated reference. Can be nil.
* `attacker` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor dealing the damage. Can be nil.

