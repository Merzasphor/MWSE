# jump

This event is called when an actor tries to jump. The velocity can be modified.

```lua
--- @param e jumpEventData
local function jumpCallback(e)
end
event.register(tes3.event.jump, jumpCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor that is trying to jump.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Mobile's related reference.
* `velocity` ([tes3vector3](../../types/tes3vector3)): The velocity of the jump.

