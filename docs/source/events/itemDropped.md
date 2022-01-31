# itemDropped

This event fires when an item is dropped.

```lua
--- @param e itemDroppedEventData
local function itemDroppedCallback(e)
end
event.register(tes3.event.itemDropped, itemDroppedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference.

