# calcSwimRunSpeed

One of the movement events, calcSwimRunSpeed is used when calculating the movement speed while in water when running.

```lua
--- @param e calcSwimRunSpeedEventData
local function calcSwimRunSpeedCallback(e)
end
event.register("calcSwimRunSpeed", calcSwimRunSpeedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): mobile’s related reference.
* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): The mobile actor whose speed is being calculated.
* `type` (number): The type of movement that was calculated. This is always 4 for this event.
* `speed` (number): The previous speed calculated, starting with the base engine values.

