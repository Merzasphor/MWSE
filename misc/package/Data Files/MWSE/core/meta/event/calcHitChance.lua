--- @meta

--- This event is raised when determining the hit chance for an actor.
--- @class calcHitChanceEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field attackerMobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile who is making the attack.
--- @field target tes3reference A shortcut to the target mobile's reference. May not always be available.
--- @field hitChance number The hit chance for the actor. This may be adjusted.
--- @field targetMobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile who is being attacked. May not always be available.
--- @field attacker tes3reference A shortcut to the mobile's reference.
calcHitChance = {}

