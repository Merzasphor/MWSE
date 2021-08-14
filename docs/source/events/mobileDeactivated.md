# mobileDeactivated

This event is called when a Mobile Actor is deactivated. Typically this happens when transitioning through cells. When the player enters a cell, the mobileActivated event will fire for each new actor. When the player leaves the cell, the mobileDeactivated event is called.

```lua
--- @param e mobileDeactivatedEventData
local function mobileDeactivatedCallback(e)
end
event.register("mobileDeactivated", mobileDeactivatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that the mobile has been deactivated for.

