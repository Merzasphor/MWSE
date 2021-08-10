# calcSwimSpeed

One of the movement events, calcSwimSpeed is used when calculating the movement speed while in water.

```lua
--- @type e event.calcSwimSpeed
local function calcSwimSpeedCallback(e)
end
event.register("calcSwimSpeed", calcSwimSpeedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor whose speed is being calculated.
* `type` (number): The type of movement that was calculated. This is always 3 for this event.
* `speed` (number): The previous speed calculated, starting with the base engine values.

