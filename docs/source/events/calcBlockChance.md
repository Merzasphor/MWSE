# calcBlockChance

This event is raised when determining the block chance for an actor. This does not affect ranged or magic attacks and ignores attacks outside of the normal blocking angles, like being attacked from behind. Blocking is disabled in some situations, like being paralyzed or attacking.

```lua
--- @param e calcBlockChanceEventData
local function calcBlockChanceCallback(e)
end
event.register(tes3.event.calcBlockChance, calcBlockChanceCallback)
```

!!! tip
	This event can be filtered based on the **`attacker.baseObject`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attacker` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the attacker mobile's reference.
* `attackerMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile that is attacking.
* `blockChance` (number): The block chance for the actor. This can be adjusted.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the target mobile's reference.
* `targetMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile that is being attacked.

