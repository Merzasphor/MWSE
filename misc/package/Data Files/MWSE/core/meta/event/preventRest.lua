--- @meta

--- This event can be used to prevent player from resting by returning false.
--- @class preventRestEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. Mobile actor which is preventing the player from resting
--- @field reference tes3reference *Read-only*. Mobile’s associated reference.
