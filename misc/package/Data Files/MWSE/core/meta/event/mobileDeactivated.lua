--- @meta

--- This event is called when a Mobile Actor is deactivated. Typically this happens when transitioning through cells. When the player enters a cell, the `mobileActivated` event will fire for each new actor. When the player leaves the cell, the `mobileDeactivated` event is called.
--- @class mobileDeactivatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference *Read-only*. The reference that the mobile has been deactivated for.
