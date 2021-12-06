--- @meta

--- This event is called when a Mobile Actor is activated. This may be the first time that a given Reference has an associated Mobile Actor attached to it. Typically this happens when transitioning through cells. When the player enters a cell, the `mobileActivated` event will fire for each new actor. When the player leaves the cell, the `mobileDeactivated` event is called.
--- @class mobileActivatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The activated mobile.
--- @field reference tes3reference *Read-only*. The reference that the mobile has been activated for.
