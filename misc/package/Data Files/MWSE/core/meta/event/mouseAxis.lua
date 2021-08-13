--- @meta

--- The mouseAxis event fires when the mouse is moved, providing deltaX and deltaY values.
--- @class mouseAxisEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field deltaX number The difference in horizontal mouse position from the previous frame.
--- @field deltaY number The difference in vertical mouse position from the previous frame.
--- @field isAltDown number True if alt  is held.
--- @field isControlDown number True if control is held.
--- @field isSuperDown number True if super (Windows key) is held.
