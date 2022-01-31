# referenceActivated

This event is triggered when a reference is activated.

```lua
--- @param e referenceActivatedEventData
local function referenceActivatedCallback(e)
end
event.register(tes3.event.referenceActivated, referenceActivatedCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference which was activated.

