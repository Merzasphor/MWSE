--- @meta

--- The mouseWheel event fires when the mouse wheel is used, providing a delta value.
--- @class mouseWheelEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field delta number *Read-only*. The direction and strength of the mouse wheel movement. This value is hardware dependent.
--- @field isAltDown number *Read-only*. True if alt is held.
--- @field isControlDown number *Read-only*. True if control is held.
--- @field isSuperDown number *Read-only*. True if super (Windows key) is held.
