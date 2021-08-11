--- @meta

--- The load event fires when the game is about to load. This event allows scripts to block loading.
--- @class loadEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field filename string The filename of the save we want to load, not including file extension. Can be modified to redirect to another save.
--- @field quickload boolean If true, the load came from the quickload system.
--- @field newGame boolean If true, a new game is being started.
