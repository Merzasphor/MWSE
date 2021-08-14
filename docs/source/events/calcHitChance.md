# calcHitChance

This event is raised when determining the hit chance for an actor.

```lua
--- @param e calcHitChanceEventData
local function calcHitChanceCallback(e)
end
event.register("calcHitChance", calcHitChanceCallback)
```

!!! tip
	This event can be filtered based on the **`attacker.baseObject`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attacker` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the mobile's reference.
* `attackerMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile who is making the attack.
* `hitChance` (number): The hit chance for the actor. This may be adjusted.
* `target` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the target mobile's reference. May not always be available.
* `targetMobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile who is being attacked. May not always be available.

