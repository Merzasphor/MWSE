--- @meta

--- This event fires when a soul gem target is filtered
--- @class filterSoulGemTargetEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor.
--- @field reference tes3reference *Read-only*. The reference.
--- @field soulGem tes3misc *Read-only*. The soul gem object.
