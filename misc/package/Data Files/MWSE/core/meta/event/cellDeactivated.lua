--- @meta

--- This event is triggered when a cell is deactivated.
--- @class cellDeactivatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field cell tes3cell *Read-only*. The cell which was deactivated.
