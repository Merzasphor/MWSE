# infoGetText

This event fires when a dialogue info object text is retrieved.

```lua
--- @param e infoGetTextEventData
local function infoGetTextCallback(e)
end
event.register("infoGetText", infoGetTextCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The dialogue info object.
* `loadOriginalText` (method): Loads the original text for the info from the game files, bypassing this event.

