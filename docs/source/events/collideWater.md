# collideWater

This event is triggered when a mobile object collides with water and all the frames during the collision.

```lua
--- @param e collideWaterEventData
local function collideWaterCallback(e)
end
event.register(tes3.event.collideWater, collideWaterCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `inWater` (boolean): *Read-only*. 
* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): *Read-only*. Mobile object which collided.
* `reference` ([tes3mobileObject](../../types/tes3mobileObject)): *Read-only*. `mobile`'s reference.

