# calcFlySpeed

One of the movement events, calcFlySpeed is used when calculating movement speeds when levitating or otherwise flying.

```lua
--- @type e event.calcFlySpeed
local function calcFlySpeedCallback(e)
end
event.register("calcFlySpeed", calcFlySpeedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor whose speed is being calculated.
* `type` (number): The type of movement that was calculated. This is always 5 for this event.
* `speed` (number): The previous speed calculated, starting with the base engine values.

