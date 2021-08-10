# infoGetText

This event fires when a dialogue info object text is retrieved.

```lua
--- @type e event.infoGetText
local function infoGetTextCallback(e)
end
event.register("infoGetText", infoGetTextCallback)
```

## Event Data

* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `loadOriginalText` (method): Loads the original text for the info from the game files, bypassing this event.

