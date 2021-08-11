--- @meta

--- This event fires when a dialogue info object text is retrieved.
--- @class infoGetTextEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field info tes3dialogueInfo The dialogue info object.
--- @field loadOriginalText method Loads the original text for the info from the game files, bypassing this event.
infoGetText = {}

