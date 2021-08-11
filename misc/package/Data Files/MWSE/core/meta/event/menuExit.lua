--- @meta

--- The menuExit event fires when the player leaves menu mode.
--- @class menuExitEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field menuMode boolean Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.
menuExit = {}

