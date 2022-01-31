# cellDeactivated

This event is triggered when a cell is deactivated.

```lua
--- @param e cellDeactivatedEventData
local function cellDeactivatedCallback(e)
end
event.register(tes3.event.cellDeactivated, cellDeactivatedCallback)
```

!!! tip
	This event can be filtered based on the **`cell`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `cell` ([tes3cell](../../types/tes3cell)): *Read-only*. The cell which was deactivated.

