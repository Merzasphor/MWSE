--- @meta

--- The enterFrame event occurs at the start of every frame, including when the game is paused or in menu mode.
--- @class enterFrameEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field timestamp number The number of hours since the beginning of the 3rd Era (similar to the Unix Epoch).
--- @field menuMode boolean If the game is paused- in the inventory or a menu, etc.
--- @field delta number The number of seconds since the last frame.
