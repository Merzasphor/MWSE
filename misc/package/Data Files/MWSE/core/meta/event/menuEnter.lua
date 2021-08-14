--- @meta

--- The menuEnter event fires when the player enters menu mode.
--- @class menuEnterEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field menu tes3uiElement *Read-only*. The new top-level menu.
--- @field menuMode boolean *Read-only*. Always true for this event. This parameter is only useful when registering the same callback for menuEnter and menuExit events.
