--- @meta

--- The mouseButtonDown event fires when a button on the mouse is released.
--- @class mouseButtonUpEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field isSuperDown number True if super (Windows key) is held.
--- @field button number The button index that was released.
--- @field isControlDown number True if control is held.
--- @field isAltDown number True if alt  is held.
mouseButtonUp = {}

