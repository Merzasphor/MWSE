--- @meta

--- The damageHandToHand event triggers before an actor takes fatigue damage from hand-to-hand combat. It does not trigger on health damage, but the 'damage' event will. The fatigueDamage value can be modified, or can be prevented completely by blocking the event. The player as attacker will gain hand-to-hand experience only if fatigueDamage is greater than zero.
--- @class damageHandToHandEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field fatigueDamage number The amount of fatigue damage done.
--- @field reference tes3reference The mobile’s associated reference.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor that is taking fatigue damage.
--- @field attackerReference tes3reference The attacker mobile's associated reference. Can be nil.
--- @field attacker tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor dealing the damage. Can be nil.
damageHandToHand = {}

