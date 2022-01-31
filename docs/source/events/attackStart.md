# attackStart

This event is invoked whenever an actor starts an attack with their fists or a weapon, or a creature makes any attack. More precisely, it is when the actor raises a melee weapon or draws an arrow. There is not necessarily a target in range, or any target at all for the player.

```lua
--- @param e attackStartEventData
local function attackStartCallback(e)
end
event.register(tes3.event.attackStart, attackStartCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `attackSpeed` (number): The speed multiplier of the attack animation, normally equal to the weapon speed (1.0 for no equipped weapon). May be changed to change the current attack's speed. See also [`tes3actorAnimationController`](https://mwse.github.io/MWSE/types/tes3actorAnimationController/) to change animation speed during the attack.
* `attackType` (number): A number from the [`tes3.physicalAttackType`](https://mwse.github.io/MWSE/references/physical-attack-types/) enumeration identifying the physical attack type. Can be `tes3.physicalAttackType.slash`, `.chop`, `.thrust`, `.projectile`, `.creature1`, `.creature2`, or `.creature3`. May be changed to change the attack's type if the original attack was slash, chop, or thrust.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor making the attack.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. A shortcut to the reference that is attacking.

