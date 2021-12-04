--- @meta

--- The buttonPressed event is unique in that it is invoked only when using `tes3.messageBox` to present buttons to the player.
--- @class buttonPressedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field button number *Read-only*. The button index, 0-based, that was pressed.
