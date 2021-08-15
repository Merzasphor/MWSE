--- @meta

--- The **combatStarted** event occurs after combat has began between two actors. This event is preceded by the [combatStart](https://mwse.github.io/MWSE/events/combatStart) event.
--- @class combatStartedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor who has entered combat.
--- @field target tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor who combat has been triggered against.
