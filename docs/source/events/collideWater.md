# collideWater

This event is triggered when a mobile object collides with water.

```lua
--- @param e collideWaterEventData
local function collideWaterCallback(e)
end
event.register("collideWater", collideWaterCallback)
```

This event can be filtered based on the **`reference`** event data.

## Event Data

* `reference` ([tes3mobileObject](../../types/tes3mobileObject)): `mobile`'s reference.
* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): Mobile object which collided.
* `inWater` (boolean): 

