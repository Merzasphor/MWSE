--- @meta

--- The key event fires when a key is released.
--- @class keyUpEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field isAltDown number True if alt  is held.
--- @field isControlDown number True if control is held.
--- @field isSuperDown number True if super (Windows key) is held.
--- @field keyCode number The scan code of the key that raised the event.
