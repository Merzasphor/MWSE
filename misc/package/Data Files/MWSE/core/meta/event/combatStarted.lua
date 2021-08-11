--- @meta

--- The combatStarted event occurs after combat has begun between two actors.
--- @class combatStartedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field target tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor who combat has been triggered against.
--- @field actor tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor who has entered combat.
