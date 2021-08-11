--- @meta

--- This event is triggered when a cell is activated.
--- @class cellActivatedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field cell tes3cell The cell which was activated.
cellActivated = {}

