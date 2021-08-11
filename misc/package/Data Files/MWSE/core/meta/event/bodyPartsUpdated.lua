--- @meta

--- This event is triggered when an actor's body parts have finished updating. This typically triggers when an actor is first rendered, or when their equipment changes.
--- @class bodyPartsUpdatedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference for the actor whose body parts were updated.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor whose body parts were updated.
bodyPartsUpdated = {}

