# calcSwimSpeed

One of the movement events, **calcSwimSpeed** is used when calculating the movement speed while in water when running.

The movement event flow is described below:

- Swimming: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcSwimSpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming (while running): [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcSwimSpeed** -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)

```lua
--- @param e calcSwimSpeedEventData
local function calcSwimSpeedCallback(e)
end
event.register(tes3.event.calcSwimSpeed, calcSwimSpeedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose speed is being calculated.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `speed` (number): The previous speed calculated, starting with the base engine values.
* `type` (number): *Read-only*. The type of movement that was calculated. This is always 3 for this event.

