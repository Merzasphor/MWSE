# convertReferenceToItem

This event is raised when an in-world `tes3reference` for an item is about to be converted to fit into a `tes3itemStack`.

```lua
--- @param e convertReferenceToItemEventData
local function convertReferenceToItemCallback(e)
end
event.register(tes3.event.convertReferenceToItem, convertReferenceToItemCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference about to be converted.

