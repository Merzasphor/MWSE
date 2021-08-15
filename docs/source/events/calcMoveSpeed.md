# calcMoveSpeed

This event is called when an actor’s movement speed is calculated. The event allows modification of this value, to dehardcode actor movement speeds. Invoked after all other movement speed events are finished.

The movement event flow is described below:

- Walking: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> **calcMoveSpeed**
- Running: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcRunSpeed](https://mwse.github.io/MWSE/events/calcRunSpeed) -> **calcMoveSpeed**
- Swimming: [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> **calcMoveSpeed**
- Swimming (while running): [calcWalkSpeed](https://mwse.github.io/MWSE/events/calcWalkSpeed) -> [calcSwimSpeed](https://mwse.github.io/MWSE/events/calcSwimSpeed) -> [calcSwimRunSpeed](https://mwse.github.io/MWSE/events/calcSwimRunSpeed) -> **calcMoveSpeed**
- Flying: [calcFlySpeed](https://mwse.github.io/MWSE/events/calcFlySpeed) -> **calcMoveSpeed**

```lua
--- @param e calcMoveSpeedEventData
local function calcMoveSpeedCallback(e)
end
event.register("calcMoveSpeed", calcMoveSpeedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor)): *Read-only*. The mobile actor whose speed is being calculated.
* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. mobile’s related reference.
* `speed` (number): The previous speed calculated, starting with the base engine values.
* `type` (number): *Read-only*. The type of movement that was calculated. This is always 0 for this event.

## Examples

!!! example "Example: 20% Faster Player Movement"

	```lua
	local function onCalcMoveSpeed(e)
	    if (e.reference == tes3.player) then
	        e.speed = e.speed * 1.2
	    end
	end
	event.register(tes3.event.calcMoveSpeed, onCalcMoveSpeed)

	```

