# infoFilter

This event fires when a dialogue info object is filtered.

```lua
--- @param e infoFilterEventData
local function infoFilterCallback(e)
end
event.register("infoFilter", infoFilterCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `source` (number): The source.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): The dialogue object.
* `reference` ([tes3reference](../../types/tes3reference)): The reference.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): The dialogue info object.
* `passes` (boolean): Indicates if the filter passes.
* `actor` ([tes3object](../../types/tes3object)): The actor.

