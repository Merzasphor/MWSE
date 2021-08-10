# collideWater

This event is triggered when a mobile object collides with water.

```lua
--- @type e event.collideWater
local function collideWaterCallback(e)
end
event.register("collideWater", collideWaterCallback)
```

This event can be filtered based on the **`table: 0x00fdf2a8`** event data.

## Event Data

* `inWater` (boolean): 
* `mobile` ([tes3mobileObject](../../types/tes3mobileObject)): Mobile object which collided.

