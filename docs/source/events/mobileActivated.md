# mobileActivated

This event is called when a Mobile Actor is activated. This may be the first time that a given Reference has an associated Mobile Actor attached to it. Typically this happens when transitioning through cells. When the player enters a cell, the `mobileActivated` event will fire for each new actor. When the player leaves the cell, the `mobileDeactivated` event is called.

```lua
--- @param e mobileActivatedEventData
local function mobileActivatedCallback(e)
end
event.register(tes3.event.mobileActivated, mobileActivatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The activated mobile.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference that the mobile has been activated for.

