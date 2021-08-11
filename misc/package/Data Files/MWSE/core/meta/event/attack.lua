--- @meta

--- This event is invoked whenever an actor makes an attack with their fists or a weapon, or a creature makes any attack. It occurs at the release time of the attack, such as the downstroke of a melee weapon or when an arrow is shot. Lockpicks and probes do not invoke this event.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/attack).
--- @class attackEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference A shortcut to the reference that is attacking.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor making the attack.
--- @field targetMobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor being attacked.
--- @field targetReference tes3reference A shortcut to the reference being attacked.
attack = {}

