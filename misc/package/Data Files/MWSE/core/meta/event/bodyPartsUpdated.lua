--- @meta

--- This event is triggered when an actor's body parts have finished updating. This typically triggers when an actor is first rendered, or when their equipment changes.
--- @class bodyPartsUpdatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor whose body parts were updated.
--- @field reference tes3reference *Read-only*. The reference for the actor whose body parts were updated.
