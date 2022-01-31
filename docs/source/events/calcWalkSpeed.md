# calcWalkSpeed

One of the movement events, **calcWalkSpeed** is used when calculating the base walk speed. Nearly every other movement speed event starts with this, with the exception of [calcFlySpeed](https://mwse.github.io/MWSE/events/calcFlySpeed).

The movement event flow is described below:

- Walking: **calcWalkSpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Running: **calcWalkSpeed** -> [calcRunSpeed](https://mwse.github.io/MWSE/events/calcRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming: **calcWalkSpeed** -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)
- Swimming (while running): **calcWalkSpeed** -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)

```lua
--- @param e calcWalkSpeedEventData
local function calcWalkSpeedCallback(e)
end
event.register(tes3.event.calcWalkSpeed, calcWalkSpeedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose speed is being calculated.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `speed` (number): The previous speed calculated, starting with the base engine values.
* `type` (number): *Read-only*. The type of movement that was calculated. This is always 1 for this event.

