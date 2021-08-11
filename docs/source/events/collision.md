# collision

This event is triggered on a collision.

```lua
--- @param e collisionEventData
local function collisionCallback(e)
end
event.register("collision", collisionCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): Mobile object's associated reference.
* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): Mobile object which collided with its target reference.
* `target` ([tes3reference](../../types/tes3reference)): Reference which mobile object has collided with.

