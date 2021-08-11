# calcRunSpeed

One of the movement events, calcRunSpeed is used when calculating when the player is running, but not swimming or flying.

```lua
--- @type e event.calcRunSpeed
local function calcRunSpeedCallback(e)
end
event.register("calcRunSpeed", calcRunSpeedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor whose speed is being calculated.
* `type` (number): The type of movement that was calculated. This is always 2 for this event.
* `speed` (number): The previous speed calculated, starting with the base engine values.

