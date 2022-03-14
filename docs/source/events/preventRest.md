# preventRest

This event can be used to prevent the player from resting by returning false.

```lua
--- @param e preventRestEventData
local function preventRestCallback(e)
end
event.register(tes3.event.preventRest, preventRestCallback)
```

!!! tip
	This event can be filtered based on the **`mobile`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is preventing the player from resting.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile's associated reference.

