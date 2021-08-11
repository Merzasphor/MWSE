# calcHitChance

This event is raised when determining the hit chance for an actor.

```lua
--- @param e calcHitChanceEventData
local function calcHitChanceCallback(e)
end
event.register("calcHitChance", calcHitChanceCallback)
```

This event can be filtered based on the **`attacker.baseObject`** event data.

## Event Data

* `attackerMobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile who is making the attack.
* `target` ([tes3reference](../../types/tes3reference)): A shortcut to the target mobile's reference. May not always be available.
* `hitChance` (number): The hit chance for the actor. This may be adjusted.
* `targetMobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile who is being attacked. May not always be available.
* `attacker` ([tes3reference](../../types/tes3reference)): A shortcut to the mobile's reference.

