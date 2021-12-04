--- @meta

--- This event is invoked whenever an actor starts an attack with their fists or a weapon, or a creature makes any attack. More precisely, it is when the actor raises a melee weapon or draws an arrow. There is not necessarily a target in range, or any target at all for the player.
--- @class attackStartEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field attackSpeed number The speed multiplier of the attack animation, normally equal to the weapon speed (1.0 for no equipped weapon). May be changed to change the current attack's speed. See also [`tes3actorAnimationController`](https://mwse.github.io/MWSE/types/tes3actorAnimationController/) to change animation speed during the attack.
--- @field attackType number A number from the [`tes3.physicalAttackType`](https://mwse.github.io/MWSE/references/physical-attack-types/) enumeration identifying the physical attack type. Can be `tes3.physicalAttackType.slash`, `.chop`, `.thrust`, `.projectile`, `.creature1`, `.creature2`, or `.creature3`. May be changed to change the attack's type if the original attack was slash, chop, or thrust.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor making the attack.
--- @field reference tes3reference *Read-only*. A shortcut to the reference that is attacking.
