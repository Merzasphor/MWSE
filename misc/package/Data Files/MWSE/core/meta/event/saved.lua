--- @meta

--- The saved event fires after the game has successfully been saved. This event is preceded by the save event.
--- @class savedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field name string The user facing name of the save, shown in the load/save game menu.
--- @field filename string The filename of the save, not including file extension.
saved = {}

