# referenceDeactivated

This event is triggered when a reference is deactivated.

```lua
--- @param e referenceDeactivatedEventData
local function referenceDeactivatedCallback(e)
end
event.register("referenceDeactivated", referenceDeactivatedCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference which was deactivated.

