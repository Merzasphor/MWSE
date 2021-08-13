--- @meta

--- This event fires when a soul gem target is filtered
--- @class filterSoulGemTargetEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer The mobile actor.
--- @field reference tes3reference The reference.
--- @field soulGem tes3misc The soul gem object.
