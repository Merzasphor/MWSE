--- @meta

--- The menuEnter event fires when the player enters menu mode.
--- @class menuEnterEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field menuMode boolean Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.
--- @field menu tes3uiElement The new top-level menu.
