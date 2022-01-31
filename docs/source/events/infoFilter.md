# infoFilter

This event fires when a dialogue info object is filtered.

```lua
--- @param e infoFilterEventData
local function infoFilterCallback(e)
end
event.register(tes3.event.infoFilter, infoFilterCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `actor` ([tes3object](../../types/tes3object)): *Read-only*. The actor.
* `dialogue` ([tes3dialogue](../../types/tes3dialogue)): *Read-only*. The dialogue object.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The dialogue info object.
* `passes` (boolean): *Read-only*. Indicates if the filter passes.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference.
* `source` (number): *Read-only*. The source.

