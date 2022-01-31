# calcFlySpeed

One of the movement events, **calcFlySpeed** is used when calculating movement speeds when levitating or otherwise flying.

The movement event flow is described below:

- Flying: **calcFlySpeed** -> [calcMoveSpeed](https://mwse.github.io/MWSE/events/calcMoveSpeed)

```lua
--- @param e calcFlySpeedEventData
local function calcFlySpeedCallback(e)
end
event.register(tes3.event.calcFlySpeed, calcFlySpeedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose speed is being calculated.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `speed` (number): The previous speed calculated, starting with the base engine values.
* `type` (number): *Read-only*. The type of movement that was calculated. This is always 5 for this event.

